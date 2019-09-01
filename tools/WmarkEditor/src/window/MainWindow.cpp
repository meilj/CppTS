/*
** Anxiu Li, 2019, BSD (2)
*/

////////////////////////////////////////////////////////////////////////////////

#include "precomp.h"

#include "../view/TextEditor.h"
#include "MainWindow.h"
#include "common/TextDef.h"

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

// MainWindow

MainWindow::MainWindow(int w, int h, const char* t) : Fl_Double_Window(w, h, t), 
                                                      m_textEditor(std::make_shared<TextEditor>(50, 80, 400, 400)), 
	                                                  m_menuBar(std::make_shared<Fl_Menu_Bar>(0, 0, 500, 40))
{
	m_menuBar->add("Load...", 0, &load_cb, &m_cmdFunc_load);
	m_menuBar->add("Save...", 0, &save_cb, &m_cmdFunc_save);
	m_menuBar->add("Replace...", 0, &replace_cb, this);
	
	m_replaceDlg = std::make_shared<Fl_Window>(300, 105, "Replace");
	m_replaceFind = std::make_shared<Fl_Input>(80, 10, 210, 25, "Find:");
	m_replaceFind->align(FL_ALIGN_LEFT);
	m_replaceWith = std::make_shared<Fl_Input>(80, 40, 210, 25, "Replace:");
	m_replaceWith->align(FL_ALIGN_LEFT);
	m_replaceAll = std::make_shared<Fl_Button>(10, 70, 90, 25, "Replace All");
	m_replaceNext = std::make_shared<Fl_Return_Button>(105, 70, 120, 25, "Replace Next");
	m_replaceCancel = std::make_shared<Fl_Button>(230, 70, 60, 25, "Cancel");
	m_replaceDlg->end();
	m_replaceDlg->set_non_modal();
	m_replaceAll->callback((Fl_Callback*)replace_all_cb, this);
	m_replaceNext->callback((Fl_Callback*)replace_next_cb, this);
	m_replaceCancel->callback((Fl_Callback*)replace_cancel_cb, this);
	
	this->resizable(*m_textEditor);
}

MainWindow::~MainWindow() noexcept
{
}

//properties
std::shared_ptr<TextEditor> MainWindow::get_TextEditor() noexcept
{
	return m_textEditor;
}

void MainWindow::show_ReplaceDialog(bool bShow) noexcept
{
	if (bShow)
		m_replaceDlg->show();
	else
		m_replaceDlg->hide();
}

void MainWindow::set_ReplacePara(bool bRepalceAll)
{
	const char *find = m_replaceFind->value();
	const char *replace = m_replaceWith->value();
	if (find[0] == '\0')
	{
		m_replaceDlg->show();
		return;
	}
	m_replaceDlg->hide();

	ReplacePara para;
	para.nPos = -1;
	if(!bRepalceAll)
		para.nPos = m_textEditor->insert_position();
	para.strFind = find;
	para.strReplace = replace;
	if (m_cmdFunc_replace != nullptr && !m_cmdFunc_replace(std::make_any<ReplacePara>(para))) {
		fl_alert("Error in repalce file!");
	}
}

//commands
void MainWindow::set_LoadCommand(CommandFunc&& cf)
{
	m_cmdFunc_load = std::move(cf);
}

void MainWindow::set_SaveCommand(CommandFunc&& cf)
{
	m_cmdFunc_save = std::move(cf);
}

void MainWindow::set_ReplaceCommand(CommandFunc&& cf)
{
	m_cmdFunc_replace = std::move(cf);
}

//callbacks
void MainWindow::load_cb(Fl_Widget*, void* v)
{
	Fl_Native_File_Chooser fc;
	fc.title("Choose file");
	fc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	if (fc.show() == 0) {
		CommandFunc& cmdFunc = *((CommandFunc*)v);
		if (cmdFunc != nullptr && !cmdFunc(std::make_any<std::string>(std::string(fc.filename())))){
			fl_alert("Error in opening file!");
		}
	}
	return;
}

void MainWindow::save_cb(Fl_Widget*, void* v)
{
	Fl_Native_File_Chooser fc;
	fc.title("Save file");
	fc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
	if (fc.show() == 0) {
		CommandFunc& cmdFunc = *((CommandFunc*)v);
		if (cmdFunc != nullptr && !cmdFunc(std::make_any<std::string>(std::string(fc.filename())))) {
			fl_alert("Error in saving file!");
		}
	}
	return;
}

void MainWindow::replace_cb(Fl_Widget*, void* v)
{
	MainWindow* e = (MainWindow*)v;
	e->show_ReplaceDialog(true);
}

void MainWindow::replace_all_cb(Fl_Widget*, void* v)
{
	MainWindow* e = (MainWindow*)v;
	e->set_ReplacePara(true);
	/*const char *find = m_replaceFind->value();
	const char *replace = m_replaceWith->value();
	if (find[0] == '\0')
	{
		m_replaceDlg->show();
	}
	 m_replaceDlg->hide();
	
	ReplacePara para;
	para.pos = -1;
	para.find = find;
	para.replace = replace;
	CommandFunc& cmdFunc = *((CommandFunc*)v);
	if (cmdFunc != nullptr && !cmdFunc(std::make_any<ReplacePara>(para))) {
		fl_alert("Error in repalce file!");
	}*/
}

void MainWindow::replace_next_cb(Fl_Widget*, void* v)
{
	MainWindow* e = (MainWindow*)v;
	e->set_ReplacePara(false);
	/*const char *find = m_replaceFind->value();
	const char *replace = m_replaceWith->value();
	if (find[0] == '\0')
	{
		m_replaceDlg->show();
	}
	m_replaceDlg->hide();
	int pos = m_textEditor->insert_position();

	ReplacePara para;
	para.pos = pos;
	para.find = find;
	para.replace = replace;
	CommandFunc& cmdFunc = *((CommandFunc*)v);
	if (cmdFunc != nullptr && !cmdFunc(std::make_any<ReplacePara>(para))) {
		fl_alert("Error in repalce file!");
	}*/
}

void MainWindow::replace_cancel_cb(Fl_Widget*, void* v)
{
	MainWindow* e = (MainWindow*)v;
	e->show_ReplaceDialog(false);
}

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////

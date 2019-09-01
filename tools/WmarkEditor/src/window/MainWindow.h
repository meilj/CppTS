/*
** Anxiu Li, 2019, BSD (2)
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

// MainWindow

class MainWindow : public Fl_Double_Window
{
public:
	MainWindow(int w, int h, const char* t);
	MainWindow(const MainWindow&) = delete;
	MainWindow& operator=(const MainWindow&) = delete;
	~MainWindow() noexcept;

//properties
	std::shared_ptr<TextEditor> get_TextEditor() noexcept;
	void show_ReplaceDialog(bool bShow) noexcept;
	void set_ReplacePara(bool bReplaceAll);

//commands
	void set_LoadCommand(CommandFunc&& cf);
	void set_SaveCommand(CommandFunc&& cf);
	void set_ReplaceCommand(CommandFunc&& cf);

//notifications
	PropertyNotification get_Notification();

private:
//callbacks
	static void load_cb(Fl_Widget*, void* v);
	static void save_cb(Fl_Widget*, void* v);
	static void replace_cb(Fl_Widget*, void* v);
	static void replace_all_cb(Fl_Widget*, void* v);
	static void replace_next_cb(Fl_Widget*, void* v);
	static void replace_cancel_cb(Fl_Widget*, void*v);
	

private:
//commands
	CommandFunc m_cmdFunc_load;
	CommandFunc m_cmdFunc_save;
	CommandFunc m_cmdFunc_replace;

//UI
	std::shared_ptr<TextEditor> m_textEditor;
	std::shared_ptr<Fl_Menu_Bar> m_menuBar;

	std::shared_ptr<Fl_Window> m_replaceDlg;
	std::shared_ptr<Fl_Input> m_replaceFind;
	std::shared_ptr<Fl_Input> m_replaceWith;
	std::shared_ptr<Fl_Button> m_replaceAll;
	std::shared_ptr<Fl_Return_Button> m_replaceNext;
	std::shared_ptr<Fl_Button> m_replaceCancel;
};

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////


/*
** Xin YUAN, 2019, BSD (2)
*/

////////////////////////////////////////////////////////////////////////////////

#include "precomp.h"

#include "TextModel.h"

#include "../common/TextDef.h"

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

// TextModel

TextModel::TextModel() : m_spBuffer(std::make_shared<Fl_Text_Buffer>())
{
}
TextModel::~TextModel() noexcept
{
}

//properties
std::shared_ptr<Fl_Text_Buffer> TextModel::get_TextBuf() noexcept
{
	return m_spBuffer;
}

//methods
bool TextModel::Load(const std::string& str)
{
	if (m_spBuffer->loadfile(str.c_str()) == 0) {
		Fire(PROPID_TEXT);
		return true;
	}
	return false;
}

bool TextModel::Save(const std::string& str)
{
	if (m_spBuffer->savefile(str.c_str()) == 0) {
		return true;
	}
	return false;
}

bool TextModel::Replace(const ReplacePara& para)
{
	bool bReplaceAll = para.nPos == -1 ? true : false;
	bool bSuc = false;
	for (int found = 1; found;) {
		int pos = para.nPos;
		found = m_spBuffer->search_forward(pos, para.strFind.c_str(), &pos);

		if (found) {
			// Found a match; update the position and replace text...
			m_spBuffer->select(pos, pos + (int)strlen(para.strFind.c_str()));
			m_spBuffer->remove_selection();
			m_spBuffer->insert(pos, para.strReplace.c_str());
			bSuc = true;
		}
		if (!bReplaceAll)
			break;
	}
	if(bSuc)
		Fire(PROPID_TEXT);
	return true;
}
////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////

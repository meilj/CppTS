﻿/*
** Xin YUAN, 2019, BSD (2)
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __TK_TEXT_ACTION_H__
#define __TK_TEXT_ACTION_H__
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

// WmarkParserTkTextAction

class WmarkParserTkTextAction : public IRdParserAction
{
public:
	WmarkParserTkTextAction() noexcept;
	~WmarkParserTkTextAction() noexcept;

// IRdParserAction methods
	virtual void SetParameter(const std::any& param);
	virtual bool DoAction(std::vector<std::string>& vecError);

private:
	RdParserActionMetaData* m_pData;
};

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

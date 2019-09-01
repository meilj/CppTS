﻿/*
** Xin YUAN, 2019, BSD (2)
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __TK_ACTION_H__
#define __TK_ACTION_H__
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

// WmarkScannerTkAction

class WmarkScannerTkAction : public IRdScannerAction
{
public:
	WmarkScannerTkAction() throw();
	~WmarkScannerTkAction() throw();

// IRdScannerAction
	virtual bool Scan(std::istream& stm, RdActionStack& stk, RdToken& token);
};

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

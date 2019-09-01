﻿/*
** Xin YUAN, 2019, BSD (2)
*/

////////////////////////////////////////////////////////////////////////////////
#ifndef __TEXT_DEF_H__
#define __TEXT_DEF_H__
////////////////////////////////////////////////////////////////////////////////

//property IDs

enum {
	PROPID_TEXT = 2
};

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

struct ReplacePara
{
	int nPos;
	std::string strFind;
	std::string strReplace;
};

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////
#endif
////////////////////////////////////////////////////////////////////////////////

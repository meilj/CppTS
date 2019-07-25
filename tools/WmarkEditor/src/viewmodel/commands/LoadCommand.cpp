﻿/*
** Xin YUAN, 2019, BSD (2)
*/

////////////////////////////////////////////////////////////////////////////////

#include "precomp.h"

#include "../../model/TextModel.h"
#include "../TextViewModel.h"

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
////////////////////////////////////////////////////////////////////////////////

// TextViewModel

CommandFunc TextViewModel::get_LoadCommand()
{
	return [this](std::any&& param)->bool
			{
				return this->m_spModel->Load(std::any_cast<std::string>(param));
			};
}

////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////

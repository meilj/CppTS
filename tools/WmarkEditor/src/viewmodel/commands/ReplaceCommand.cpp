/*
** Mei Lijuan, 2019
*/

////////////////////////////////////////////////////////////////////////////////

#include "precomp.h"

#include "../../model/TextModel.h"
#include "../TextViewModel.h"

////////////////////////////////////////////////////////////////////////////////
namespace CSL {
	////////////////////////////////////////////////////////////////////////////////

	// TextViewModel

	CommandFunc TextViewModel::get_ReplaceCommand()
	{
		return [this](std::any&& param)->bool
		{
			return this->m_spModel->Replace(std::any_cast<ReplacePara>(param));
		};
	}

	////////////////////////////////////////////////////////////////////////////////
}
////////////////////////////////////////////////////////////////////////////////

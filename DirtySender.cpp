#include "DirtySender.h"

#include <algorithm>
#include <vector_erase_move_lastelement/vector_swap_erase.h>

void DirtySender::AddDirtyReveiver(DirtyReceiver* reciever)
{
	this->mDirtyReceivers.push_back(reciever);
}

void DirtySender::RemoveDirtyReveiver(DirtyReceiver* reciever)
{
	std::vector<DirtyReceiver>::iterator targetIter = std::find(this->mDirtyReceivers.begin(), this->mDirtyReceivers.end(), reciever);
	std::vector_swap_erase(this->mDirtyReceivers, targetIter);
}

void DirtySender::SendDirty()
{
	for (auto& receiver : this->mDirtyReceivers)
	{
		receiver->mIsDirty = true;
	}
}

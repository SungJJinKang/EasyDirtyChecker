#include "DirtySender.h"

#include <algorithm>
#include <vector_erase_move_lastelement/vector_swap_erase.h>

void DirtySender::AddDirtyReceiver(DirtyReceiver* reciever)
{
	this->mDirtyReceivers.push_back(reciever);
}

void DirtySender::RemoveDirtyReceiver(DirtyReceiver* reciever)
{
	std::vector<DirtyReceiver*>::iterator targetIter = std::find(this->mDirtyReceivers.begin(), this->mDirtyReceivers.end(), reciever);
	std::vector_swap_erase(this->mDirtyReceivers, targetIter);
}

void DirtySender::NotifyDirty()
{
	for (auto& receiver : this->mDirtyReceivers)
	{
		receiver->SetDirty();
	}
}

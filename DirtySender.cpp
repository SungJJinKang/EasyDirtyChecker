#include "DirtySender.h"

#include <cassert>
#include <algorithm>

#include "DirtyReceiver.h"

//#include <vector_erase_move_lastelement/vector_swap_erase.h> //https://github.com/SungJJinKang/vector_swap_erase

void DirtySender::AddDirtyReceiver(DirtyReceiver* receiver)
{
	assert(receiver != nullptr);
	receiver->ClearDirtySender();
	this->mDirtyReceivers.push_back(receiver);
	receiver->mDirtySender = this;
}

void DirtySender::RemoveDirtyReceiver(DirtyReceiver* receiver)
{
	assert(receiver != nullptr);

	if (receiver->mDirtySender == this)
	{
		receiver->mDirtySender = nullptr;
	}

	std::vector<DirtyReceiver*>::iterator targetReceiverIter = std::find(this->mDirtyReceivers.begin(), this->mDirtyReceivers.end(), receiver);
	if (targetReceiverIter != this->mDirtyReceivers.end())
	{
		this->mDirtyReceivers.erase(targetReceiverIter);
		//std::vector_swap_erase(this->mDirtyReceivers, targetIter);
	}
}

DirtySender::~DirtySender()
{
	auto diretyReceivers = mDirtyReceivers;
	for (auto dirtyReceiver : diretyReceivers)
	{
		this->RemoveDirtyReceiver(dirtyReceiver);
	}
}

void DirtySender::NotifyDirty()
{
	for (auto receiver : this->mDirtyReceivers)
	{
		receiver->SetDirty();
	}
}

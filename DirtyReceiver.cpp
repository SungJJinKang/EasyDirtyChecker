#include "DirtyReceiver.h"

#include <cassert>
#include "DirtySender.h"
#include <vector_erase_move_lastelement/vector_swap_erase.h>



DirtyReceiver::DirtyReceiver(DirtySender* sender)
{
	this->SetDirtySender(sender);
}

DirtyReceiver::~DirtyReceiver()
{
	this->mSender->RemoveDirtyReceiver(this);

	for (auto& localDirty : this->mLocalIsDirtys)
	{
		localDirty->mOwnerDirtyReceiver = nullptr;
	}
}

void DirtyReceiver::SetDirtySender(DirtySender* sender)
{
	if (this->mSender != nullptr)
	{
		this->mSender->RemoveDirtyReceiver(this);
	}

	this->mSender = sender;
	
	if (this->mSender != nullptr)
	{
		this->mSender->AddDirtyReceiver(this);
	}
}

void DirtyReceiver::SetDirty()
{
	this->mMainIsDirty = true;
	for (auto& localDirty : this->mLocalIsDirtys)
	{
		localDirty->bmIsDirty = true;
	}
}

void DirtyReceiver::AddLocalIsDirtyVariable(LocalDirty* localIsDirty)
{
	assert(this->mSender != nullptr);
	assert(localIsDirty != nullptr);
	assert(localIsDirty->mOwnerDirtyReceiver == nullptr);

	localIsDirty->mOwnerDirtyReceiver = this;
	this->mLocalIsDirtys.push_back(localIsDirty);
}

void DirtyReceiver::RemoveLocalIsDirtyVariable(LocalDirty* localIsDirty)
{
	assert(this->mSender != nullptr);
	assert(localIsDirty != nullptr);

	localIsDirty->mOwnerDirtyReceiver = nullptr;
	std::vector<LocalDirty*>::iterator targetIter = std::find(this->mLocalIsDirtys.begin(), this->mLocalIsDirtys.end(), localIsDirty);
	std::vector_swap_erase(this->mLocalIsDirtys, targetIter);

	
}

void DirtyReceiver::CleanDirty(bool clearLocalIsDirty)
{
	assert(this->mSender != nullptr);

	this->mMainIsDirty = false;
	
	if (clearLocalIsDirty == true)
	{
		for (auto& localDirty : this->mLocalIsDirtys)
		{
			localDirty->bmIsDirty = false;
		}
	}
}

bool DirtyReceiver::GetIsDirtyMain(bool clearDirty)
{
	assert(this->mSender != nullptr);

	bool currentDirtyVariable = this->mMainIsDirty;

	if (clearDirty == true)
	{
		this->CleanDirty(false);
	}

	return currentDirtyVariable;
}

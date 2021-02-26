#include "DirtyReceiver.h"

#include "DirtySender.h"

DirtyReceiver::DirtyReceiver(DirtySender& sender)
	: mSender{ sender }, mIsDirty{ false }
{

}

DirtyReceiver::~DirtyReceiver()
{
	this->mSender.RemoveDirtyReveiver(this);
}

void DirtyReceiver::CleanDirty()
{
	this->mIsDirty = false;
}

bool DirtyReceiver::GetIsDirty() const
{
	return this->mIsDirty;
}

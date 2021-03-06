#include "DirtyReceiver.h"

#include <cassert>


DirtyReceiver::DirtyReceiver()
	: bmIsDirty{ true }
{

}

DirtyReceiver::DirtyReceiver(bool initialDirty)
	: bmIsDirty{ initialDirty }
{

}

DirtyReceiver::DirtyReceiver(const DirtyReceiver & dirtyReceiver)
	: bmIsDirty{ dirtyReceiver.bmIsDirty }
{
	if (dirtyReceiver.mDirtySender != nullptr)
	{
		dirtyReceiver.mDirtySender->AddDirtyReceiver(this);
	}
}

DirtyReceiver::DirtyReceiver(DirtyReceiver && dirtyReceiver) noexcept
	: bmIsDirty{ dirtyReceiver.bmIsDirty }
{
	if (dirtyReceiver.mDirtySender != nullptr)
	{
		dirtyReceiver.mDirtySender->AddDirtyReceiver(this);
		dirtyReceiver.mDirtySender->RemoveDirtyReceiver(&dirtyReceiver);
	}
}

DirtyReceiver& DirtyReceiver::operator=(const DirtyReceiver& dirtyReceiver)
{
	this->bmIsDirty = dirtyReceiver.bmIsDirty;
	if (dirtyReceiver.mDirtySender != nullptr)
	{
		dirtyReceiver.mDirtySender->AddDirtyReceiver(this);
	}

	return *this;
}

DirtyReceiver& DirtyReceiver::operator=(DirtyReceiver&& dirtyReceiver) noexcept
{
	this->bmIsDirty = dirtyReceiver.bmIsDirty;
	if (dirtyReceiver.mDirtySender != nullptr)
	{
		dirtyReceiver.mDirtySender->AddDirtyReceiver(this);
		dirtyReceiver.mDirtySender->RemoveDirtyReceiver(&dirtyReceiver);
	}

	return *this;
}

DirtyReceiver::~DirtyReceiver()
{
	this->ClearDirtySender();
}


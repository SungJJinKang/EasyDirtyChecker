#include "DirtyReceiver.h"

#include <cassert>

#include "DirtySender.h"
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

DirtyReceiver& DirtyReceiver::operator=(bool isDirty)
{
	this->bmIsDirty = isDirty;
	return *this;
}

void DirtyReceiver::SetDirty(bool isDirty /*= true*/)
{
	this->bmIsDirty = isDirty;
}


void DirtyReceiver::ClearDirtySender()
{
	if (this->mDirtySender != nullptr)
	{
		this->mDirtySender->RemoveDirtyReceiver(this);
	}
}

bool DirtyReceiver::GetIsDirty(bool clearDirty)
{
	if (clearDirty == true)
	{
		bool currentDirtyVariable = this->bmIsDirty;
		this->bmIsDirty = false;
		return currentDirtyVariable;
	}
	else
	{
		return this->bmIsDirty;
	}
}

#include "LocalDirty.h"

#include "DirtyReceiver.h"
LocalDirty::LocalDirty()
	: bmIsDirty{ true }
{

}

LocalDirty::LocalDirty(bool initialDirty)
	: bmIsDirty{ initialDirty }
{

}

LocalDirty::~LocalDirty()
{
	if (this->mOwnerDirtyReceiver != nullptr)
	{
		this->mOwnerDirtyReceiver->RemoveLocalIsDirtyVariable(this);
	}
}

LocalDirty& LocalDirty::operator=(bool isDirty)
{
	this->bmIsDirty = isDirty;
	return *this;
}

void LocalDirty::SetDirty(bool isDirty /*= true*/)
{
	this->bmIsDirty = isDirty;
}

bool LocalDirty::GetIsDirty(bool clearDirty)
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

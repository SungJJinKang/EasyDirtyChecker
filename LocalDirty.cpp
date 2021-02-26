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

bool LocalDirty::GetIsDirty(bool clearDirty)
{
	bool currentDirtyVariable = this->bmIsDirty;

	if (clearDirty == true)
	{
		this->bmIsDirty = false;
	}

	return currentDirtyVariable;
}

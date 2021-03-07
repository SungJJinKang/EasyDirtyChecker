#pragma once
#include "DirtySender.h"

class DirtySender;
class DirtyReceiver
{
	friend class DirtySender;
private:

	DirtySender* mDirtySender{ nullptr };
	bool bmIsDirty;

public:

	DirtyReceiver();
	DirtyReceiver(bool initialDirty);
	DirtyReceiver(const DirtyReceiver & dirtyReceiver) ;
	DirtyReceiver(DirtyReceiver && dirtyReceiver) noexcept ;
	DirtyReceiver& operator=(const DirtyReceiver& dirtyReceiver) ;
	DirtyReceiver& operator=(DirtyReceiver&& dirtyReceiver) noexcept;
	~DirtyReceiver();

	constexpr operator bool()
	{
		return this->bmIsDirty;
	}

	constexpr DirtyReceiver& operator=(bool isDirty)
	{
		this->bmIsDirty = isDirty;
		return *this;
	}

	constexpr void SetDirty(bool isDirty = true)
	{
		this->bmIsDirty = isDirty;
	}


	constexpr void ClearDirtySender()
	{
		if (this->mDirtySender != nullptr)
		{
			this->mDirtySender->RemoveDirtyReceiver(this);
		}
	}

	/// <summary>
	/// Get IsDirty
	/// </summary>
	/// <param name="clearDirty">Do Clear Dirty Variable???</param>
	/// <returns></returns>
	[[nodiscard]] constexpr bool GetIsDirty(bool clearDirty) // don't put default value to clearDirty argument
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

};


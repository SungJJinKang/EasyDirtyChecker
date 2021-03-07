#pragma once

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

	DirtyReceiver& operator=(bool isDirty);
	void SetDirty(bool isDirty = true);


	void ClearDirtySender();

	/// <summary>
	/// Get IsDirty
	/// </summary>
	/// <param name="clearDirty">Do Clear Dirty Variable???</param>
	/// <returns></returns>
	[[nodiscard]] bool GetIsDirty(bool clearDirty); // don't put default value to clearDirty argument

};


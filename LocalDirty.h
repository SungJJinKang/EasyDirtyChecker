#pragma once

class DirtyReceiver;
class LocalDirty
{
	friend class DirtyReceiver;
private:

	DirtyReceiver* mOwnerDirtyReceiver{ nullptr };
	bool bmIsDirty;

public:

	LocalDirty();
	LocalDirty(bool initialDirty);
	LocalDirty(const LocalDirty&) = default;
	LocalDirty(LocalDirty&&) noexcept = default;
	LocalDirty& operator=(const LocalDirty&) = default;
	LocalDirty& operator=(LocalDirty&&) noexcept = default;
	~LocalDirty();

	LocalDirty& operator=(bool isDirty);
	void SetDirty(bool isDirty = true);

	/// <summary>
	/// Get IsDirty
	/// </summary>
	/// <param name="clearDirty">Do Clear Dirty Variable???</param>
	/// <returns></returns>
	[[nodiscard]] bool GetIsDirty(bool clearDirty); // don't put default value to clearDirty argument

};


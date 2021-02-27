#pragma once
#include <vector>
#include "LocalDirty.h"

class DirtySender;
class DirtyReceiver
{
	friend class DirtySender;

private:
	DirtySender* mSender{ nullptr };
	/// <summary>
	/// This dirty is set true only by Sender,
	/// and is set false only by CleanDirty Function
	/// 
	/// I don't recommend use mMainIsDirty variable, Use your own LocalIsDirty Variable and Add to this receiver 
	/// 
	/// For a frame, many components will get IsDirty value, then it will clear dirty varialbe.
	/// Then other components may will see false Dirty value. this makes bugs.....
	/// </summary>
	bool mMainIsDirty{ true };
	/// <summary>
	/// If you want to receiver dirty value to variable what you want, add that bool variable to this variable
	/// </summary>
	std::vector<LocalDirty*> mLocalIsDirtys{};
	void SetDirty();

public:

	DirtyReceiver() {}
	DirtyReceiver(DirtySender* sender);
	DirtyReceiver(const DirtyReceiver&) = default;
	DirtyReceiver(DirtyReceiver&& dirtyReceiver) noexcept;
	DirtyReceiver& operator=(const DirtyReceiver&) = default;
	DirtyReceiver& operator=(DirtyReceiver&& dirtyReceiver) noexcept;
	
	//Important, when Receiver is destructed, remove this obejct from sender's Reciever list(vector)
	~DirtyReceiver();

	void SetDirtySender(DirtySender* sender);

	/// <summary>
	/// Make your own IsDirtyVariable receiver Dirty value
	/// you should reset dirty variable yourself!!!!!!!!!!!!!!!!!!!
	/// 
	/// Recommnet Use This than mMainIsDirty
	/// </summary>
	/// <param name="localDirtyVariable"></param>
	void AddLocalIsDirtyVariable(LocalDirty* localIsDirty);
	void RemoveLocalIsDirtyVariable(LocalDirty* localIsDirty);

	void CleanDirty(bool clearLocalIsDirty);
	
	/// <summary>
	/// Get IsDirty
	/// </summary>
	/// <param name="clearDirty">Do Clear Dirty Variable???</param>
	/// <returns></returns>
	[[nodiscard]] bool GetIsDirtyMain(bool clearDirty); // don't put default value to clearDirty argument

	
};


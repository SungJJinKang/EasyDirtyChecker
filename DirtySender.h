#pragma once

#include <vector>
#include "DirtyReceiver.h"

class DirtySender
{
	friend class DirtyReceiver;
private:
	std::vector<DirtyReceiver*> mDirtyReceivers{};
	//this class doens't have dirty value itself, this clacss just send dirty to Reveivers

	void AddDirtyReveiver(DirtyReceiver* reciever);
	/// <summary>
	/// TODO : use std::vector_swap_erase
	/// </summary>
	/// <param name="reciever"></param>
	void RemoveDirtyReveiver(DirtyReceiver* reciever);

public:
	
	DirtySender() = default;
	DirtySender(const DirtySender&) = default;
	DirtySender(DirtySender&&) noexcept = default;
	DirtySender& operator=(const DirtySender&) = default;
	DirtySender& operator=(DirtySender&&) noexcept = default;
	~DirtySender() = default;

	/// <summary>
	/// Set Receiver's Dirty true
	/// </summary>
	void SendDirty();
};


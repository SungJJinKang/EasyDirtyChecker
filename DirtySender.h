#pragma once

#include <vector>
#include "DirtyReceiver.h"

class DirtySender
{
private:
	std::vector<DirtyReceiver> mDirtyReceivers{};
	//this class doens't have dirty value itself, this clacss just send dirty to Reveivers

public:
	void AddDirtyReveiver(const DirtyReceiver& reciever);
	/// <summary>
	/// TODO : use std::vector_swap_erase
	/// </summary>
	/// <param name="reciever"></param>
	void RemoveDirtyReveiver(const DirtyReceiver& reciever);

	/// <summary>
	/// Set Receiver's Dirty true
	/// </summary>
	void SendDirty();
};


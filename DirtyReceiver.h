#pragma once

class DirtySender;
class DirtyReceiver
{
	friend class DirtySender;

private:
	const DirtySender& mSender;
	/// <summary>
	/// This dirty is set true only by Sender,
	/// and is set false only by CleanDirty Function
	/// </summary>
	bool mIsDirty;

public:

	DirtyReceiver(const DirtySender& sender);
	
	//Important, when Receiver is destructed, remove this obejct from sender's Reciever list(vector)
	~DirtyReceiver();

	void CleanDirty();
};


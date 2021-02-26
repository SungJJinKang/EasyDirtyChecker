#pragma once

class DirtySender;
class DirtyReceiver
{
	friend class DirtySender;

private:
	DirtySender& mSender;
	/// <summary>
	/// This dirty is set true only by Sender,
	/// and is set false only by CleanDirty Function
	/// </summary>
	bool mIsDirty;

public:

	DirtyReceiver(DirtySender& sender);
	DirtyReceiver(const DirtyReceiver&) = default;
	DirtyReceiver(DirtyReceiver&&) noexcept = default;
	DirtyReceiver& operator=(const DirtyReceiver&) = default;
	DirtyReceiver& operator=(DirtyReceiver&&) noexcept = default;
	
	//Important, when Receiver is destructed, remove this obejct from sender's Reciever list(vector)
	~DirtyReceiver();

	void CleanDirty();
	bool GetIsDirty() const;
};


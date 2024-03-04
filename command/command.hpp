#include <iostream>

// ============ Receiver ============
class TV
{
public:
	TV(bool isPowered = false);
	~TV() = default;

	// commands (from invoker) that the TV responds to
	void powerOn();
	void powerOff();
	void volumeUp();
	void volumeDown();
	void channelUp();
	void channelDown();

	inline void setIsPowered(bool isPowered);
	inline bool getIsPowered() const;

private:
	bool isPowered;
};

// ============ AbstractCommand ============
class TVCommand 
{
public:
	virtual ~TVCommand() = default;
	virtual void execute() = 0;
};

class PowerOn : public TVCommand
{
public:
	PowerOn(TV * tv = nullptr);
	~PowerOn() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class PowerOff : public TVCommand
{
public:
	PowerOff(TV * tv = nullptr);
	~PowerOff() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class VolumeUp : public TVCommand
{
public:
	VolumeUp(TV * tv = nullptr);
	~VolumeUp() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class VolumeDown : public TVCommand
{
public:
	VolumeDown(TV * tv = nullptr);
	~VolumeDown() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class ChannelUp : public TVCommand
{
public:
	ChannelUp(TV * tv = nullptr);
	~ChannelUp() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

class ChannelDown : public TVCommand
{
public:
	ChannelDown(TV * tv = nullptr);
	~ChannelDown() = default;

	virtual void execute() override;

	inline void setTV();
	inline TV * getTV();

protected:
	TV * tv;
};

// ============ Invoker ============
class TVRemote
{
public:
	TVRemote(TVCommand* tvCommand = nullptr);
	~TVRemote() = default;

	TVCommand * getTVCommand() const;
	void setCommand(TVCommand * tvCommand);

	void command() const;

	inline void setTVCommand(TVCommand* tvCommand);
	inline TVCommand * getTVCommand();

protected:
	TVCommand * tvCommand;
};

#include "command.inl"
#include <iostream>

// ============ Receiver ============
class TV
{
public:
	TV();
	~TV();

	// commands (from invoker) that the TV responds to
	void powerOn();
	void powerOff();
	void volumeUp();
	void volumeDown();
	void channelUp();
	void channelDown();
};

// ============ AbstractCommand ============
class TVCommand 
{
public:
	virtual ~TVCommand();
	virtual void execute() = 0;
};

class PowerOn : public TVCommand
{
public:
	PowerOn(TV * tv = nullptr);
	~PowerOn();

	virtual void execute() override;

	void setTV();
	TV * getTV();

protected:
	TV * tv;
};

class PowerOff : public TVCommand
{
public:
	PowerOff(TV * tv = nullptr);
	~PowerOff();

	virtual void execute() override;

	void setTV();
	TV * getTV();

protected:
	TV * tv;
};

class VolumeUp : public TVCommand
{
public:
	VolumeUp(TV * tv = nullptr);
	~VolumeUp();

	virtual void execute() override;

	void setTV();
	TV * getTV();

protected:
	TV * tv;
};

class VolumeDown : public TVCommand
{
public:
	VolumeDown(TV * tv = nullptr);
	~VolumeDown();

	virtual void execute() override;

	void setTV();
	TV * getTV();

protected:
	TV * tv;
};

class ChannelUp : public TVCommand
{
public:
	ChannelUp(TV * tv = nullptr);
	~ChannelUp();

	virtual void execute() override;

	void setTV();
	TV * getTV();

protected:
	TV * tv;
};

class ChannelDown : public TVCommand
{
public:
	ChannelDown(TV * tv = nullptr);
	~ChannelDown();

	virtual void execute() override;

	void setTV();
	TV * getTV();

protected:
	TV * tv;
};

// ============ Invoker ============
class TVRemote
{
public:
	TVRemote();
	~TVRemote();

	TVCommand * getTVCommand() const;
	void setCommand(TVCommand * tvCommand);

	void command() const;

	void setTVCommand(TVCommand* tvCommand);
	TVCommand * getTVCommand();

protected:
	TVCommand * tvCommand;
};
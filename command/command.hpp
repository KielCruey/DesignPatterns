#include <iostream>

// ============ AbstractCommand ============
class TVCommand 
{
public:
	virtual ~TVCommand();
	virtual void execute() = 0;
};

class VolumeUp : public TVCommand
{
public:
	VolumeUp();
	~VolumeUp();

	virtual void execute() override;
};

class VolumeDown : public TVCommand
{
public:
	VolumeDown();
	~VolumeDown();

	virtual void execute() override;
};

class ChannelUp : public TVCommand
{
public:
	ChannelUp();
	~ChannelUp();

	virtual void execute() override;
};

class ChannelDown : public TVCommand
{
public:
	ChannelDown();
	~ChannelDown();

	virtual void execute() override;
};

// ============ Receiver ============
class TV
{
public:
	TV();
	~TV();

	void powerOn();
	void powerOff();
};

// ============ Invoker ============
class TVRemote
{
public:
	TVRemote();
	~TVRemote();

	TVCommand * getTVCommand() const;
	void setCommand(TVCommand * tvCommand);

	void command();

private:
	TVCommand * tvCommand;
};
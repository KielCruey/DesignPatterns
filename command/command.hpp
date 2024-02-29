#include <iostream>

// ============ Receiver ============
class TV
{
public:
	TV();
	~TV();

	void powerOn();
	void powerOff();
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
	PowerOn();
	~PowerOn();

	virtual void execute() override;

protected:
	TV * tv;
};

class PowerOff : public TVCommand
{
public:
	PowerOff();
	~PowerOff();

	virtual void execute() override;

protected:
	TV * tv;
};

class VolumeUp : public TVCommand
{
public:
	VolumeUp();
	~VolumeUp();

	virtual void execute() override;

protected:
	TV * tv;
};

class VolumeDown : public TVCommand
{
public:
	VolumeDown();
	~VolumeDown();

	virtual void execute() override;

protected:
	TV * tv;
};

class ChannelUp : public TVCommand
{
public:
	ChannelUp();
	~ChannelUp();

	virtual void execute() override;

protected:
	TV * tv;
};

class ChannelDown : public TVCommand
{
public:
	ChannelDown();
	~ChannelDown();

	virtual void execute() override;

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

	void command();

private:
	TVCommand * tvCommand;
};
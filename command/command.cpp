#include "command.hpp"

// ============ Static Functions ============
static void printToConsole(std::string string) {
	std::cout << string << std::endl;
}

// ============ TV ============
TV::TV(bool isPowered) :
	isPowered(isPowered)
{ }

void TV::powerOn() {
	if (getIsPowered())	{
		printToConsole("TV is ALREADY powered on!");
	}
	else {
		setIsPowered(true);
		printToConsole("TV is powered on!");
	}
}

void TV::powerOff() {
	if (!getIsPowered()) {
		printToConsole("TV is already off!");
	}
	else {
		setIsPowered(false);
		printToConsole("TV is powered off!");
	}
}

void TV::volumeUp() {
	if (getIsPowered()) printToConsole("TV volumed up!");
	else			    printToConsole("TV not powered -- can't increase volume!");
}

void TV::volumeDown() {
	if (getIsPowered()) printToConsole("TV volumed down!");
	else			    printToConsole("TV not powered -- can't decrease volume!");
}

void TV::channelUp() {
	if (getIsPowered()) printToConsole("TV channeled up!");
	else			    printToConsole("TV not powered -- can't increase the channel!");
}

void TV::channelDown() {
	if (getIsPowered()) printToConsole("TV channeled down!");
	else			    printToConsole("TV not powered -- can't decrease the channel!");
}

void TV::setIsPowered(bool isPowered) {
	this->isPowered = isPowered;
}

bool TV::getIsPowered() const {
	return this->isPowered;
}

// ============ PowerOn ============
PowerOn::PowerOn(TV * tv) :
	tv(tv)
{ }

void PowerOn::execute() {
	getTV()->powerOn();
}

void PowerOn::setTV() {
	this->tv = tv;
}

TV * PowerOn::getTV() {
	return this->tv;
}

// ============ PowerOff ============
PowerOff::PowerOff(TV * tv) :
	tv(tv)
{ }

void PowerOff::execute() {
	getTV()->powerOff();
}

void PowerOff::setTV() {
	this->tv = tv;
}

TV * PowerOff::getTV() {
	return this->tv;
}

// ============ VolumeUp ============
VolumeUp::VolumeUp(TV * tv) :
	tv(tv)
{ }

void VolumeUp::execute() {
	getTV()->volumeUp();
}

void VolumeUp::setTV() {
	this->tv = tv;
}

TV * VolumeUp::getTV() {
	return this->tv;
}

// ============ VolumeDown ============
VolumeDown::VolumeDown(TV * tv) :
	tv(tv)
{ }

void VolumeDown::execute() {
	getTV()->volumeDown();
}

void VolumeDown::setTV() {
	this->tv = tv;
}

TV * VolumeDown::getTV() {
	return this->tv;
}

// ============ ChannelUp ============
ChannelUp::ChannelUp(TV * tv) :
	tv(tv)
{ }

void ChannelUp::execute() {
	getTV()->channelUp();
}

void ChannelUp::setTV() {
	this->tv = tv;
}

TV * ChannelUp::getTV() {
	return this->tv;
}

// ============ ChannelDown ============
ChannelDown::ChannelDown(TV * tv) :
	tv(tv)
{ }

void ChannelDown::execute() {
	getTV()->channelDown();
}

void ChannelDown::setTV() {
	this->tv = tv;
}

TV * ChannelDown::getTV() {
	return this->tv;
}

// ============ Invoker ============
TVRemote::TVRemote(TVCommand* tvCommand) :
	tvCommand(tvCommand)
{ }

TVCommand* TVRemote::getTVCommand() const {
	return this->tvCommand;
}

void TVRemote::setCommand(TVCommand* tvCommand) {
	this->tvCommand = tvCommand;
}

void TVRemote::command() const {
	getTVCommand()->execute();
}

void TVRemote::setTVCommand(TVCommand* tvCommand) {
	this->tvCommand = tvCommand;
}

TVCommand * TVRemote::getTVCommand() {
	return this->tvCommand;
}

// ============ Client Code ============
static void tvCommand(TVRemote * tvRemote, TVCommand * tvCommand) {
	tvRemote->setCommand(tvCommand);
	tvRemote->command();
}
// ============ Main ============
int main() {
	TV * tv = new TV(); // receiver
	TVRemote * tvRemote = new TVRemote(); // invoker

	// execute
	tvCommand(tvRemote, new PowerOn(tv));
	tvCommand(tvRemote, new VolumeUp(tv));
	tvCommand(tvRemote, new VolumeDown(tv));
	tvCommand(tvRemote, new ChannelUp(tv));
	tvCommand(tvRemote, new ChannelDown(tv));
	tvCommand(tvRemote, new PowerOff(tv));

	return 0;
}
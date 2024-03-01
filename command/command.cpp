#include "command.hpp"

// ============ Static Functions ============
static void printToConsole(std::string string) {
	std::cout << string << std::endl;
}

// ============ TV ============
TV::TV() {

}

void TV::powerOn() {
	printToConsole("TV is powered on!");
}

void TV::powerOff() {
	printToConsole("TV is powered off!");
}

void TV::volumeUp() {
	printToConsole("TV volumed up!");
}

void TV::volumeDown() {
	printToConsole("TV volumed down!");
}

void TV::channelUp() {
	printToConsole("TV channeled up!");
}

void TV::channelDown() {
	printToConsole("TV channeled down!");
}

// ============ PowerOn ============
PowerOn::PowerOn(TV * tv) :
	tv(tv)
{ }

void PowerOn::execute() {
	tv->powerOn();
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
	tv->powerOff();
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

}

void ChannelDown::setTV() {
	this->tv = tv;
}

TV * ChannelDown::getTV() {
	return this->tv;
}

// ============ Invoker ============
TVRemote::TVRemote() {

}

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
	// receiver
	TV * tv = new TV();

	// concrete commands
	PowerOn* powerOn = new PowerOn();
	PowerOff * powerOff = new PowerOff();

	VolumeUp* volumeUp = new VolumeUp();
	VolumeDown * volumeDown = new VolumeDown();

	ChannelUp * channelUp = new ChannelUp();
	ChannelDown * channelDown = new ChannelDown();

	// invoker
	TVRemote * tvRemote = new TVRemote();

	// execute
	tvCommand(tvRemote, powerOn);
	tvCommand(tvRemote, powerOff);
	tvCommand(tvRemote, volumeUp);
	tvCommand(tvRemote, volumeDown);
	tvCommand(tvRemote, channelUp);
	tvCommand(tvRemote, channelDown);

	return 0;
}
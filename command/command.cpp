#include "command.hpp"

// ============ TV ============
TV::TV() {

}

TV::~TV() {

}

void TV::powerOn() {
	std::cout << "TV is powered on!" << std::endl;
}

void TV::powerOff() {
	std::cout << "TV is powered off!" << std::endl;
}

// ============ TVCommand ============
TVCommand::~TVCommand() {

}

// ============ PowerOn ============
PowerOn::PowerOn() {

}

PowerOn::~PowerOn() {

}

void PowerOn::execute() {
	tv->powerOn();
}

// ============ PowerOff ============
PowerOff::PowerOff() {

}

PowerOff::~PowerOff() {

}

void PowerOff::execute() {
	tv->powerOff();
}

// ============ VolumeUp ============
VolumeUp::VolumeUp() {

}

VolumeUp::~VolumeUp() {

}

void VolumeUp::execute() {

}

// ============ VolumeDown ============
VolumeDown::VolumeDown() {

}

VolumeDown::~VolumeDown() {

}

void VolumeDown::execute() {

}

// ============ ChannelUp ============
ChannelUp::ChannelUp() {

}

ChannelUp::~ChannelUp() {

}

void ChannelUp::execute() {

}

// ============ ChannelDown ============
ChannelDown::ChannelDown() {

}

ChannelDown::~ChannelDown() {

}

void ChannelDown::execute() {

}

// ============ Invoker ============
TVRemote::TVRemote() {

}

TVRemote::~TVRemote() {

}

TVCommand* TVRemote::getTVCommand() const {
	return this->tvCommand;
}

void TVRemote::setCommand(TVCommand* tvCommand) {
	this->tvCommand = tvCommand;
}

void TVRemote::command() {
	getTVCommand()->execute();
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
	tvRemote->setCommand(powerOn);
	tvRemote->command();

	return 0;
}
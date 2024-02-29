#include "command.hpp"

// ============ TVCommand ============
TVCommand::~TVCommand() {

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
	VolumeUp* volumeUp = new VolumeUp();
	VolumeDown * volumeDown = new VolumeDown();

	ChannelUp * channelUp = new ChannelUp();
	ChannelDown * channelDown = new ChannelDown();

	// invoker
	TVRemote * tvRemote = new TVRemote();



	return 0;
}
#include <iostream>

#include "bridge.hpp"

enum State { OFF = 0, ON };

int const MAXIMUM_VOLUME = 10;
int const MINIMUM_VOLUME = 0;

int const MAXIMUM_CHANNEL = 100;
int const MINIMUM_CHANNEL = 1;

// ============= TVDevice =============
TVDevice::TVDevice(bool isMuted, bool isPowered, int volume, int channel, double watchTime, double totalTime) :
    isMuted(isMuted),
    isPowered(isPowered),
    volume(volume),
    channel(channel),
    watchTime(watchTime),
    totalTime(totalTime)
{
    std::cout << "TV Device created" << std::endl;
}

TVDevice::~TVDevice()
{
    std::cout << "TV Device destroyed" << std::endl;
}

void TVDevice::SetIsMuted(bool isMuted)
{
    this->isMuted = isMuted;
}

void TVDevice::SetPower(bool isPowered)
{
    this->isPowered = isPowered;
}

void TVDevice::SetVolume(int volume)
{
    this->volume = volume;
}

void TVDevice::SetChannel(int channel) 
{
    this->channel = channel;
}

void TVDevice::SetWatchTime(double watchTime)
{
    this->watchTime = watchTime;
}

void TVDevice::SetTotalTime(double totalTime)
{
    this->totalTime = totalTime;
}

bool TVDevice::GetIsMuted()
{
    return this->isMuted;
}

bool TVDevice::GetPower() 
{
    return this->isPowered;
}

int TVDevice::GetVolume() 
{
    return this->volume;
}

int TVDevice::GetChannel() 
{
    return this->channel;
}

double TVDevice::GetWatchTime()
{
    return this->watchTime;
}

double TVDevice::GetTotalTime()
{
    return this->totalTime;
}

// ============= RadioDevice =============
RadioDevice::RadioDevice(bool isMuted, bool isPowered, int volume, int channel) :
    isPowered(isPowered),
    volume(volume),
    channel(channel)
{
    std::cout << "Radio Device created" << std::endl;
}

RadioDevice::~RadioDevice()
{
    std::cout << "Radio Device destroyed" << std::endl;
}

void RadioDevice::SetIsMuted(bool isMuted)
{
    this->isMuted = isMuted;
}

void RadioDevice::SetPower(bool isPowered)
{
    this->isPowered = isPowered;
}

void RadioDevice::SetVolume(int volume)
{
    this->volume = volume;
}

void RadioDevice::SetChannel(int channel)
{
    this->channel  = channel;
}

bool RadioDevice::GetIsMuted()
{
    return this->isMuted;
}

bool RadioDevice::GetPower()
{
    return this->isPowered;
}

int RadioDevice::GetVolume()
{
    return this->volume;
}

int RadioDevice::GetChannel()
{
    return this->channel;
}

// ============= Abstraction =============
Remote::Remote(Device * device) :
    device(device)
{
    std::cout << "Remote Device created" << std::endl;
}

Remote::~Remote()
{
    std::cout << "Remote Device destroyed" << std::endl;
}

// turns the power on/off
bool Remote::TogglePower(Device * device)
{
    if(device->GetPower())
    {
        device->SetPower(State::OFF);
        std::cout << "Remote Device is OFF" << std::endl;
    }
    else
    {
        device->SetPower(State::ON);
        std::cout << "Remote Device is ON" << std::endl;
    }
        
    return device->GetPower();
}

// turns the volume on/off
bool Remote::ToggleMute(Device * device)
{
    if(device->GetIsMuted())
    {
        device->SetIsMuted(State::OFF);
        std::cout << "Remote Device is UNMUTED" << std::endl;
    }
    else
    {
        device->SetIsMuted(State::ON);
        std::cout << "Remote Device is MUTED" << std::endl;
    }
        
    return device->GetIsMuted();
}

// increases volume by one and check if not over maximum volume
int Remote::VolumeUp(Device * device)
{
    if(device->GetVolume() < MAXIMUM_VOLUME)
    {
        device->SetVolume(device->GetVolume() + 1);
    }

    return device->GetVolume();
}   

// decreases volume by one and check if not over minimum volume
int Remote::VolumeDown(Device * device)
{
    if(device->GetVolume() > MINIMUM_VOLUME)
    {
        device->SetVolume(device->GetVolume() - 1);
    }

    return device->GetVolume();
}

// increases channel by one and check if not over maximum channel
int Remote::ChannelUp(Device * device)
{
    if(device->GetChannel() < MAXIMUM_CHANNEL)
    {
        device->SetChannel(device->GetChannel() + 1);
    }

    return device->GetChannel();
}

// decrease channel by one and check if not over minimum channel
int Remote::ChannelDown(Device * device)
{
    if(device->GetChannel() > MINIMUM_CHANNEL)
    {
        device->SetChannel(device->GetChannel() - 1);
    }

    return device->GetChannel();
}

Device * Remote::GetDevice()
{
    return this->device;
}

void Remote::SetDevice(Device * device)
{
    this->device = device;
}

// ============= Redefined Abstraction =============
// constructor calls the 
TVRemote::TVRemote(Device * device) :
    Remote(device)
{
    std::cout << "TV Remote Device created" << std::endl;
}

TVRemote::~TVRemote()
{
    std::cout << "TV Remote Device destroyed" << std::endl;
}

bool TVRemote::TogglePower(Device * device)
{
    if(device->GetPower())
    {
        device->SetPower(State::OFF);
        std::cout << "TV Remote Device is OFF" << std::endl;
    }
    else
    {
        device->SetPower(State::ON);
        std::cout << "TV Remote Device is ON" << std::endl;
    }
        
    return device->GetPower();
}

bool TVRemote::ToggleMute(Device * device)
{
    if(device->GetIsMuted())
    {
        device->SetIsMuted(State::OFF);
        std::cout << "Remote Device is UNMUTED" << std::endl;
    }
    else
    {
        device->SetIsMuted(State::ON);
        std::cout << "Remote Device is MUTED" << std::endl;
    }
        
    return device->GetIsMuted();
}

int TVRemote::VolumeUp(Device * device)
{
    if(device->GetVolume() < MAXIMUM_VOLUME)
    {
        device->SetVolume(device->GetVolume() + 1);
    }

    return device->GetVolume();
}

int TVRemote::VolumeDown(Device * device)
{
    if(device->GetVolume() > MINIMUM_VOLUME)
    {
        device->SetVolume(device->GetVolume() - 1);
    }

    return device->GetVolume();
}

int TVRemote::ChannelUp(Device * device)
{
    if(device->GetChannel() < MAXIMUM_CHANNEL)
    {
        device->SetChannel(device->GetChannel() + 1);
    }

    return device->GetChannel();
}

int TVRemote::ChannelDown(Device * device)
{
    if(device->GetChannel() > MINIMUM_CHANNEL)
    {
        device->SetChannel(device->GetChannel() - 1);
    }

    return device->GetChannel();
}

int TVRemote::FastRewind(Device * device)
{
    return 0;
}

int TVRemote::Rewind(Device * device)
{   
    return 0;
}

int TVRemote::Play(Device * device)
{
    return 0;
}

int TVRemote::FastForward(Device * device)
{
    return 0;
}


// =============== Client Code ===============
// increases/decreases channel to requested new channel
void ChangeChannelTo(Remote * remote, int changeChannelTo)
{
    do
    {
        if(remote->GetDevice()->GetChannel() < changeChannelTo)
            remote->GetDevice()->SetChannel(remote->ChannelUp(remote->GetDevice()));
        else
            remote->GetDevice()->SetChannel(remote->ChannelDown(remote->GetDevice()));

        std::cout << remote->GetDevice()->GetChannel() << std::endl;
    }
    while(remote->GetDevice()->GetChannel() != changeChannelTo);
}

void ChangeVolumeTo(Remote * remote, int changeVolumeTo)
{
    do
    {
        if(remote->GetDevice()->GetVolume() < changeVolumeTo)
            remote->GetDevice()->SetVolume(remote->VolumeUp(remote->GetDevice()));
        else
            remote->GetDevice()->SetVolume(remote->VolumeDown(remote->GetDevice()));

        std::cout << remote->GetDevice()->GetVolume() << std::endl;
    }
    while(remote->GetDevice()->GetVolume() != changeVolumeTo);
}


// =============== Main ===============
int main()
{
    Device * radioDevice = new RadioDevice();
    Remote * radioRemote = new Remote(radioDevice);

    radioRemote->TogglePower(radioDevice);
    radioRemote->ToggleMute(radioDevice);
    ChangeVolumeTo(radioRemote, 4);
    ChangeChannelTo(radioRemote, 10);

    delete radioDevice;
    delete radioRemote;

    TVDevice * tvDevice = new TVDevice();
    TVRemote * tvRemote = new TVRemote(tvDevice);

    tvRemote->TogglePower(tvDevice);
    tvRemote->ToggleMute(tvDevice);
    ChangeVolumeTo(tvRemote, 7);
    ChangeChannelTo(tvRemote, 50);

    delete tvDevice;
    delete tvRemote;

    return 0;
}
// ============= Abstraction =============
// only put in functions that the abstract class needs to do,
class Remote
{
public:
    Remote(Device * device);
    virtual ~Remote() = default;

    virtual bool TogglePower() = 0;
    virtual bool ToggleMute() = 0;
    virtual int VolumeUp() = 0;
    virtual int VolumeDown() = 0;
    virtual int ChannelUp() = 0;
    virtual int ChannelDown() = 0;

// device needs to be accessible to the derived classes -- used protected
protected:
    Device * device; 
};

// ============= Redefined Abstraction =============
class TVRemote : public Remote
{
public:
    TVRemote(Device * device);
    ~TVRemote() override;

    bool TogglePower() override;
    bool ToggleMute() override;
    int VolumeUp() override;
    int VolumeDown() override;
    int ChannelUp() override;
    int ChannelDown() override;

    // tv only features
    int FastRewind(); // rewinds only 10 seconds
    int Rewind();
    int Play();
    int FastForward();
};

// ============= Implementation =============
class Device
{
public:
    virtual ~Device() = default;

    virtual void SetPower(bool power) = 0;
    virtual void SetVolume(int volume) = 0;
    virtual void SetChannel(int channel) = 0;

    virtual bool GetPower() = 0;
    virtual int GetVolume() = 0;
    virtual int GetChannel() = 0;
};

// ============= Concrete Implementation =============
class TVDevice : public Device
{
public:
    TVDevice();
    ~TVDevice() override;

    void SetPower(bool power) override;
    void SetVolume(int volume) override;
    void SetChannel(int channel) override;

    bool GetPower() override;
    int GetVolume() override;
    int GetChannel() override;

private:
    bool power;
    int volume;
    int channel;
    double time; // tv feature only
};

class RadioDevice : public Device
{
public:
    RadioDevice();
    ~RadioDevice();

private:
    bool power;
    int volume;
    int channel;
};


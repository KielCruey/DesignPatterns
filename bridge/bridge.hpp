// ============= Implementation =============
class Device
{
public:
    virtual ~Device() = default;

    virtual void SetIsMuted(bool isMuted) = 0;
    virtual void SetPower(bool power) = 0;
    virtual void SetVolume(int volume) = 0;
    virtual void SetChannel(int channel) = 0;

    virtual bool GetIsMuted() = 0;
    virtual bool GetPower() = 0;
    virtual int GetVolume() = 0;
    virtual int GetChannel() = 0;
};

// ============= Concrete Implementation =============
class TVDevice : public Device
{
public:
    TVDevice(bool isMuted = 1, 
            bool isPowered = 0, 
            int volume = 1, 
            int channel = 1, 
            double watchTime = 0, 
            double totalTime = 0);
            
    virtual ~TVDevice() override;

    virtual void SetIsMuted(bool isMuted) override;
    virtual void SetPower(bool isPowered) override;
    virtual void SetVolume(int volume) override;
    virtual void SetChannel(int channel) override;

    void SetWatchTime(double watchTime);
    void SetTotalTime(double totalTime);

    virtual bool GetIsMuted() override;
    virtual bool GetPower() override;
    virtual int GetVolume() override;
    virtual int GetChannel() override;

    double GetWatchTime();
    double GetTotalTime();

private:
    bool isMuted;
    bool isPowered;
    int volume;
    int channel;
    double watchTime; // tv feature only
    double totalTime; // tv feature only
};

class RadioDevice : public Device
{
public:
    RadioDevice(bool isMuted = 1,
                bool isPowered = 0,
                int volume = 1,
                 int channel = 1);
                 
    virtual ~RadioDevice() override;

    virtual void SetIsMuted(bool isMuted) override;
    virtual void SetPower(bool isPowered) override;
    virtual void SetVolume(int volume) override;
    virtual void SetChannel(int channel) override;

    virtual bool GetIsMuted() override;
    virtual bool GetPower() override;
    virtual int GetVolume() override;
    virtual int GetChannel() override;

private:
    bool isMuted;
    bool isPowered;
    int volume;
    int channel;
};

// ============= Abstraction =============
// only put in functions that the abstract class needs to do,
class Remote
{
public:
    Remote(Device * device);
    virtual ~Remote();

    virtual bool TogglePower(Device * device);
    virtual bool ToggleMute(Device * device);
    virtual int VolumeUp(Device * device);
    virtual int VolumeDown(Device * device);
    virtual int ChannelUp(Device * device);
    virtual int ChannelDown(Device * device);

    Device * GetDevice();
    void SetDevice(Device * device);

// device needs to be accessible to the derived classes -- used protected
protected:
    Device * device; 
};

// ============= Redefined Abstraction =============
class TVRemote : public Remote
{
public:
    TVRemote(Device * device);
    virtual ~TVRemote();

    virtual bool TogglePower(Device * device) override;
    virtual bool ToggleMute(Device * device) override;
    virtual int VolumeUp(Device * device) override;
    virtual int VolumeDown(Device * device) override;
    virtual int ChannelUp(Device * device) override;
    virtual int ChannelDown(Device * device) override;

    // tv only features
    int FastRewind(Device * device); // rewinds only 10 seconds
    int Rewind(Device * device);
    int Play(Device * device);
    int FastForward(Device * device);
};

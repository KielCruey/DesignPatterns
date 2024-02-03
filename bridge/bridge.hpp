// TVRemote needs this object
struct Movie
{
public:
    Movie(std::string name, 
            double currentDuration, 
            double totalDuration);

    ~Movie();

    void SetName(std::string name);
    void SetCurrentDuration(double currentDuration);
    void SetTotalDuration(double totalDuration);

    std::string GetName() const;
    double GetCurrentDuration() const;
    double GetTotalDuration() const;

private:
    std::string name;
    double currentDuration; // the place where the user is currently watching in [mins]
    double totalDuration;   // length of movie in [mins]
};

// ============= Implementation =============
class Device
{
public:
    virtual ~Device() = default;

    virtual void SetIsMuted(bool isMuted) = 0;
    virtual void SetPower(bool power) = 0;
    virtual void SetVolume(int volume) = 0;
    virtual void SetChannel(int channel) = 0;

    virtual bool GetIsMuted() const = 0;
    virtual bool GetPower() const = 0;
    virtual int GetVolume() const = 0;
    virtual int GetChannel()const  = 0;
};

// ============= Concrete Implementation =============
class TVDevice : public Device
{
public:
    TVDevice(Movie * movie = nullptr,
            bool isPlaying = 0,
            bool isMuted = 1, 
            bool isPowered = 0, 
            int volume = 1, 
            int channel = 1);
            
    ~TVDevice() override;   

    void SetMovie(Movie * movie);
    Movie * GetMovie();

    void SetIsPlaying(bool isPlaying);
    bool GetIsPlaying();

    void SetIsMuted(bool isMuted) override;
    void SetPower(bool isPowered) override;
    void SetVolume(int volume) override;
    void SetChannel(int channel) override;

    bool GetIsMuted() const override;
    bool GetPower() const override;
    int GetVolume() const override;
    int GetChannel() const override;

private:
    Movie * movie;

    bool isPlaying;
    bool isMuted;
    bool isPowered;
    int volume;
    int channel;
};

class RadioDevice : public Device
{
public:
    RadioDevice(bool isMuted = 1,
                bool isPowered = 0,
                int volume = 1,
                 int channel = 1);
                 
    ~RadioDevice() override;

    void SetIsMuted(bool isMuted) override;
    void SetPower(bool isPowered) override;
    void SetVolume(int volume) override;
    void SetChannel(int channel) override;

    bool GetIsMuted() const override;
    bool GetPower() const override;
    int GetVolume() const override;
    int GetChannel() const override;

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

    Device * GetDevice() const;
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
    bool TogglePlay(Device * device);
    double Rewind(Device * device);
    double FastRewind(Device * device); // rewinds only 10 seconds
    double FastForward(Device * device);
};

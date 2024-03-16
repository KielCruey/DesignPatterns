class Disposition;

// ======== Context ========
class Boss
{
public:
	Boss();
	~Boss();

	void helpMe();
	void directMe();
	
	char * getMood();

private:
	Mood * mood;

	void setMood(Disposition* mood);
};

// ======== State ========
class Mood
{
public:
	Mood();
	virtual ~Mood();

	void setBoss(Boss * boss);

	virtual void helpMe() = 0;
	virtual void directMe() = 0;

protected:
	Boss * boss;
};

// ======== Concrete State ========
class BadMood : public Mood
{
public:
	BadMood() = default;
	~BadMood() = default;

	void helpMe() override;
	void directMe() override;
};

class OkMood : public Mood
{
public:
	OkMood() = default;
	~OkMood() = default;

	void helpMe() override;
	void directMe() override;
};

class GoodMood : public Mood
{
public:
	GoodMood() = default;
	~GoodMood() = default;

	void helpMe() override;
	void directMe() override;
};

#include "state.inl"
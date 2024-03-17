class Mood;
class Boss;

// ======== State ========
class Mood
{
public:
	Mood(Boss * boss = nullptr);
	virtual ~Mood() = default;

	inline void setBoss(Boss * boss);

	virtual void helpMe() = 0;
	virtual void directMe() = 0;

protected:
	Boss * boss;
};

// ======== Context ========
class Boss
{
public:
	Boss(Mood * mood = nullptr);
	~Boss();

	// allows changing the Boss object at runtime.
	void TransitionMood(Mood* mood);

	// delegates part of its behavior to the current Mood object
	void helpMe();
	void directMe();
	
	inline Mood * getMood();
	inline void setMood(Mood * mood);

private:
	Mood * mood;
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
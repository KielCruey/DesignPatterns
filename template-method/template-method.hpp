// Templates as defined in the C++ language are a feature of the C++ programming
// language is not related to the Template Method pattern.C++ define templates
// for data types whereas the Template Method pattern define a template for an algorithm.


const int MIN_AMOUNT = 0;

const int MAX_SHOT_AMOUNT = 15;
const int MAX_BEVERAGE_AMOUNT = 30;

const int MAX_CUPS = 60;
const int MAX_WATER_AMOUNT = 600; // about 75 

// ============ Support Classes ============
class Extras
{
public:
	Extras(int sugarShot = MAX_SHOT_AMOUNT,
		   int creamShot = MAX_SHOT_AMOUNT,
		   int milkShot = MAX_SHOT_AMOUNT,
		   int chocolateShot = MAX_SHOT_AMOUNT);
	~Extras();

	// getters/setters
	inline int getSugarShot() const;
	inline int getCreamShot() const;
	inline int getMilkShot() const;
	inline int getChocolateShot() const;

	inline void setSugarShot(int sugarShot);
	inline void setCreamShot(int creamShot);
	inline void setMilkShot(int milkShot);
	inline void setChocolateShot(int chocolateShot);

private:
	int sugarShot;
	int creamShot;
	int milkShot;
	int chocolateShot;
};

class Teas
{
public:
	Teas(int greenTea = MAX_BEVERAGE_AMOUNT,
		 int blackTea = MAX_BEVERAGE_AMOUNT,
		 int chiaTea = MAX_BEVERAGE_AMOUNT);
	~Teas();

	// getters/setters
	inline int getGreenTea() const;
	inline int getBlackTea() const;
	inline int getChiaTea() const;

	inline void setGreenTea(int greenTea);
	inline void setBlackTea(int blackTea);
	inline void setChiaTea(int chiaTea);

private:
	int greenTea;
	int blackTea;
	int chiaTea;
};

class Coffees
{
public:
	Coffees(int lightRoast = MAX_BEVERAGE_AMOUNT,
			int mediumRoast = MAX_BEVERAGE_AMOUNT,
			int darkRoast = MAX_BEVERAGE_AMOUNT);
	~Coffees();

	// getters/setters
	inline int getLightRoast() const;
	inline int getMediumRoast() const;
	inline int getDarkRoast() const;

	inline void setLightRoast(int lightRoast);
	inline void setMediumRoast(int mediumRoast);
	inline void setDarkRoast(int darkRoast);

private:
	int lightRoast;
	int mediumRoast;
	int darkRoast;
};

// ========== Abstract Template ==========
class BeverageMaker
{
public:
	BeverageMaker(Extras * extras = nullptr,
				  Teas * teas = nullptr,
				  Coffees * coffees = nullptr,
				  int cups = MAX_CUPS,
				  double waterAmount = MAX_WATER_AMOUNT);
	~BeverageMaker();

	void makeBeverage();
	void restockExtras();
	void restockTeas();
	void restockCoffees();

	// getters/setters
	inline int getCups() const;
	inline double getWaterAmount() const;

	inline void setCups(int cups);
	inline void setWaterAmount(double waterAmount); // in fl oz

protected:
	Extras * extras;
	Teas * teas;
	Coffees * coffees;

	virtual void placeCup();
	virtual void boilWater();
	virtual void brew() = 0;
	virtual void pourInCup();
	virtual void addExtras() = 0;

private:
	int cups;
	double waterAmount;
};

// ========== Concrete Templates ==========
class TeaMaker : public BeverageMaker
{
public:
	void brew() override;
	void addExtras() override;
};

class CoffeeMaker : public BeverageMaker
{
public:
	void brew() override;
	void addExtras() override;
};

#include "template-method.inl"
#include <vector>

const double BIKE_RATE = 10.0;
const double BIKE_FARE = 0.0;

const double BUS_RATE = 35.0;
const double BIKE_FARE = 3.0; // per trip

const double CAR_RATE = 50.0;
const double BIKE_FARE = 4.5; // per gallon of gas

// ========== Abstract Strategy ==========
class CommuteStrategy
{
public:
	CommuteStrategy(const double averageRateOfTravel = NULL,
					double costToTravel = NULL);
	virtual ~CommuteStrategy() = default;

	// virtuals 
	virtual void travelToDestination() = 0;

	// getters/setters
	inline const double getAverageRateOfTravel() const;
	inline double getCostToTravel() const;

	inline void setCostToTravel(double costToTravel);

private:
	const double averageRateOfTravel; // in mph
	double costToTravel; // in USD
};

// ========== Concrete Strategy ==========
class Bike : public CommuteStrategy
{
public:
	Bike();
	virtual ~Bike() override = default;
	void travelToDestination() override;

	// getters/setters
	inline double getTotalTimeCommuted() const;

private:
	double totalTimeCommuted; // in mins
};

class Bus : public CommuteStrategy
{
public:
	Bus();
	virtual ~Bus() override = default;
	void travelToDestination() override;

	// getters/setters
	inline double getTotalTimeCommuted() const;

private:
	int routesToDestination; // one way to destination
	double totalTimeCommuted; // in mins
};

class Car : public CommuteStrategy
{
public:
	Car();
	virtual ~Car() override = default;
	void travelToDestination() override;

	// getters/setters
	inline double getTotalTimeCommuted() const;

private:
	double mpg;
	double totalTimeCommuted; // in mins
};

// ========== Context ==========
class TravelTrip
{
public:
	explicit TravelTrip(CommuteStrategy&& commuteStrategy);
	virtual ~TravelTrip();

	void travel(CommuteStrategy* commuteStrategy);

	// setters
	inline void setCommuteStrategy(CommuteStrategy* commuteStrategy);

private:
	CommuteStrategy * commuteStrategy;
};

#include "strategy.inl"
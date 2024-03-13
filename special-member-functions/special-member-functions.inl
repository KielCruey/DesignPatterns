// ========= Motorcycle =========
inline std::string Motorcycle::getMake() {
	return this->make;
}

inline std::string Motorcycle::getModel() {
	return this->model;
}

inline int * Motorcycle::getSerialNumber() {
	return this->serialNumber;
}

inline void Motorcycle::setMake(std::string make) {
	this->make = make;
}

inline void Motorcycle::setModel(std::string model) {
	this->model = model;
}

inline void Motorcycle::setSerialNumber(int * serialNumber) {
	this->serialNumber = serialNumber;
}
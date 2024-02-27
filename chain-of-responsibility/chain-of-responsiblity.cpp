#include "chain-of-responsibility.hpp"

// =========== BaseHandler ===========
BaseHandler::BaseHandler(Handler * nextHandler) :
    nextHandler(nextHandler)
{
    std::cout << "BaseHandler created" << std::endl;
}

BaseHandler::~BaseHandler() {
    std::cout << "BaseHandler deleted" << std::endl;
}

void BaseHandler::setHandler(Handler * handler) {
    this->nextHandler = nextHandler;
}

Handler * BaseHandler::getHandler() {
    return this->nextHandler;
}

std::string BaseHandler::Handle(std::string command) {
    if(nextHandler != nullptr) {
        return nextHandler->Handle(command);
    }
    else return "";
}

// =========== RobotBodyHandler ===========
RobotBodyHandler::RobotBodyHandler(bool hasRobotChest,
                                   bool hasRobotPelvis) :
    hasRobotChest(hasRobotChest),
    hasRobotPelvis(hasRobotPelvis)                                
{
    std::cout << "RobotBodyHandler created" << std::endl;
}

RobotBodyHandler::~RobotBodyHandler() {
    std::cout << "RobotBodyHandler deleted" << std::endl;
}

std::string RobotBodyHandler::Handle(std::string command) {
    return 0;
}

// =========== RobotLimbHandler ===========
RobotLimbHandler::RobotLimbHandler(bool hasRobotRightArm,
                                   bool hasRobotLeftArm,
                                   bool hasRobotRightLeg,
                                   bool hasRobotLeftLeg) :
    hasRobotRightArm(hasRobotRightArm),
    hasRobotLeftArm(hasRobotLeftArm),
    hasRobotRightLeg(hasRobotRightLeg),
    hasRobotLeftLeg(hasRobotLeftLeg)
{
    std::cout << "RobotLimbHandler created" << std::endl;
}

RobotLimbHandler::~RobotLimbHandler() {
    std::cout << "RobotLimbHandler destroyed" << std::endl;
}

std::string RobotLimbHandler::Handle(std::string command) {
    return 0;
}

// =========== RobotCraniumHandler ===========
RobotCraniumHandler::RobotCraniumHandler(bool hasRobotCranium)  :
    hasRobotCranium(hasRobotCranium)
{
    std::cout << "RobotCraniumHandler created" << std::endl;
}

RobotCraniumHandler::~RobotCraniumHandler() {
    std::cout << "RobotCraniumHandler deleted" << std::endl;
}

std::string RobotCraniumHandler::Handle(std::string command) {
    return 0;
}

// =========== Main ===========
int main() {
    return 0;
}
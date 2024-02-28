#include <iostream>
#include <string>

// ========= Handler =========
class Handler 
{
public: 
    virtual ~Handler() = 0;

    virtual void setHandler(Handler * nextHandler) = 0;
    virtual Handler * getHandler() = 0;

    virtual Handler * setNext(Handler * handler) = 0; // function chains the next handling check
    virtual std::string Handle(std::string command) = 0;
};

// ========= Base Handler =========
class BaseHandler : public Handler
{
public: 
    BaseHandler(Handler * nextHandler = nullptr);
    virtual ~BaseHandler() override;

    virtual void setHandler(Handler * nextHandler) override;
    virtual Handler * getHandler() override;

    virtual Handler * setNext(Handler * handler) override;
    virtual std::string Handle(std::string command) override;

private:
    Handler * nextHandler;
};

// ========= Concrete Handler(s) =========
class RobotBodyHandler : public BaseHandler 
{
public: 
    RobotBodyHandler(bool hasRobotChest = NULL,
                     bool hasRobotPelvis = NULL);
    virtual ~RobotBodyHandler() override;

    virtual Handler * setNext(Handler * handler) override;
    virtual std::string Handle(std::string command) override;

private:
    bool hasRobotChest;
    bool hasRobotPelvis;
};

class RobotLimbHandler : public BaseHandler 
{
public: 
    RobotLimbHandler(bool hasRobotRightArm = NULL,
                     bool hasRobotLeftArm = NULL,
                     bool hasRobotRightLeg = NULL,
                     bool hasRobotLeftLeg = NULL);
    virtual ~RobotLimbHandler() override;

    virtual Handler * setNext(Handler * handler) override;
    virtual std::string Handle(std::string command) override;

private:
    bool hasRobotRightArm;
    bool hasRobotLeftArm;
    bool hasRobotRightLeg;
    bool hasRobotLeftLeg;
};

class RobotCraniumHandler : public BaseHandler 
{
public: 
    RobotCraniumHandler(bool hasRobotCranium = NULL);
    virtual ~RobotCraniumHandler() override;

    virtual Handler * setNext(Handler * handler) override;
    virtual std::string Handle(std::string command) override;

private:
    bool hasRobotCranium;
};
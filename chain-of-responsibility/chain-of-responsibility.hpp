#include <iostream>
#include <string>
#include <vector>

// ========= Handler =========
class Handler 
{
public: 
    virtual Handler * setNext(Handler * handler) = 0; // function chains the next handling check
    virtual std::string Handle(std::string request) = 0;
};

// ========= Base Handler =========
class BaseHandler : public Handler
{
public: 
    BaseHandler(Handler * nextHandler = nullptr);
    virtual ~BaseHandler();

    virtual Handler * setNext(Handler * handler) override;
    virtual std::string Handle(std::string request) override;

    void setHandler(Handler* nextHandler);
    Handler* getHandler() const;

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

    virtual std::string Handle(std::string request) override;

    void setHasRobotChest(bool hasRobotChest);
    void setHasRobotPelvis(bool hasRobotPelvis);
    bool getHasRobotChest() const;
    bool getHasRobotPelvis() const;

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

    virtual std::string Handle(std::string request) override;

    void setHasRobotRightArm(bool hasRobotRightArm);
    void setHasRobotLeftArm(bool hasRobotLeftArm);
    void setHasRobotRightLeg(bool hasRobotRightLeg);
    void setHasRobotLeftLeg(bool hasRobotLeftLeg);
    bool getHasRobotRightArm() const;
    bool getHasRobotLeftArm() const;
    bool getHasRobotRightLeg() const;
    bool getHasRobotLeftLeg() const;

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

    virtual std::string Handle(std::string request) override;

    void setHasRobotCranium(bool hasRobotCranium);
    bool getHasRobotCranium() const;

private:
    bool hasRobotCranium;
};

#include <string>

// ========= Handler =========
class Handler 
{
public: 
    virtual ~Handler() = 0;

    virtual void setHandler(Handler * handler) = 0;
    virtual Handler * getHandler() = 0;

    virtual std::string Handle() = 0;
};

// ========= Base Handler =========
class BaseHandler : public Handler
{
public: 
    BaseHandler(Handler * nextHandler = nullptr);
    virtual ~BaseHandler() override;

    virtual void setHandler(Handler * handler) override;
    virtual Handler * getHandler() override;

    virtual std::string Handle() override;

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

    virtual std::string Handle() override;

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

    virtual std::string Handle() override;

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

    virtual std::string Handle() override;

private:
    bool hasRobotCranium;
};
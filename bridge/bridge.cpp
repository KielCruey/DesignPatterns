#include "bridge.hpp"

// ============= Abstraction =============
Remote::Remote(Device * device) :
    device(device)
{

}

Remote::~Remote()
{

}

// ============= Redefined Abstraction =============
// constructor calls the 
TVRemote::TVRemote(Device * device) :
    Remote(device)
{
    
}

TVRemote::~TVRemote()
{
    
}

// =============== Main ===============
int main()
{
    return 0;
}
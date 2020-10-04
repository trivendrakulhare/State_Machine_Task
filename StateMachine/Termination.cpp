/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/

#include "Termination.hpp"
#include <iostream>
#include "fsmlist.hpp"

//---------------------------------------------------------------------------
//
// Termination State
static int TerminationFlag = 0;
class InitiateTermination :public Termination
{
    
    void entry() override
    {
    
        if (TerminationFlag == 0)
        {
            std::cout << "Termination Activated" << std::endl;
            TerminationFlag = 1;
        }
        
    }
};

//---------------------------------------------------------------------------
//

class NoTermination :public Termination
{
    void entry() override
    {
        std::cout << "idle state" << std::endl;
        
    }
};

//---------------------------------------------------------------------------
//
// Base State: Default implementation

void Termination::react(TerminationStart const&)
{
    transit<InitiateTermination>();
}

void Termination::react(TerminationStop const&)
{
    transit<NoTermination>();
}

//---------------------------------------------------------------------------
//
// Initial State definition

FSM_INITIAL_STATE(Termination,NoTermination)

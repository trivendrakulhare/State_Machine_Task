/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#include "InitialEngineIgnition.hpp"
#include "fsmlist.hpp"

//---------------------------------------------------------------------------
//
// Initial Engine Ignition State

static int initialStagingFlag = 0;

class Start : public InitialEngineIgnition
{
	void entry() override
    {
		std::cout << "Initial Engine Ignintion Started" << std::endl;
		send_event(LaunchPadClampRelease());
	}
};

//---------------------------------------------------------------------------
//

class Stop : public InitialEngineIgnition
{
	void entry() override
    {
		std::cout << "Initial Engine Stopped" << std::endl;
		send_event(InitialEngineStaging());
		send_event(NextEngineStart());
	}
};

//---------------------------------------------------------------------------
//
// Staging
class Staging : public InitialEngineIgnition
{
	void entry() override
    {
		if (initialStagingFlag == 0)
        {
			std::cout << "Staging Initiated" << std::endl;
			initialStagingFlag = 1;
		}
	}
};

//---------------------------------------------------------------------------
//
// Base State: Default Implementations

void InitialEngineIgnition::react(InitialIgnitionEventStart const&)
{
	transit<Start>();
}

void InitialEngineIgnition::react(InitialIgnitionEventStop const&)
{
	transit<Stop>();
}

void InitialEngineIgnition::react(InitialEngineStaging const&)
{
	transit<Staging>();
}


//---------------------------------------------------------------------------
//
// Initial State Definition

FSM_INITIAL_STATE(InitialEngineIgnition, Stop)



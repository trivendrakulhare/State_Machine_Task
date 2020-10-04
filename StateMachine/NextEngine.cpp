/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#include "NextEngine.hpp"
#include <iostream>
#include "fsmlist.hpp"

//---------------------------------------------------------------------------
//

static int fairingJettisonFlag = 0;
// Next Engine Ignition State

class NextStart : public NextEngine
{
	void entry() override
    {
		if (fairingJettisonFlag == 0)
        {
			std::cout << "Next Engine Ignintion Started" << std::endl;
			send_event(FairingJettisonStart());
			fairingJettisonFlag = 1;
		}
	}
};


//---------------------------------------------------------------------------
//

class NextStop : public NextEngine
{
	void entry() override
    {
		std::cout << "Next Engine Ignintion Stopped" << std::endl;
	}
};


//---------------------------------------------------------------------------
//
// Base State: Default Implementation

void NextEngine::react(NextEngineStart const&)
{
	transit<NextStart>();
}

void NextEngine::react(NextEngineStop const&)
{
	transit<NextStop>();
}

//---------------------------------------------------------------------------
//
// Initial State Definition

FSM_INITIAL_STATE(NextEngine, NextStop)

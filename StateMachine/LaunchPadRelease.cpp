/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#include "LaunchPadRelease.hpp"
#include<iostream>
#include "fsmlist.hpp"

//---------------------------------------------------------------------------
//
//Clamp Release State

static int clampReleaseFlag = 0;
class InitiateClampRealease :public LaunchPadRelease
{
	void entry() override
    {
		if (clampReleaseFlag == 0)
        {
			std::cout << "Launch pad clamp release initiated" << std::endl;
			send_event(InitialIgnitionEventStop());
			clampReleaseFlag = 1;
		}
	}
};


//---------------------------------------------------------------------------
//

class InitialStateStop :public LaunchPadRelease
{
	void entry() override
    {
		std::cout << "Clamp are closed" << std::endl;
	}
};

//---------------------------------------------------------------------------
//
// Base State: Default Implementation

void LaunchPadRelease::react(LaunchPadClampRelease const&)
{
	transit<InitiateClampRealease>();
}

void LaunchPadRelease::react(LaunchPadClampStop const&)
{
	transit<InitialStateStop>();
}

//---------------------------------------------------------------------------
//
// Initial State Definition

FSM_INITIAL_STATE(LaunchPadRelease, InitialStateStop)

/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#include "FairingJettison.hpp"
#include <iostream>
#include "fsmlist.hpp"

//---------------------------------------------------------------------------
//
// Fairing Jettision State

static int jettisonStartFlag = 0;
class JettisonStart :public FairingJettison
{
	
	void entry() override
    {
	
		if (jettisonStartFlag == 0)
        {
			std::cout << "Payload Fairing being Jettisoned" << std::endl;
			send_event(PayloadReleaseStart());
			jettisonStartFlag = 1;
		}
		
	}
};

//---------------------------------------------------------------------------
//

class JettisonStop :public FairingJettison
{
	void entry() override
    {
		std::cout << "idle state" << std::endl;
		
	}
};


//---------------------------------------------------------------------------
//
//Base State: Default Implementation

void FairingJettison::react(FairingJettisonStart const&)
{
	transit<JettisonStart>();
}

void FairingJettison::react(FairingJettionStop const&)
{
	transit<JettisonStop>();
}

//---------------------------------------------------------------------------
//

FSM_INITIAL_STATE(FairingJettison,JettisonStop)

/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#include "PayloadRealease.hpp"
#include "fsmlist.hpp"
#include <iostream>

//---------------------------------------------------------------------------
//


static int payloadReleaseFLag = 0;

// Payload release state

class PayloadStart :public PayloadRealease
{
	void entry() override
    {
		if (payloadReleaseFLag == 0)
        {
			std::cout << "Payload Released" << std::endl;
            send_event(TerminationStart());
            payloadReleaseFLag = 1;
		}
	}
};

//---------------------------------------------------------------------------
//

class PayloadStop :public PayloadRealease
{
	void entry() override
    {
		std::cout << "Payload Stopped" << std::endl;
	}
};

//---------------------------------------------------------------------------
//
// Base State: Default Implementation


void PayloadRealease::react(PayloadReleaseStart const&)
{
	transit<PayloadStart>();
}

void PayloadRealease::react(PayloadReleaseStop const&)
{
	transit<PayloadStop>();
}

//---------------------------------------------------------------------------
//
// Initial State Definition

FSM_INITIAL_STATE(PayloadRealease,PayloadStop)

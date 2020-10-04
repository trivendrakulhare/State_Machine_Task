/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#include "CountDown.hpp"
#include <iostream>
#include "fsmlist.hpp"

//---------------------------------------------------------------------------
//
// Count Down State
class StartCountDown : public CountDown
{
	
	void entry() override
    {
		for (int i = 10; i > 0; i--)
        {
		
			std::cout << "Count Down: T-" << i << std::endl;
			if (i == 1)
            {
				send_event(InitialIgnitionEventStart());
			}
		}
			
		}
	};

//---------------------------------------------------------------------------
//
// Initial State Definition

FSM_INITIAL_STATE(CountDown, StartCountDown)



/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#pragma once
#include "tinyfsm.hpp"

//---------------------------------------------------------------------------
//
// Event Decleration

struct PayloadReleaseStart: tinyfsm::Event{};
struct PayloadReleaseStop : tinyfsm::Event {};

//---------------------------------------------------------------------------
//
// PayloadRelease (FSM base class) declaration

class PayloadRealease : public tinyfsm::Fsm<PayloadRealease>
{
    /* react(), entry() and exit() functions need to be accessible
     from tinyfsm::Fsm class */
    
public:
    // Default reaction for unhandled events
	void react(tinyfsm::Event const&) { };
    
    //non-virtual declaration: reactions are the same for all states
    
	void react(PayloadReleaseStart const&);
	void react(PayloadReleaseStop const&);
    
    // pure virtual: enforce implementation in all states
    
	virtual void entry(void) = 0;
	void exit(void) { };
};



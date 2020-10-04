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

struct FairingJettisonStart : tinyfsm::Event {};
struct FairingJettionStop: tinyfsm::Event{};

//---------------------------------------------------------------------------
//
// FairingJettison (FSM base class) declaration

class FairingJettison : public tinyfsm::Fsm<FairingJettison>
{
    /* react(), entry() and exit() functions need to be accessible
     from tinyfsm::Fsm class */
    
public:
    // Default reaction for unhandled events
	void react(tinyfsm::Event const&) { };
    
    //non-virtual declaration: reactions are the same for all states
    
	void react(FairingJettisonStart const&);
	void react(FairingJettionStop const&);
    
   // pure virtual: enforce implementation in all states
    
	virtual void entry(void) = 0;
	void exit(void) { };
};


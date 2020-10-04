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

struct LaunchPadClampRelease : tinyfsm::Event {};
struct LaunchPadClampStop : tinyfsm::Event {};


//---------------------------------------------------------------------------
//
// LaunchPadRelease (FSM base class) declaration

class LaunchPadRelease : public tinyfsm::Fsm<LaunchPadRelease>
{
    
    /* react(), entry() and exit() functions need to be accessible
     from tinyfsm::Fsm class */
public:
    // Default reaction for unhandled events
	void react(tinyfsm::Event const&) { };
    
    //non-virtual declaration: reactions are the same for all states
    
	void react(LaunchPadClampRelease const&);
	void react(LaunchPadClampStop const&);
    
    // pure virtual: enforce implementation in all states
    
	virtual void entry(void) = 0;
	void exit(void) { };
};


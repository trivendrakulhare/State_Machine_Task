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

struct NextEngineStart : tinyfsm::Event {};
struct NextEngineStop : tinyfsm::Event {};

//---------------------------------------------------------------------------
//
// NextEngine (FSM base class) declaration

class NextEngine : public tinyfsm::Fsm<NextEngine>
{
    /* react(), entry() and exit() functions need to be accessible
     from tinyfsm::Fsm class */
    
public:
    // Default reaction for unhandled events
	void react(tinyfsm::Event const&) { };
    
    //non-virtual declaration: reactions are the same for all states
    
	void react(NextEngineStart const&);
	void react(NextEngineStop const&);
	
    // pure virtual: enforce implementation in all states
    
	virtual void entry(void) = 0;
	void exit(void) { };
};


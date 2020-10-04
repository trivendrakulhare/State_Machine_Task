/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/
#pragma once

#include "tinyfsm.hpp"
#include <iostream>

//---------------------------------------------------------------------------
//
// Event Decleration

struct InitialIgnitionEventStart : tinyfsm::Event {};
struct InitialIgnitionEventStop : tinyfsm::Event {};
struct InitialEngineStaging : tinyfsm::Event {};

//---------------------------------------------------------------------------
//
// InitialEngineIgnition (FSM base class) declaration
//
class InitialEngineIgnition: public tinyfsm::Fsm<InitialEngineIgnition>
{
    /* react(), entry() and exit() functions need to be accessible
     from tinyfsm::Fsm class */
	
public:
    // Default reaction for unhandled events
	void react(tinyfsm::Event const&) { };
    
    //non-virtual declaration: reactions are the same for all states
    
	void react(InitialIgnitionEventStart const&);
	void react(InitialIgnitionEventStop const&);
	void react(InitialEngineStaging const&);
    
    // pure virtual: enforce implementation in all states
    
	virtual void entry(void) = 0;
	void exit(void) { };


};


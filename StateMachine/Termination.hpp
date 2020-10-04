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

struct TerminationStart : tinyfsm::Event {};
struct TerminationStop: tinyfsm::Event{};


//---------------------------------------------------------------------------
//
// Termination (FSM base class) declaration

class Termination : public tinyfsm::Fsm<Termination>
{
    
   /* react(), entry() and exit() functions need to be accessible
    from tinyfsm::Fsm class */
    
    
public:
    // Default reaction for unhandled events
    
    void react(tinyfsm::Event const&) { };
    
    //non-virtual declaration: reactions are the same for all states
    
    void react(TerminationStart const&);
    void react(TerminationStop const&);
    
    
    // pure virtual: enforce implementation in all states
    
    virtual void entry(void) = 0;
    void exit(void) { };
};

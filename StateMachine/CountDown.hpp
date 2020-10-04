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

struct countDownEvent : tinyfsm::Event {};

class CountDown: public tinyfsm::Fsm<CountDown>
{
public:
	void react(tinyfsm::Event const&) { };
	
	virtual void entry(void) = 0;
	
};


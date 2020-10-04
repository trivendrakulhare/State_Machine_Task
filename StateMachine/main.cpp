/*
* @author: Trivendra Kulhare
* Date: 10/04/2020
* RFA Task
*/

#include "fsmlist.hpp"
#include <iostream>
#include "CountDown.hpp"

using namespace std;


int main()
{
    fsm_list::start();

    countDownEvent countDownEvent;

    send_event(countDownEvent);
    
}

#ifndef FSMLIST_HPP_INCLUDED
#define FSMLIST_HPP_INCLUDED

#include "tinyfsm.hpp"
#include "InitialEngineIgnition.hpp"
#include "CountDown.hpp"
#include "LaunchPadRelease.hpp"
#include "NextEngine.hpp"
#include "FairingJettison.hpp"
#include "PayloadRealease.hpp"
#include "Termination.hpp"

//---------------------------------------------------------------------------
//

using fsm_list = tinyfsm::FsmList< CountDown ,InitialEngineIgnition ,LaunchPadRelease , NextEngine , FairingJettison , PayloadRealease, Termination >;


//---------------------------------------------------------------------------
//


template<typename E>
void send_event(E const & event)
{
  fsm_list::template dispatch<E>(event);
}


#endif

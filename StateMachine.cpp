#include "StateMachine.h"

StateMachine::~StateMachine(){
    Exit();
}
/*
* Initialize State Machine
*/
void StateMachine::Init(StateMachine* pOwner, State* initialState){
    m_pOwner = pOwner;
    mCurrentState = initialState;
    mCurrentState->Enter();
}

/*
* Update state and enter the new state
*/
void StateMachine::UpdateState(State* newState){
    mCurrentState = newState;
    mCurrentState->Enter();
}

/*
* Update by executing the state.
*/
void StateMachine::Update(){
    mCurrentState->Execute(m_pOwner);
}

/*
* Cleanup
*/
void StateMachine::Exit(){
    delete m_pOwner;
    delete mCurrentState;
}
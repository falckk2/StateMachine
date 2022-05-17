#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "State.h"
class State; //forward defining
class StateMachine{
private:
    StateMachine* m_pOwner; // itself, handy for updating
    State* mCurrentState; // the current state

public:
    ~StateMachine();
    void Init(StateMachine* pOwner, State* initialState); //initialisation
    void UpdateState(State* newState); //update state
    void Update(); //use the current state to update itself
    void Exit(); //cleanup

};
#endif
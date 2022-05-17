#ifndef STATE_H
#define STATE_H

#include "StateMachine.h"

class StateMachine; //forward defining
class State{
private:
    int m_nrOfStates; //number of states it can enter from its current state
    State** m_pConnections; //pointers to the states it can enter into from this one
    char m_node; // Name, A,B,C

public:
    ~State();
    //Initialize is separate from constructor, since all items need to be constructed before references can be given
    void Init(int numStates, State** connectionList, char name); 
    //Enter, do stuff when entering a state
    void Enter();
    //Execute state which leads to reach next state
    void Execute(StateMachine* pOwner);
    //Cleanup
    void Exit();
};
#endif
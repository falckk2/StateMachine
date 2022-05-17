#include "State.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <dos.h>
#include <iostream>
#include "EventGenerator.h"
State::~State(){
    Exit();
}
/*
* Initialize all variables
*/
void State::Init(int numStates, State** connectionList, char name){
    m_nrOfStates = numStates;
    m_pConnections = connectionList;
    m_node = name;
}

/*
* Sleep 1 second before writing out the entered state
*/
void State::Enter(){
    Sleep(1);
    std::cout << "Entered State: " << m_node << std::endl;
}

/*
* Finds what the next state will be
* Has the StateMachine update its current state
*/
void State::Execute(StateMachine* pOwner){
    int connection = GenerateEvent(m_nrOfStates);
    pOwner-> UpdateState(m_pConnections[connection]);
}
void State::Exit(){
    delete m_pConnections;
}
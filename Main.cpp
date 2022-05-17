#include <iostream>
#include "StateMachine.h"

using namespace std;

int main(){

    //create instances of states
    State* stateA = new State();
    State* stateB = new State();
    State* stateC = new State();

    //create pointer of pointers
    State** connectionsA = new State*[2];
    State** connectionsB = new State*[1];
    State** connectionsC = new State*[1];

    // connect them
    connectionsA[0] = stateA;
    connectionsA[1] = stateB;
    connectionsB[0] = stateC;
    connectionsC[0] = stateB;

    // initialize states
    stateA->Init(2, connectionsA, 'A');
    stateB->Init(1, connectionsB, 'B');
    stateC->Init(1, connectionsC, 'C');
    
    //create state machine
    StateMachine* stateMachine = new StateMachine();
    
    cout << "State machine started!" << endl;
    
    //Initialize State Machine
    stateMachine->Init(stateMachine, stateA);

    bool done = false;
    string decision;
    
    cout << "Enter \"Update\" when you want to update the state machine, \"Exit\" when you want to exit" << endl;

    // Let people decide themselves what to do, update or exit at anytime. Input string will determine the decision
    do {
        cin >> decision;

        if(decision.compare("Update") == 0){
            cout << "Updating state!" << endl;
            stateMachine->Update();
            cout << "Enter \"Update\" or \"Exit\"" << endl;
        }
        else if(decision.compare("Exit") == 0){
            cout << "Shutting Down!";
            stateMachine->Exit();
            stateA->Exit();
            stateB->Exit();
            stateC->Exit();
            done = true;
        }else{
            cout << "not valid decision" << endl;
        }
    } while(!done);


    return 0;
};

#include <stdlib.h>
#include <time.h>
using namespace std;

/*
* Generate random numbers
* changes seed in order to assure randomness between sessions
*/
int GenerateEvent(int nrOfPossibleChanges){
    srand(time(0));
    return rand() % nrOfPossibleChanges;
}
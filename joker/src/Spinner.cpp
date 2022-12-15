#include "Spinners.h"
#include <cstdlib>
#include <ctime>

Spinners::Spinners() {
    dif = 0;  //0 is the basic difficulty, -1 will be easy, 1 will be hard
    seed = time(NULL);
    //Random Number generator, should only be called once
}
Spinners::~Spinners() {}

void Spinners::setDifficulty(int i) {
    dif = i;
}

int Spinners::spin(bool b) { //Dif modifier makes the three spinners
    int v = 0;
    if (b) {  //Large spinner (1-8)
        v = (rand_r(&seed) % 8) + 1;
        //Generate randomn number between 1-8
        if (dif > 0) {if (v < 8) v++;}
        //if diffilculty is 1 and value is not the maximum(8) add 1.
        else if (v > 1) v += dif;
        //otherwise if value is not the minimum add the diffilculty modifier.

    } else {  //Small spinner (4-7)
        v = (rand_r(&seed) % 4) + 4;
        //Generate randomn number between 4-7
        if (dif > 0) {if (v < 7) v++;}
        //if diffilculty is 1 and value is not the maximum(7) add 1
        else if (v > 4) v += dif;
        //otherwise if the value is not the minimum add the dif modifier.
    }
    return v;
}

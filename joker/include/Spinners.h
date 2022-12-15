#ifndef SPINNERS
#define SPINNERS

class Spinners{ //Handles the random number generation
 public:
    Spinners(); //Generates a random number seed
    ~Spinners(); //Included for habit forming
    int spin(bool b); //Returns a value from the spin
    void setDifficulty(int i); //Changes how the bets affects outcome
 private:
    int dif; //Spin modifier
    unsigned int seed; //Random Number Generation
};

#endif //SPINNERS

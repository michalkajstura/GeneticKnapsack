#ifndef GENETICKNAPSACK_CRANDOMGENERATOR_H
#define GENETICKNAPSACK_CRANDOMGENERATOR_H

#include <random>

class CRandomGenerator {

private:
    CRandomGenerator() {}

public:
    static double generate();
    static int choice(int from, int to);
};


#endif //GENETICKNAPSACK_CRANDOMGENERATOR_H

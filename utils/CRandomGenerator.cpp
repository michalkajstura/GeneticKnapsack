#include "../includes/CRandomGenerator.h"

using namespace std;

double CRandomGenerator::generate() {
    mt19937 generator(std::random_device{}());
    uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(generator);
}

int CRandomGenerator::choice(int from, int to) {
    double range = to - from;
    int index = (CRandomGenerator::generate() *  range) + from;
    return index;
}


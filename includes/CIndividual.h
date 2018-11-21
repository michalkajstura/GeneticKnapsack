#ifndef GENETICKNAPSACK_CINDIVIDUAL_H
#define GENETICKNAPSACK_CINDIVIDUAL_H

#include <vector>
#include <utility>
#include "CRandomGenerator.h"
#include "CKnapsackProblem.h"

class CIndividual {

private:
    std::vector<bool> m_genotype;
    double m_fitness;
    CKnapsackProblem &m_knapsackProblem;
    void evaluateFitness();

public:
    CIndividual(CKnapsackProblem &knapsackProblem);
    CIndividual(CIndividual *another);
    CIndividual(std::vector<bool> genotype, CKnapsackProblem &knapsackProblem);
    double getFitness();
    void mutate(float mutProb);
    std::pair<CIndividual*, CIndividual*> cross(CIndividual *otherInd);
    bool getGeneAt(int index);
    std::vector<bool> getGenotype();
    CKnapsackProblem &getKnapsack();
};


#endif //GENETICKNAPSACK_CINDIVIDUAL_H

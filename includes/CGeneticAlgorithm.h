#ifndef GENETICKNAPSACK_CGENETICALGORITHM_H
#define GENETICKNAPSACK_CGENETICALGORITHM_H

#include <vector>
#include "CIndividual.h"

class CGeneticAlgorithm {

private:
    int m_populationNum;
    float m_crossProb, m_mutationProb;
    std::vector<CIndividual*> m_population;
    CIndividual *m_bestIndividual;
    void createRandomPopulation();
    void crossPopulation();
    void mutatePopulation();
    CIndividual* getBestIndividualPopulation();
    CIndividual* pickBetter();
    CKnapsackProblem &m_knapsackProblem;

public:
    CGeneticAlgorithm(int populationNum, float crossProb, float mutationProb, CKnapsackProblem &knapsackProblem);
    std::vector<double> run(int iterations);
    CIndividual getBestIndividual();

};


#endif //GENETICKNAPSACK_CGENETICALGORITHM_H

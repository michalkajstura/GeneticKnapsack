#include "../includes/CGeneticAlgorithm.h"

using namespace std;

CGeneticAlgorithm::CGeneticAlgorithm(int populationNum,
                                     float crossProb,
                                     float mutationProb,
                                     CKnapsackProblem& knapsackProblem) : m_knapsackProblem(knapsackProblem) {
    m_populationNum = populationNum;
    m_crossProb = crossProb;
    m_mutationProb = mutationProb;
    m_bestIndividual = NULL;
    createRandomPopulation();
}

void CGeneticAlgorithm::crossPopulation() {

    vector<CIndividual*> newPopulation;
    vector<CIndividual*> toDelete;
    while(newPopulation.size() < m_populationNum) {

        // Choose 2 pairs individuals from population and pick better individual from each pair
        CIndividual *firstParent = pickBetter();
        CIndividual *secondParent = pickBetter();

        // Cross them with probability of crossProb
        if (CRandomGenerator::generate() < m_crossProb) {
            pair<CIndividual*, CIndividual*> children = firstParent->cross(secondParent);
            newPopulation.push_back(children.first);
            newPopulation.push_back(children.second);

        } else {
            newPopulation.push_back(new CIndividual(firstParent));
            newPopulation.push_back(new CIndividual(firstParent));
        }
    }

    for (int i=0; i<m_population.size(); i++) {
        delete m_population.at(i);
    }
    m_population.clear();
    m_population = newPopulation;
}

CIndividual* CGeneticAlgorithm::pickBetter() {

    CIndividual *first = m_population.at(CRandomGenerator::choice(0, m_population.size()));
    CIndividual *second = m_population.at(CRandomGenerator::choice(0, m_population.size()));
    return (first->getFitness() > second->getFitness()) ? first : second;
}

CIndividual* CGeneticAlgorithm::getBestIndividualPopulation(){

    CIndividual *bestIndividual = NULL;

    vector<CIndividual*>::iterator iter = m_population.begin();
    for (iter; iter != m_population.end(); iter++) {
        if (bestIndividual == NULL) {
            bestIndividual = *iter;
        } else if ((*iter)->getFitness() > bestIndividual->getFitness()) {
            bestIndividual = *iter;
        }
    }

    return new CIndividual(bestIndividual);
}

CIndividual CGeneticAlgorithm::getBestIndividual() {
    return *m_bestIndividual;
}

void CGeneticAlgorithm::mutatePopulation() {

    vector<CIndividual*>::iterator iter = m_population.begin();
    for (iter; iter != m_population.end(); iter++) {
        (*iter)->mutate(m_mutationProb);
    }
}

void CGeneticAlgorithm::createRandomPopulation() {
    for (int i=0; i<m_populationNum; i++) {
        m_population.push_back(new CIndividual(m_knapsackProblem));
    }
}

vector<double> CGeneticAlgorithm::run(int iterations) {

    // List of best fitness values
    vector<double> history;

    for (int i=0; i<iterations; i++) {
//        evaluateFitnessPopulation();
        crossPopulation();
        mutatePopulation();

        // Pick the best individual from population
        CIndividual *bestIndividual = getBestIndividualPopulation();
        history.push_back(bestIndividual->getFitness());

        // Replace m_bestIndividual with best individual from current population
        // if bestIndividual is better
        if (m_bestIndividual == NULL) {
            m_bestIndividual = bestIndividual;
        } else if (bestIndividual != NULL
                   && bestIndividual->getFitness() > m_bestIndividual->getFitness()) {
            m_bestIndividual = bestIndividual;
        }
    }
    return history;
}
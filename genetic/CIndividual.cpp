#include <random>
#include "../includes/CIndividual.h"

using namespace std;

CIndividual::CIndividual(std::vector<bool> genotype,
                         CKnapsackProblem &knapsackProblem) : m_knapsackProblem(knapsackProblem) {
    m_genotype = genotype;
    evaluateFitness();
}

CIndividual::CIndividual(CIndividual *another) : m_knapsackProblem(another->getKnapsack()){
    m_genotype = another->getGenotype();
    m_fitness = another->getFitness();
}

CIndividual::CIndividual(CKnapsackProblem &knapsackProblem) : m_knapsackProblem(knapsackProblem) {
    // Generate individuals genotype randomly

    for (int i=0; i<m_knapsackProblem.getItemNum(); i++) {
        bool gene = CRandomGenerator::generate() >= 0.5;
        m_genotype.push_back(gene);
    }
    evaluateFitness();
}

void CIndividual::evaluateFitness(){
    pair<double, double> result = m_knapsackProblem.evaluateResult(m_genotype);
    double value = result.first;
    double weight = result.second;
    m_fitness = (weight <= m_knapsackProblem.getMaxWeight()) ? value : -weight;
}

void CIndividual::mutate(float mutProb) {
    for (int i=0; i<m_genotype.size(); i++) {
        bool gene = m_genotype.at(i);
        bool newGene= (CRandomGenerator::generate() <= mutProb) ? !gene : gene;
        m_genotype.at(i) = newGene;
    }

    // Update fitness
    evaluateFitness();
}

pair<CIndividual*, CIndividual*> CIndividual::cross(CIndividual *otherInd) {

    // Choose random index of cut
    int cutIndex = CRandomGenerator::choice(1, m_genotype.size());

    // Cut both genomes
    vector<bool> newInd1gen;
    vector<bool> newInd2gen;
    for (int i=0; i<m_genotype.size(); i++) {
        if (i < cutIndex) {
            newInd1gen.push_back(otherInd->getGeneAt(i));
            newInd2gen.push_back(getGeneAt(i));
        } else {
            newInd1gen.push_back(getGeneAt(i));
            newInd2gen.push_back(otherInd->getGeneAt(i));
        }
    }

    // Return two individuals created from genomes
    return pair<CIndividual*, CIndividual*>(new CIndividual(newInd1gen, m_knapsackProblem),
                                            new CIndividual(newInd2gen, m_knapsackProblem));
}

bool CIndividual::getGeneAt(int index) {
    return m_genotype.at(index);
}

double CIndividual::getFitness() {
    return m_fitness;
}

std::vector<bool> CIndividual::getGenotype() {
    return m_genotype;
}

CKnapsackProblem& CIndividual::getKnapsack() {
    return m_knapsackProblem;
}

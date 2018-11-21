#ifndef GENETICKNAPSACK_CKNAPSACKPROBLEM_H
#define GENETICKNAPSACK_CKNAPSACKPROBLEM_H

#include <utility>
#include <vector>

class CKnapsackProblem {

private:
    double **m_table;
    int m_itemNum;
    double m_maxWeight;

public:
    CKnapsackProblem(int itemNum, double maxWeight, double **table);
    std::pair<double, double> evaluateResult(std::vector<bool> genotype);
    double getMaxWeight();
    int getItemNum();
};


#endif //GENETICKNAPSACK_CKNAPSACKPROBLEM_H

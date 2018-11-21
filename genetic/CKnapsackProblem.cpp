#include "../includes/CKnapsackProblem.h"

using namespace std;

CKnapsackProblem::CKnapsackProblem(int itemNum, double maxWeight, double **table) {
    m_maxWeight = maxWeight;
    m_itemNum = itemNum;
    m_table = table;
}

pair<double, double> CKnapsackProblem::evaluateResult(vector<bool> genotype) {

    // Calculate the sum of items taken by the individual
    double resultValue = 0;
    double resultWeight = 0;
    for (int i=0; i<m_itemNum; i++) {
        if (genotype.at(i)) {
            resultValue += m_table[i][0];
            resultWeight += m_table[i][1];
        }
    }

    return pair<double, double>(resultValue, resultWeight);
}

double CKnapsackProblem::getMaxWeight() {
    return m_maxWeight;
}

int CKnapsackProblem::getItemNum() {
    return m_itemNum;
}

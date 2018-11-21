cmake_minimum_required(VERSION 3.12)
project(GeneticKnapsack)


set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticKnapsack main.cpp genetic/CIndividual.cpp includes/CIndividual.h genetic/CKnapsackProblem.cpp includes/CKnapsackProblem.h genetic/CGeneticAlgorithm.cpp includes/CGeneticAlgorithm.h utils/CRandomGenerator.cpp includes/CRandomGenerator.h)


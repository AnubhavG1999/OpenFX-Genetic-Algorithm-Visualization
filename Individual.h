#pragma once
#include<string>
#include "Genetics.h"

// The object which makes up an 'Individual' in a 'Population', consists of a
// chromosome and a fitness, both of which the individual is aware of
class Individual{

public:
	std::string chromosome;
	int fitness;
	Individual(std::string chromosome);
	Individual mate(Individual parent2);
	int cal_fitness();
};

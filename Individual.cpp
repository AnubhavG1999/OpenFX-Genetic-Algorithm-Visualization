#include "Individual.h"

//Constructor to assign the individual it's chromosome and make sure fitness is
//recalculated whenever an individual is changed
Individual::Individual(std::string chromosome)
{
	this->chromosome = chromosome;
	fitness = cal_fitness();
}

// Function toPerform mating and produce new offspring with another individual
Individual Individual::mate(Individual par2)
{
	// chromosome for offspring
	std::string child_chromosome = "";

	int len = chromosome.size();
	for (int i = 0;i<len;i++)
	{
		// random probability
		float p = Genetics::random_num(0, 100) / 100;

		// if prob is less than 0.45, insert gene
		// from parent 1
		if (p < 0.45)
			child_chromosome += chromosome[i];

		// if prob is between 0.45 and 0.90, insert
		// gene from parent 2
		else if (p < 0.90)
			child_chromosome += par2.chromosome[i];

		// otherwise insert random gene(mutate),
		// for maintaining diversity
		else
			child_chromosome += Genetics::mutated_genes();
	}

	// create new Individual(offspring) using
	// generated chromosome for offspring
	return Individual(child_chromosome);
}

// Method to calculate an individuals fitness
int Individual::cal_fitness()
{
	int len = Genetics::TARGET.size();
	int fitness = 0;
	for (int i = 0;i<len;i++)
	{
		if (chromosome[i] != Genetics::TARGET[i])
			fitness++;
	}
	return fitness;
}

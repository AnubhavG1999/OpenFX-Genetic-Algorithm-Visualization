#pragma once
#include<string>

// Class which handles the randomization and seeding for the geetic algorithm to
// work properly
class Genetics {

public:
	// Static Gene pool, target string & population size
	static  std::string GENES;
	static std::string TARGET;
	#define POPULATION_SIZE 100

	// Methods for mutation and randomization
	static int random_num(int start, int end);
	static char mutated_genes();
	static std::string create_gnome();
};

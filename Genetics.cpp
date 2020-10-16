#include "Genetics.h"

//Basically the available Gene Pool randomization, picking and choosing will be
//done with
std::string Genetics::GENES =  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP"\
"QRSTUVWXYZ 1234567890, .-;:_!\"#%&/()=?@${[]}";

// The Target Phrase to be evolved to, if left unprompted, phrase below will be
// used
std::string Genetics::TARGET = "CS126 is the best class ever";

// Basically a random number generator which'll seed a number for which gene to
// pull
int Genetics::random_num(int start, int end)
{

	int range = (end - start) + 1;
	int random_int = start + (rand() % range);
	return random_int;
}

// Create genes for random mutation out of the gene pool
char Genetics::mutated_genes()
{

	int len = GENES.size();
	int r = random_num(0, len - 1);
	return GENES[r];
}

// Create a randomized chromosome or set of genes for initial population seeding
std::string Genetics::create_gnome()
{

	int len = TARGET.size();
	std::string gnome = "";
	for (int i = 0;i<len;i++)
		gnome += mutated_genes();
	return gnome;
}

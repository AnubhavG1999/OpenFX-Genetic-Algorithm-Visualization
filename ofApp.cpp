#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    fitness_plotter.setWindowSize(2000);

	srand((unsigned)(time(0)));

	// current generation
	generation = 0;

	// current average
	average = 0;


	vector<Individual> population;
	found = false;
	creator = false;
	cout << "Enter mutation phrase here: ";
	std::getline(std::cin, Genetics::TARGET);

}

//--------------------------------------------------------------
void ofApp::update(){

	// create initial population
	while (creator == false) {
		for (int i = 0;i < POPULATION_SIZE;i++)
		{
			string gnome = Genetics::create_gnome();
			population.push_back(Individual(gnome));
		}
		creator = true;
	}

	while (!found)
	{
		// sort the population in increasing order of fitness score
		sort(population.begin(), population.end());

		// if the individual having lowest fitness score ie.
		// 0 then we know that we have reached to the target
		// and break the loop
		if (population[0].fitness <= 0)
		{	
			found = true;
			break;
		}

		// Otherwise generate new offsprings for new generation
		vector<Individual> new_generation;

		// Perform Elitism, that mean 10% of fittest population
		// goes to the next generation
		int s = ((10 * POPULATION_SIZE) / 100);
		for (int i = 0;i<s;i++)
			new_generation.push_back(population[i]);

		// From 50% of fittest population, Individuals
		// will mate to produce offspring
		s = (90 * POPULATION_SIZE) / 100;
		for (int i = 0;i<s;i++)
		{
			int len = population.size();
			int r = Genetics::random_num(0, 50);
			Individual parent1 = population[r];
			r = Genetics::random_num(0, 50);
			Individual parent2 = population[r];
			Individual offspring = parent1.mate(parent2);
			new_generation.push_back(offspring);
		}
		population = new_generation;
		cout << "Generation: " << generation << "\t";
		cout << "String: " << population[0].chromosome << "\t";
		cout << "Fitness: " << population[0].fitness << "\n";
		//Calculating averag fitness of every generation
		for (int i = 0; i < population.size(); i++) {
			average += population[i].fitness;
		}
		average = (average / POPULATION_SIZE);
		//Plotting out values 
		fitness_plotter["Average Fitness"] << (average);
		fitness_plotter["Maximum Fitness"] << population[0].fitness;
		fitness_plotter["Minimum Fitness"] << population[POPULATION_SIZE-1].fitness;
		generation++;
		return;
	}
	for (int i = 0; i < population.size(); i++) {
		average += population[i].fitness;
	}
	average = (average / POPULATION_SIZE);
	cout << "Generation: " << generation << "\t";
	cout << "String: " << population[0].chromosome << "\t";
	cout << "Fitness: " << population[0].fitness << "\n";
	fitness_plotter["Average Fitness"] << average;
	fitness_plotter["Maximum Fitness"] << population[0].fitness;
	fitness_plotter["Minimum Fitness"] << population[POPULATION_SIZE - 1].fitness;
	return;
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackgroundGradient(ofColor(255,255,255), ofColor(255,255,255));
    fitness_plotter.draw(0, 0, ofGetWidth(), ofGetHeight());

	if (population[0].fitness == 0) {
		return;
	}
}

// overloaded < operator to compare 2 individuals
bool operator<(const Individual &ind1, const Individual &ind2)
{

	return ind1.fitness < ind2.fitness;
}

# Project Proposal evolve and mutate
The Idea

I implemented a version of a genetic algorithm to formulate a random 64 byte String, and mutate and evolve it to reach a given string.
I was considering extending this project to not just have a meaningless byte string, but maybe evolve something meaningful, like a randomly generated string to form words or a combination of A's,C's,G's & T's to form an actual human genome, although computationally heavy, I believe with efficient enough implementation I could implement it for a pretty big chunk of a genome. 

Additionally I was thinking of graphically representing the variations in the genome along a standardised epoch/time period to see how it varies, with certain different implementations, i.e elitism, crossbreeding, or to sum it up, user generated initial conditions among populations and disease maybe.

The Implementation

I'd think making a GUI which allows the user to play with initial conditions would be a given along with allowing them to view how the sample changes along with epoch/time periods until it reaaches the target may be a cool way to go about it. Being one of the things I regretted implementing in the Java project, I was thinking of using ofxChart(https://github.com/fulltrend/ofxChart) an OF compatible graphing library to go about doing the graphical variation visualisation and using ofxGUI to implement the initial conditions which the user can set.

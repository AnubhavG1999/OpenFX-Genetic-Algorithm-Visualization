# Development Log

Hey! This is my development log for my CS126 project which involves implementing a genomic algorithm to generate results towards a random string and graphing the results to see if they conform to what they're supposed to look like. It's something I've been interested in doing for a while and CS126 gave me the opportunity to implement it and see it in action!

-Just to clarify:
      -src contains a proof of concept genetic algorithm implementation
      -src2 contains the ofx implementation of the genomic algorithm to plot out relative fitness


# Week 1

- Tried exporting java code to cpp for byte strings, didn't work out.
- Tried exporting java code to cpp for byte strings, didn't work out. Tried implementing a new format and going with it, but that didn't work out either.

## Week 2

- Thought up new idea replacing meaningless byte strings with words and strings. 
-  Ran into issues making implementing string methods and keeping track of fitness. 
- Added a 'Individual' class so now every individual keeps track of their own fitness whenever called, and it helps making the 'Population' vector. 
- Ran into issues working with OFX in Linux(now resolved, migrated over to Windows)
- Implemented the main method, tested the gene pool to find missing characters(apostrophe's etc).

## Week 3

- Added a static genetics class to store evolution and randomization methods.
- Experimented with mutation values to get a good balance of generations and fitness.
- Terminal implementation more or less done.
- ofxPlotter chosen instead of ofxChart due to ofxPlotter supporting multiple graphs in one window making visualization side by side easier.
- Trouble porting in ofxPlotter due to improper documentation in ofxPlotter examples.


## Week 4
- ofxPlotter up and running, decided against messing with user input in OFX since it was getting too janky in the draw and update methods.
- Graph for highest fitness implemented by sorting the 'Population' at the beginning of each epoch 
- Graph fr lowest fitness also pulled the same way
- Graph for average fitness implemented too
- Markdown changes being made to DEVELOPMENT. md


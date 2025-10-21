#ifndef GLOBAL_H
#define GLOBAL_H

#include "Level.h"
#include "Oxygen.h"

using namespace std;
using namespace ExtinctionProtocol;

// Use extern to declare the global variable
extern Level chapters[4]; // Global variable declared to store levels in sequential order
extern Oxygen oxyLevel; // Global variable declared to manage oxygen levels
extern int currLevel; // Global variable declared to manage level iteration
extern int currQuestion; // Global variable declared to manage question iteration
extern int PlayerScore; // Global variable declared to manage player's score
extern int TotalScore;
extern int LevelOneScore;
extern int LevelTwoScore;
extern int LevelThreeScore;

void loadNextLevel(); // Global method to load next level

#endif // !GLOBAL_H
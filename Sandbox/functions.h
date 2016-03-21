#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// return random number from 0 to 1
double getRand();

//  Pre Condition:	start <= end
// Post Condition:	Returns a valid integer in range [start, end]
//					Prints descriptive error messgaes
//					Removes everything from the cin buffer
//					Restores the cin object if needed
int getIntInRange(int start, int end);

#endif
#ifndef TESTS_H
#define TESTS_H

// Collection of function to test entire features, so that
// we don't have to play the game until the point the feature
// appears every time we want to test it

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~/
/ Feature testing flags:
/ "-nrt" = narration system
/ "-nav" = navigation system
/ "-min" = minigames
/ "-btl" = battle system
/~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

void testFeature(const char *flag); // checks the flag and calls the correspondent test function
void testNarration();
void testNavigation();
void testMinigames();
void testBattles();

#endif
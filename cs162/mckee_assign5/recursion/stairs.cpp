/*********************************************************************
** Program Filename: stairs.cpp
** Author: Ian McKee + Skeleton code creator (Alex or Roger probably)
** Date: 12/8/2023
** Description: Defines our ways_to_top function that was declared in .h, Has a few base cases then recurses as we have more and more stairs.
** Input: recurse.cpp, a given n we take from that input in main()
** Output: Integer in the function
*********************************************************************/

int ways_to_top(int n) {
	// YOUR CODE GOES HERE
	if (n <= 0) return 0; //base case: 0 or less means we can't count.
	if (n == 1) return 1; //base case 1: returns the first one
	if (n == 2) return 2;
	if (n == 3) {
		return 4;
	} else {
		return ways_to_top(n - 1) + ways_to_top(n - 2) + ways_to_top(n - 3);
	}
}

/*
 Author:     Sparkle , junyang.gao@gmail.com
 Date:       Mar 3, 2014
 Update:     Mar 3, 2014
 Problem:    Print all possible paths from top left to bottom right
 Difficulty: Easy
 Source:     http://www.geeksforgeeks.org/print-all-possible-paths-from-top-left-to-bottom-right-of-a-mxn-matrix/ 
 Notes:
 The problem is to print all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down.
 The algorithm is a simple recursive algorithm, from each cell first print all paths by going down and then print all paths by going right. 
 Do this recursively for each cell encountered.

 Solution: recursive.
 */

#include <stddef.h>
#include <iostream>
using namespace std;

class Solution {
public:
    /*	mat:  Pointer to the starting of mXn matrix
		i, j: Current position of the robot (For the first call use 0,0)
		m, n: Dimentions of given the matrix
		pi:   Next index to be filed in path array
		*path[0..pi-1]: The path traversed by robot till now (Array to hold the
                  path need to have space for at least m+n elements) */
	void printAllPathsUtil(int *matrix, int i, int j, int m, int n, int *path, int pi)
	{
		if ((path == nullptr) || (matrix == nullptr))
			return;


		if(i == m && j == n)
		{
			for (int k = 0; k < pi; ++k)
				cout<<path[k]<<", ";

			cout<<endl;
			return;
		}

		path[pi] = *((matrix + i*n) + j);

		if(i < m )

			printAllPathsUtil(matrix, ++i, j, m, n, path, ++pi);
		if(j < n)
			printAllPathsUtil(matrix, ++i, j, m, n, path, ++pi);
    }
	void printAllPaths(int *matrix, int m, int n)
	{
		
		int *path = new int[m+n];
		printAllPathsUtil( matrix, 0, 0, m, n, path, 0);
		delete [] path;
	}
};
// Driver program to test abve functions
int main()
{
    int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
	Solution s;
    s.printAllPaths(*mat, 2, 3);
    return 0;
}
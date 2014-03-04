/*
 Author:     Sparkle , junyang.gao@gmail.com
 Date:       Mar 3, 2014
 Update:     Mar 3, 2014
 Problem:    Count all possible paths from top left to bottom right of a mXn matrix
 Difficulty: Easy
 Source:     http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
 Notes:
 The problem is to count all the possible paths from top left to bottom right of a mXn matrix with the constraints that from each cell you can either move only to right or down

 Solution: recursive and DP
 */

#include <iostream>
#include <sstream>
#include <map>

using namespace std;

class SolutionCAPP{
public:
    int numberOfPathsRecursive(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        return numberOfPathsRecursive(m - 1, n) + numberOfPathsRecursive(m, n - 1);
    }

    map<string, int> map;  
    int numberOfPathsDP(int m, int n) {
        int sum;
        string key = std::to_string(m).append(":").append(std::to_string(n)); //key format as: m:n
        
        if(map.find(key) != map.end())
            return map[key];

        if(m == 1 || n == 1) {
            map.insert(pair<string, int>(key, 1));
            return 1;
        }
        sum = numberOfPathsDP(m - 1, n) + numberOfPathsDP(m, n - 1);
        map.insert(pair<string, int>(key, sum));
        return sum;
    }
};
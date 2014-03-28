/*Candy Total Accepted: 7961 Total Submissions: 45890 My Submissions
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?*/


#include <stddef.h>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        
        vector<int> candys;
        int num = ratings.size();
        for(int i = 0; i < num; ++i)
        {
            candys.push_back(1);
        }
        
        int preNum = candys[0];
        int preRating = ratings[0];
        
        for(int i = 1; i < num; ++i)
        {
            if(ratings[i] > preRating)
                candys[i] = preNum + 1;
            
            preNum = candys[i];
            preRating = ratings[i];
        }

        preRating = ratings[num - 1];
        preNum = candys[num - 1];
        int sum = candys[num - 1];

        for(int i = num - 2; i >= 0; --i)
        {
            if(ratings[i] > preRating)
                candys[i] = max((preNum + 1), candys[i]);
            
            preNum = candys[i];
            preRating = ratings[i];

            sum += candys[i];
        }
        return sum;
    }
};
/*
Given coins with values 1, 3, and 5.
And the sum S is set to be 11.
for example: coins = {1, 2, 5, 10, 21, 25}
get the minimal coins for sum of 63
the result should be 3;

@para Vector a : 硬币的面额， S：要计算的总和。 
@return : 最少需要的硬币数
int static int MinCoinNumbers(Vector<Integer> a, S){

}*/
#include <vector>
#include <algorithm>
using namespace std;


class MinCoins
{
public:
    int MinCoinNumbers(vector<int> a,int S){
        int res[100];
        for (int i = 0; i < 100; i++)
            res[i] = 0;
        
        sort(a.begin(), a.end());

        for (int i = 1; i <= S; i++)
        {
            int minCoins = i/a[0];
            for (int j = a.size() - 1; j >= 0; j--)
            {
                if(i >= a[j])
                {
                    minCoins = min(res[i - a[j]] + 1, minCoins);
                }
            }
            res[i] = minCoins;
        }
        return res[S];
    }
};

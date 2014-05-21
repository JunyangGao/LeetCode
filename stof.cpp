#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//simulate the stof() method

double _stof(string s){
    double res = 0;
    if(s.length() > 0)
    {
        int round = -1;
        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '.' )
                round = 0;
            
            if(s[i] < '0' || s[i] >'9')
                continue;

            if(round > -1)
                round++;

            res = res*10 + s[i] - '0';
        }
        if(round > -1)
            res = res/pow(10, round);      
    }
    return res;
}
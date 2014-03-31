//Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given:
//start = "hit"
//    end = "cog"
//    dict = ["hot","dot","dog","lot","log"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//    return its length 5.
//
//Note:
//Return 0 if there is no such transformation sequence.
//    All words have the same length.
//    All words contain only lowercase alphabetic characters.
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.size() == 0)
            return 0;
        
        queue<pair<string, int>> q;
        q.push(make_pair(start, 1));
        dict.erase(start);

        while(!q.empty())
        {
            pair<string, int> before = q.front();
            q.pop();
            string word = before.first;
            for (size_t i = 0; i < word.size(); ++i)
            {
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    word[i] = c;
                    if (word == end)
                        return before.second + 1;
                    
                    if (dict.find(word) != dict.end())
                    {
                        q.push(make_pair(word, before.second+1));
                        dict.erase(word);
                    }
                }
                word = before.first;
            }
        }       
        return 0;
    }
};
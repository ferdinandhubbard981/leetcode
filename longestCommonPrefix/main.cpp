#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findShortestStringLen(vector<string> strs) {
        int shortest = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            int len = strs[i].size();
            shortest = (len < shortest) ? len : shortest;
        }
        return shortest;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string output = "";
        bool inPrefix = true;
        int shortestStringLen = findShortestStringLen(strs);
        for (int i = 0; i < shortestStringLen && inPrefix; i++) {
            char current = strs[0][0];
            for (int j = 0; j < strs.size() && inPrefix; i++) {
                if (strs[j][i] != current) inPrefix = false;
            }
            if (inPrefix) output += current;
        }
        return output;
    }
};


/*int main () {


    return 0;
}*/
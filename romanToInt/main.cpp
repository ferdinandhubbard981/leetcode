#include <bits/stdc++.h>
using namespace std;
    


class Solution {
public:
    
    int romanToInt(string s) {
        int output = 0;
        map<char, int> romanDigits = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

        for (int i = 0; i < s.size()-1; i++) {
            int current = romanDigits[s[i]];
            int next = romanDigits[s[i+1]];
            if (current < next) {
                output -= current;
            }
            else {
                output += current;
            }
        }
        output += romanDigits[s[s.size()-1]];
        return output;
    }
};

int main() {


    return 0;
}
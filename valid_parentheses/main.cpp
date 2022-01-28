#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool output = true;
        unordered_map<char, int> parenthesesMap;
        parenthesesMap[')'] = -1;
        parenthesesMap[']'] = -2;
        parenthesesMap['}'] = -3;
        parenthesesMap['('] = 1;
        parenthesesMap['['] = 2;
        parenthesesMap['{'] = 3;

        vector<int> buffer;
        for (int i = 0; i < s.size() && output; i++) {
            if (parenthesesMap[s[i]] > 0) buffer.push_back(parenthesesMap[s[i]]);
            else if (buffer.size() > 0) {
                if (buffer.back() == parenthesesMap[s[i]] * -1) buffer.erase(buffer.end()-1);
                else output = false;
            }
            else output = false;
        }
        if (buffer.size() != 0) output = false;
        
        return output;
    }
};

int main() {
    string input = ")";
    Solution instance;
    cout << "output: " << instance.isValid(input) << endl;
    return 0;
}
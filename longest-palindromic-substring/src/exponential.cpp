#include <string>
#include <iostream>
using namespace std;

// time comlexity:
// longest Palindrome branches into two function calls for each charcter in the string (except last one).
// therefore, it's time complexity is exponential, 2^n.
// we might be able to improve this using a hashmap
class Solution {
public:
    string longestPalindrome(string s) {
        if (isPalindrome(s)) return s;
        // else
        string noFirstChar = s.substr(1);
        string noLastChar = s.substr(0, s.size()-1);

        noFirstChar = longestPalindrome(noFirstChar);
        noLastChar = longestPalindrome(noLastChar);
        if (noFirstChar.size() > noLastChar.size()) return noFirstChar;
        return noLastChar;
    }

    bool isPalindrome(string s) {
        for (size_t i = 0; i < (s.size()/2); i++) {
            if (s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    }
};

int main() {
    string input = "babaddtattarrattatddetartrateedredividerb";
    cout << "input size: " << input.size() << endl;
    Solution s;
    string output = s.longestPalindrome(input);
    cout << "output: " << output << endl;
}
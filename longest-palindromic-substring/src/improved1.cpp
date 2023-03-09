#include <string>
#include <iostream>
using namespace std;

// time comlexity:
class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindromeRec(s, 0, 0);
    }

    string longestPalindromeRec(string s, u_int leftIndex, u_int rightIndex) {
        if (rightIndex == (s.size()-1)) return s.substr(leftIndex, rightIndex-leftIndex+1);
        if (isPalindrome(s)) {
            // The only option that could result in a longer palindrome is to increment rightIndex by 1
            return (longestPalindromeRec(s, leftIndex, rightIndex+1));
        }
        // otherwise we have two options:
            // increment rightIndex by 1
            // or increment leftIndex by 1
        string left = longestPalindromeRec(s, leftIndex+1, rightIndex);
        string right = longestPalindromeRec(s, leftIndex, rightIndex+1);
        if (left.size() > right.size()) return left;
        return right;
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
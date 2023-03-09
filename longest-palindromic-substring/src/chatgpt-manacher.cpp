#include <string>
#include <iostream>
#include <vector>
using namespace std;

// time comlexity:
// longest Palindrome branches into two function calls for each charcter in the string (except last one).
// therefore, it's time complexity is exponential, 2^n.
// we might be able to improve this using a hashmap
class Solution {
public:
    string longestPalindrome(string s) {
        // preprocess the string
        string str = "#";
        for (char c : s) {
            str += c;
            str += "#";
        }

        int n = (int) str.size();
        vector<int> p(n);

        // center and right bound of the palindrome with the rightmost endpoint
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; i++) {
            // mirror index of i with respect to the center
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            // expand the palindrome around i
            while (str[i + p[i] + 1] == str[i - p[i] - 1])
                p[i]++;

            // update the center and right bound
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        // find the longest palindrome substring
        int max_len = 0, center_idx = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > max_len) {
                max_len = p[i];
                center_idx = i;
            }
        }

        int start = (center_idx - max_len) / 2;
        return s.substr(start, max_len);
    }
};

int main() {
    string input = "babaddtattarrattatddetartrateedredividerb";
    cout << "input size: " << input.size() << endl;
    Solution s;
    string output = s.longestPalindrome(input);
    cout << "output: " << output << endl;
}
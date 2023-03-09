// complexity:
// O(n + numRows)


#include <string>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows);
        int loopIndex = 0;
        string::iterator it = s.begin();
        while (it != s.end()) {
            if (loopIndex == 0) {
                // fill column with characters
                while (loopIndex < numRows) {
                    rows[loopIndex++].push_back(*(it++));
                    if (it == s.end()) break;
                    
                }
                loopIndex--;
            }
            else if (loopIndex == numRows-1) loopIndex -= 1;

            else {
                rows[loopIndex--].push_back(*(it++));
            }

        }
        string output = std::accumulate(rows.begin(), rows.end(), string{}, 
            [](const string& a, const string& b) {
                return a + b;
            });
        return output;
    }
};

int main() {
    Solution s;
    string input = "AB";
    int numRows = 2;
    string output = s.convert(input, numRows);
    cout << output << endl;
}
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getNumOfDigits(int x) {
        long modResult = 0;
        int numOfDigits = -1;
        while (modResult < x) {
            numOfDigits++;
            modResult = x % (long)pow(10, numOfDigits);
        }
        return numOfDigits;
    }

    int getDigit(int x, int index) { //index starting at 0
        return (int)(x / pow(10, index)) % 10;
    }
    bool isPalindrome(int x) {
        bool output = true;
        if (x < 0) output = false;
        int numOfDigits = getNumOfDigits(x);
        int digitsRemoved = 0;
        while (output && (numOfDigits - digitsRemoved > 1)) {
            int leftDigit = getDigit(x, numOfDigits-(digitsRemoved/2)-1);
            int rightDigit = getDigit(x, digitsRemoved/2);
            if (leftDigit != rightDigit) output = false;
            digitsRemoved += 2;
        }
        return output;
    }
};

int main() {
    Solution instance;
    int input = 1234567899;
    bool isPalindrome = instance.isPalindrome(input);
    if (isPalindrome) cout << input << " is a palindrome" << endl;
    else cout << input << " is not a palindrome" << endl;
    return 0;
}
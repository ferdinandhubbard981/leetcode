#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOver = 0;
        if (!l1) l1 = new ListNode();
        ListNode* initial = l1; 
        while (l2 || carryOver) {
            operation(l1, l2, carryOver);
            l1 = l1-> next;
            if (l2) l2 = l2->next;
        }

        return initial;
    }

    void operation(ListNode* l1, ListNode* l2, int& carryOver) {
        int val, l2Val;
        if (!l1) l1 = new ListNode();
        l2Val = (l2) ? l2->val : 0;
        val = l1->val + l2Val + carryOver;
        carryOver = val / 10;
        val = val % 10;
        l1->val = val;
    }

    ListNode* generateList(int num) {
        ListNode* curr = new ListNode();
        ListNode* initial = curr;
        int digit = 1;
        while (num != 0) {
            int val = num % power(10, digit++);
            num -= val;
            curr->val = val;
            curr->next = new ListNode();
        }
        curr->next = nullptr;
        return initial;
    }

    int power(int base, int exponent) {
        int result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;
    }
};

int main() {
    Solution s;
    int num1 = 223, num2 = 334;
    ListNode *l1 = s.generateList(num1), *l2 = s.generateList(num2);
    ListNode output = s.addTwoNumbers(l1, l2)
}

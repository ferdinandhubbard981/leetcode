struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        else if (!list2) {
            return list1;
        }
        ListNode* output = list1;

        if (list1->val > list2->val) {
            output = list2;
            list2 = list2->next;
        }
        else {
            list1 = list1->next;
        }
        ListNode* curr = output;

        while (list1 && list2) {

            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next
        }
        if (list1) {
            curr->next = list1;
        }
        else {
            curr->next = list2;
        }
        return output;        
    }
};


int main() {
    // 1, 2, 3
    // 1, 1, 5
    Solution s;

    return 0;
}
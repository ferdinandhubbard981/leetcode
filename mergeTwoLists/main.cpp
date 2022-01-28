#include <bits/stdc++.h>

using namespace std;



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
        //2, 3, 4
        //1, 2, 5
        ListNode* mergedList;
        ListNode** iterator = &mergedList;
        while (list1 != nullptr || list2 != nullptr) {
            ListNode* newNode = new ListNode();
            if (list2 != nullptr && list1->val > list2->val) {
                newNode->val = list2->val;
            }
            else {
                newNode->val = list1->val;
            }
            *iterator = newNode;
            *iterator = (*iterator)->next;
        }
        return mergedList;
    }
};

ListNode* makeListNode(vector<int> list) {
    ListNode* output;
    ListNode** iterator = &output;
    for (int i = 0; i < list.size(); i++) {
        ListNode* newNode = new ListNode(list[i]);
        *iterator = newNode;
        *iterator = (*iterator)->next;
    }   
    return output; 
}
int main() {
    vector<int> listone = {1,2,4};
    vector<int> listtwo = {1,3,4};
    ListNode* one = makeListNode(listone);
    ListNode* two = makeListNode(listtwo);
    Solution instance;
    ListNode* output = instance.mergeTwoLists(one, two);
    cout << "done" << endl;
    return 0;
}
//**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode() : val(0), next(nullptr) {}
// *     ListNode(int x) : val(x), next(nullptr) {}
// *     ListNode(int x, ListNode *next) : val(x), next(next) {}
// * };
// */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        
        for (ListNode* curList : lists) {
            ListNode* cur = curList;

            while (cur) {
                ListNode* nextNode = cur->next;

                ListNode* prev = &dummy;
                ListNode* node = dummy.next;

                while (node && node->val <= cur->val) {
                    prev = node;
                    node = node->next;
                }

                prev->next = cur;
                cur->next = node;

                cur = nextNode;
            }
        }

        return dummy.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        int n = 0;
        ListNode* node = head;
        while (node) {
            node = node->next;
            ++n;
        }

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;  
        ListNode* groupStart = head;      

        while (n >= k) {
            ListNode* prev = nullptr;
            ListNode* curr = groupStart;

            for (int i = 0; i < k; ++i) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            prevGroupEnd->next = prev;
            groupStart->next = curr;

            prevGroupEnd = groupStart;
            groupStart = curr;

            n -= k;
        }

        return dummy.next;
    }
};

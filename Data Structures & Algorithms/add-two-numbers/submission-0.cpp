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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x, y;
        x = y = 0;
        int p = 1;
        while(l1) 
        {
            x+=(l1->val)*p;
            l1 = l1->next;
            p*=10;
        }
        p = 1;
        while(l2) 
        {
            y+=(l2->val)*p;
            l2 = l2->next;
            p*=10;
        }
        int res = x+y;
        cout << res << '\n';
        ListNode* ans = new ListNode(res%10);
        ListNode* cur = ans;
        res/=10;
        while(res!=0)
        {
            ListNode* copy = new ListNode(res%10);
            cur->next = copy;
            res/=10;
            cur = cur->next;
        }

        return ans;
    }
};

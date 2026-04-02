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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode dummy(head->val, head->next);
        ListNode* node = &dummy;
        while(node->next!=nullptr)
        {
            v.push_back(node->val);
            node = node->next;
        }
        v.push_back(node->val);
        vector<int> vec;
        int i = 0, j = v.size()-1;
        while(i <= j)
        {
            if(i == j) {vec.push_back(v[i]); break;}
            vec.push_back(v[i]);
            vec.push_back(v[j]);
            ++i,--j;
        }
        i = 0;
        for(int x : vec) cout << x << ' ';
        while(head->next != nullptr)
        {
            head->val = vec[i];
            head = head->next;
            ++i;
        }
        head->val = vec[i];
    }
};

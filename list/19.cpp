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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)
            return nullptr;
        ListNode* n_slow = head;
        ListNode* n_quick = head;
        // 因为n_quick先走了n_slow步，所以n_quick走到null的时候，n_slow的前一个正好就是需要删除的pointer
        for(int i = 0; i < n; i++)
        {
            n_quick = n_quick->next;
        }
        if(!n_quick)
        {
            return head->next;
        }
        ListNode* tmp = n_slow;
        while(n_quick)
        {
            n_quick = n_quick->next;
            tmp = n_slow;
            n_slow = n_slow->next;
        }
        tmp->next = n_slow->next;//这个变量其实也可以不需要
        return head;
    }
};
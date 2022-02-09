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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* curr = head->next;
        ListNode* res = head;
        int tmp = head->val;
        while(curr) {
        //需要next来保存下一个的节点。需要curr来维持循环。需要res来保存头节点
            ListNode* next = curr->next;
            if(tmp != curr->val) {
                tmp = curr->val;
                head->next = curr;
                head = head->next;
            }
            curr = next;
        }
        head->next = nullptr;
        return res;
        
    }
};
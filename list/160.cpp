/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        if(lenA > lenB) {
            for(int i = 0; i < (lenA - lenB); i++)
                headA = headA->next;
        } else {
            for(int i = 0; i < (lenB - lenA); i++)
                headB = headB->next;
        }
        while(headA || headB) {
            if(headA == headB)
                break;
            headA = headA->next;
            headB = headB->next;
        }
        return (headA && headB) ? headA: NULL;
    }
    
    int getLength(ListNode *head) {
        int cnt = 0;
        while(head) {
            head = head->next;
            cnt++;
        }
        return cnt;
    }
};
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
    ListNode* reverseList(ListNode* head) {
        //需要3个临时变量。一个保存当前的指针，一个保存结果(前一个指针)，一个保存next指针
        //把curr 的next变成了前面，然后赋值给了prev.在链表的时候我们需要保留curr这个结构，然后对这个
        //结构做更改。并将改后的结果给result.
        ListNode* prev = nullptr;
        ListNode* next;
        ListNode* curr = head;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        return prev;
    }
};

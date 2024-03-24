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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode*temp = head;
        ListNode*temp1 = temp;
        ListNode*temp2 = head->next;
        ListNode*temp3 = temp2;
        while(temp1->next && temp1->next->next) {
            ListNode*a = temp1->next->next;
            temp2 = temp1->next;
            temp1->next = a;
            temp2->next = a->next;
            temp1 = a;
            temp2 = a->next;
        }
        temp1->next = temp3; 
        return head;
    }
};
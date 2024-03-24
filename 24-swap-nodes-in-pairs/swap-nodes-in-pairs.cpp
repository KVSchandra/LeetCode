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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode*temp = head;
        ListNode*temp1 = head->next;
        ListNode*head1 = temp1;
        ListNode*forward = NULL;
        while(temp1 && temp) {
            forward = temp1->next;
            temp1->next = temp;
            if(forward && forward->next) temp->next = forward->next;
            else temp->next = forward;
            temp = forward;
            if(temp) temp1 = temp->next;
            else temp1 = NULL;
        }
        return head1;
    }
};
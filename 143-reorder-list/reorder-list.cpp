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
        ListNode*slow = head;
        ListNode*fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*prev = NULL;
        ListNode*forward = NULL;
        ListNode*curr = slow->next;
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        slow->next = NULL; // IMPORTANT
        ListNode*temp = head;
        while(temp && prev) {
            ListNode*a = temp->next;
            ListNode*b = prev->next;
            temp->next = prev;
            prev->next = a;
            prev = b;
            temp = a;
        }
    }
};
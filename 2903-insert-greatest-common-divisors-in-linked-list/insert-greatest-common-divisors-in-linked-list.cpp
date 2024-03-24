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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode*temp = head;
        ListNode*forward = NULL;
        while(temp->next) {
            forward = temp->next;
            int a = __gcd(temp->val, forward->val);
            ListNode*g = new ListNode(a);
            temp->next = g;
            g->next = forward;
            temp = forward;
        }
        return head;
    }
};
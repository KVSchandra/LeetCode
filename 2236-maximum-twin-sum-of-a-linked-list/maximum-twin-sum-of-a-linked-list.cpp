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
    int pairSum(ListNode* head) {
        ListNode*slow = head;
        ListNode*fast = head->next;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode*temp = slow->next;
        slow->next = NULL;
        ListNode*curr = temp;
        ListNode*prev = NULL;
        ListNode*forward = NULL;
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        int maxi = INT_MIN;
        while(head && prev) {
            maxi = max(head->val + prev->val, maxi);
            prev = prev->next;
            head = head->next;
        }
        return maxi;
    }
};
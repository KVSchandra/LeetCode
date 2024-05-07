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
    ListNode*rev(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode*prev = NULL;
        ListNode*curr = head;
        ListNode*forward = NULL;
        while(curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode*head1 = rev(head);
        ListNode*head2 = head1;
        ListNode*temp = head1;
        int carry = 0;
        while(temp && head2) {
            int a = (temp->val + head2->val + carry);
            temp->val = a%10;
            a/=10;
            carry = a;
            temp = temp->next;
            head2 = head2->next;
        }
        ListNode*t = head1;
        while(t->next) {
            t = t->next;
        }
        if(carry) {
            t->next = new ListNode(carry);
        }
        ListNode*ans = rev(head1);
        return ans;
    }
};
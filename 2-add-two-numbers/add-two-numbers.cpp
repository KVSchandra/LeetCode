class Solution {
public:
    ListNode* rev(ListNode* head) { 
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        while (curr) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode*prev1 = (l1);
        ListNode*prev2 = (l2);
        
        ListNode*head1 = NULL;
        ListNode*temp1 = head1;
        int sum = 0;
        while(prev1 || prev2 || sum) {
            if(prev1){
                sum += prev1->val;
                prev1 = prev1->next;
            }
            if(prev2){
                sum += prev2->val;
                prev2 = prev2->next;
            }
            if(!head1){
                head1 = new ListNode(sum % 10);
                temp1 = head1;
            } 
            else{
                temp1->next = new ListNode(sum % 10);
                temp1 = temp1->next;
            }
            sum /= 10;
        }
        return (head1);
    }
};

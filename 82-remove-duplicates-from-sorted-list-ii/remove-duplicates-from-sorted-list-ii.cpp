class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head1 = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            if(curr->next && curr->val == curr->next->val) {
                while(curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                curr = curr->next;
            } 
            else {
                ListNode*a = new ListNode(curr->val);
                if(!head1){
                    head1 = a;
                    prev = head1;
                } 
                else{
                    prev->next = a;
                    prev = prev->next;
                }
                curr = curr->next;
            }
        }
        return head1;
    }
};

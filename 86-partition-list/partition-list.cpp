class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        ListNode* temp1 = NULL; 
        ListNode* head1 = temp1; 
        ListNode* temp2 = NULL;
        ListNode* head2 = temp2;
        while(temp) {
            if(temp->val < x) {
                if(!temp1){ 
                    temp1 = temp;
                    head1 = temp1; 
                } 
                else{
                    temp1->next = temp;
                    temp1 = temp1->next; 
                }
            } 
            else {
                if(!temp2){ 
                    temp2 = temp;
                    head2 = temp2; 
                } 
                else{
                    temp2->next = temp;
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
        if(temp1) temp1->next = head2;
        if(temp2) temp2->next = nullptr;
        if(temp1 == NULL) return head2;
        return head1; 
    }
};

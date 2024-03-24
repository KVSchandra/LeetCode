class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* head1 = NULL;
        ListNode* temp1 = head1;
        ListNode* temp = head;
        int sum = 0;
        while(temp->next){
            if(temp->val > 0){
                sum += temp->val;
                if(temp->next->val == 0){
                    ListNode* a = new ListNode(sum);
                    if(head1 == NULL){
                        head1 = a;
                        temp1 = head1;
                    } 
                    else{
                        temp1->next = a;
                        temp1 = temp1->next;
                    }
                    sum = 0;
                }
            }
            temp = temp->next;
        }
        return head1;
    } 
};

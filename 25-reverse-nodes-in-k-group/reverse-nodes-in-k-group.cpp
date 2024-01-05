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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL ) return head;
        //Length
        ListNode*temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        if(len < k) return head;
        //Reversing first k node
        int count = 0;
        ListNode* forward = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr && count < k){
            count++;
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward; 
        }
        //recursive calls;
        if(forward != NULL){
           head->next = reverseKGroup(forward, k);
        }
        return prev;

    }
};
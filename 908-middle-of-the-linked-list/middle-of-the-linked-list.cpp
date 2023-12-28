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
    ListNode* middleNode(ListNode* head) {
        vector<int>v;
        ListNode*temp = head;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int count = 0;
        while(head){
            if(count == (v.size()/2) ) break;
            count++;
            head = head->next;
        }
        return head;

    }
};
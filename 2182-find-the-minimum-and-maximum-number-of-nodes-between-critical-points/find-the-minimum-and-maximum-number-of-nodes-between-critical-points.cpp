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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev = head;
        ListNode*curr = head->next;
        ListNode*forward = head->next->next;
        int count = 1;
        vector<int>v;
        while(forward) {
            if((prev->val > curr->val && curr->val < forward->val) || (prev->val < curr->val && curr->val > forward->val)) {
                v.push_back(count);
            }
            prev = curr;
            curr = forward;
            forward = forward->next;
            count++;
        }
        int mini = INT_MAX, maxi = -1;
        if(v.size() >= 2){
            for(int i = 0; i<v.size()-1; i++) {
                mini = min(mini, abs(v[i] - v[i+1]));
            }
            maxi = v[v.size()-1] - v[0];
        }
        if(mini == INT_MAX) mini = -1;
        return {mini, maxi};
    }
};
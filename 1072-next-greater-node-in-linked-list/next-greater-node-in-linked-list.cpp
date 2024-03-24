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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        while(head) {
            ListNode*temp = head;
            int maxi = temp->val;
            bool flag = false;
            while(temp) {
                if(temp->val > maxi) {
                    flag = true;
                    ans.push_back(temp->val);
                    break;
                }
                temp = temp->next;
            }
            if(flag == false) ans.push_back(0);
            head = head->next;
        }
        return ans;
    }
};
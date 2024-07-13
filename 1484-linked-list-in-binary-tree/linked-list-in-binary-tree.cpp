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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, ListNode* temp) {
        if(temp->next == NULL) return true;
        if(root == NULL) return false;
        bool left = false, right = false;
        if(root->left && root->left->val == temp->next->val) {
            left = check(root->left, temp->next);
        }
        if(root->right && root->right->val == temp->next->val) {
            right = check(root->right, temp->next);
        }
        return left | right;
    }

    bool solve(TreeNode* root, ListNode* head) {
        if(root == NULL) return false;
        if(root->val == head->val) {
            if(check(root, head)) {
                return true;
            }
        }
        bool left = solve(root->left, head);
        bool right = solve(root->right, head);
        return left | right;
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        return solve(root, head);
    }
};
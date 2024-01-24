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
    void checkTree(TreeNode* root,unordered_map<int,int> freq,int &cnt)
    {
        if(root ->left == NULL && root->right == NULL)
        {
            freq[root->val]++;
            int oddCnt=0;
            for(auto it:freq)
            {
                if((it.second)%2==1){oddCnt++;}
            }
            if(oddCnt == 1 || oddCnt == 0){cnt++;}
            freq.clear();
            return;
        }
        freq[root->val]++;
        if(root->left) checkTree(root->left,freq,cnt);
        if(root->right) checkTree(root->right,freq,cnt);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> freq;
        int cnt=0;
        checkTree(root,freq,cnt);
        return cnt;
    }
};
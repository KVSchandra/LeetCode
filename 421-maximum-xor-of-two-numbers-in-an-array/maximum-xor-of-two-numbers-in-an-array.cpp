class TrieNode {
public:
    bool endOfNum;
    vector<TrieNode*>children;

    TrieNode() {
        endOfNum = false;
        children.resize(2, NULL);
    }
};

class Trie {
private:
    TrieNode*root = new TrieNode();
public:
    void insert(int num) {
        TrieNode*curr = root;
        for(int i = 31; i>=0; i--) {
            int bit = ((num >> i) & 1);
            if(!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
        curr->endOfNum = true;
    }

    int getMax(int num) {
        int maxNum = 0;
        TrieNode*curr = root;
        for(int i = 31; i>=0; i--) {
            int bit = ((num >> i) & 1);
            if(curr->children[1-bit] != NULL) {
                maxNum |= (1 << i);
                curr = curr->children[!bit];
            }
            else curr = curr->children[bit];
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxi = INT_MIN;
        for(auto val : nums) {
            trie.insert(val);
        }
        for(auto val : nums) {
            maxi = max(maxi, trie.getMax(val));
        }
        return maxi;
    }
};
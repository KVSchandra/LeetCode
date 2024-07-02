class TrieNode {
public:
    bool endOfWord;
    vector<TrieNode*> children;

    TrieNode() {
        endOfWord = false;
        children.resize(26, NULL);
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    void insert(string s) {
        TrieNode* curr = root;
        for(auto val : s) {
            if(!curr->children[val-'a']) {
                curr->children[val-'a'] = new TrieNode();
            }
            curr = curr->children[val-'a'];
        }
        curr->endOfWord = true;
    }
};

bool solve(int i, int count, string &s, TrieNode* root, vector<vector<int>>& dp) {
    if(i == s.size()) {
        return count >= 2;
    }
    
    if(dp[i][count] != -1) {
        return dp[i][count];
    }
    
    TrieNode* curr = root;
    for(int j = i; j < s.size(); j++) {
        if(curr->children[s[j] - 'a'] == NULL) {
            return dp[i][count] = false;
        }
        curr = curr->children[s[j]-'a'];
        if(curr->endOfWord) {
            if(solve(j+1, count+1, s, root, dp)) {
                return dp[i][count] = true;
            }
        }
    }
    return dp[i][count] = false;
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;
        for(auto val : words) {
            if(!val.empty()) trie.insert(val);
        }
        vector<string> ans;
        for(auto& val : words) {
            if(!val.empty()) {
                vector<vector<int>> dp(val.size(), vector<int>(val.size(), -1));
                if(solve(0, 0, val, trie.root, dp)) {
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};
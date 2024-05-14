class TrieNode {
public:
    bool endOfWord;
    vector<TrieNode*>children;

    TrieNode() {
        endOfWord = false;
        children.resize(26, NULL);
    }
};

class Trie {
public:
    TrieNode*root = new TrieNode();
public:
    void insert(string s) {
        TrieNode*curr = root;
        for(auto val : s) {
            if(!curr->children[val-'a']) {
                curr->children[val-'a'] = new TrieNode();
            }
            curr = curr->children[val-'a'];
        }
        curr->endOfWord = true;
    }

    bool search(string s, int &a) {
        TrieNode*curr = root;
        int b = 0;
        for(auto val : s) {
            if(curr->children[val-'a']) {
                curr = curr->children[val-'a'];
                b++;
            }
            else return false;
            if(curr->endOfWord) {a = b; return true;}
        }
        return false;
    }

};

class Solution {
public:
    Trie trie;
    int solve(int i, string &s, vector<string>&dictionary, vector<int>&dp) {
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = INT_MAX;
        TrieNode*curr = trie.root;
        for(int j = i; j<s.size(); j++) {
            if(curr->children[s[j]-'a']) {
                curr = curr->children[s[j]-'a'];
            }
            else break;
            if(curr->endOfWord) {
                pick = min(pick, solve(j+1, s, dictionary, dp));
            }
        }
        int notPick = 1 + solve(i+1, s, dictionary, dp);
        return dp[i] = min(pick, notPick);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto val : dictionary) {
            trie.insert(val);
        }
        vector<int>dp(s.size(), -1);
        return solve(0, s, dictionary, dp);
    }
};
class TrieNode{
public:
    bool endOfWord;
    vector<TrieNode*>children;
    int prefix;
    TrieNode() {
        endOfWord = false;
        children.resize(26, NULL);
        prefix = 0;
    }
};

class Trie {
private:
    TrieNode*root = new TrieNode();
public:
    void insert(string word) {
        TrieNode*curr = root;
        for(auto val : word) {
            if(!curr->children[val-'a']) {
                curr->children[val-'a'] = new TrieNode();
                curr->prefix++;
            }
            curr = curr->children[val-'a'];
        }
        curr->endOfWord = true;
    }

    void lcp(string s, string &ans) {
        TrieNode*curr = root;
        for(auto val : s) {
            if(curr->prefix == 1) {
                ans.push_back(val);
                curr = curr->children[val-'a'];
            }
            else break;
            if(curr->endOfWord) break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        for(auto val : strs) {
            trie.insert(val);
            if(val == "") return "";
        }
        string ans = "";
        trie.lcp(strs[0], ans);
        return ans;
    }
};
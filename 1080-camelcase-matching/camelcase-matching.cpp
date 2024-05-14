class TrieNode{
public:
    bool endOfWord;
    vector<TrieNode*>children;

    TrieNode() {
        endOfWord = false;
        children.resize(200, NULL);
    }
};

class Trie {
private:
    TrieNode*root = new TrieNode();
public:
    void insert(string word) {
        TrieNode*curr = root;
        for(auto val : word) {
            if(!curr->children[val-'A']) {
                curr->children[val-'A'] = new TrieNode();
            }
            curr = curr->children[val-'A'];
        }
        curr->endOfWord = true;
    }

    bool search(string s) {
        TrieNode*curr = root;
        for(auto val : s) {
            if(curr->children[val-'A']) {
                curr = curr->children[val-'A'];
            }
            else if(isupper(val)) return false;
        }
        return curr->endOfWord;
    }

};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie trie;
        vector<bool>ans;
        trie.insert(pattern);
        for(auto val : queries) {
            ans.push_back(trie.search(val));
        }
        return ans;
    }
};
class TrieNode {
public:
    bool endOfWord;
    TrieNode* children[26] = {NULL};
    int ind;
    int len;

    TrieNode() {
        endOfWord = false;
        ind = INT_MAX;
        len = INT_MAX;
    }
};

class Trie{
public:
    TrieNode*root = new TrieNode();
public:
    void insert(string word, int i) {
        TrieNode*curr = root;
        for(auto val : word) {
            if(!curr->children[val-'a']) {
                curr->children[val-'a'] = new TrieNode();
            }
            if(word.size() < curr->children[val-'a']->len) {
                curr->children[val-'a']->len = word.size();
                curr->children[val-'a']->ind = i;
            }
            curr = curr->children[val-'a'];
        }
        curr->endOfWord = true;
    }

    int search(string &word) {
        TrieNode*curr = root;
        for(auto val : word) {
            if(!curr->children[val-'a']) return curr->ind;
            curr = curr->children[val-'a'];
        }
        return curr->ind;
    }

};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int>ans(wordsQuery.size(), -1);
        Trie trie;
        int mini = INT_MAX;
        int index = -1;
        for(int i = 0; i<wordsContainer.size(); i++) {
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            if(wordsContainer[i].size() < mini) {
                mini = wordsContainer[i].size();
                index = i;
            }
            trie.insert(wordsContainer[i], i);
        }
        for(int i = 0; i<wordsQuery.size(); i++) {
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());
            int a = trie.search(wordsQuery[i]);
            if(a != INT_MAX) ans[i] = a;
            else ans[i] = index;
        }
        return ans;
    }
};
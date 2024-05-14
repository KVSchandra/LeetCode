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
    private:
        TrieNode*root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {
            TrieNode*curr = root;
            for(auto val : word) {
                if(!curr->children[val-'a']) {
                    curr->children[val-'a'] = new TrieNode();
                }
                curr = curr->children[val-'a'];
            } 
            curr->endOfWord = true;
        }

        bool search(string word) {
            TrieNode*curr = root;
            for(auto val : word) {
                curr = curr->children[val-'a'];
                if(!curr) return false;
            }
            return curr->endOfWord;
        }

        bool startsWith(string prefix) {
            TrieNode*curr = root;
            for(int i = 0; i<prefix.size(); i++) {
                curr = curr->children[prefix[i] - 'a'];
                if(curr == NULL) return false;
            }
            return true;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
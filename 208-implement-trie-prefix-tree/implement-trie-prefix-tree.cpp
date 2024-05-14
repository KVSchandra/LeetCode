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
        TrieNode*root = new TrieNode();;
    public:
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
            for(auto val : prefix) {
                curr = curr->children[val-'a'];
                if(!curr) return false;
            }
            return true;
        }

};
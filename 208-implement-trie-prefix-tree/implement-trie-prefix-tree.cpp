class TrieNode {
public:
    bool endOfWord;
    int countEnd;
    int countPrefix;
    vector<TrieNode*> children;

    TrieNode() {
        endOfWord = false;
        countEnd = 0;
        countPrefix = 0;
        children.resize(26, 0);
    }
};

class Trie {
private:
    TrieNode* root = new TrieNode();
public:
    void insert(string word) {
        TrieNode* curr = root;
        for(auto val : word) {
            if(!curr->children[val-'a']) {
                curr->children[val-'a'] = new TrieNode();
            }
            curr = curr->children[val-'a'];
            curr->countPrefix++;
        }
        curr->countEnd++;
        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for(auto val : word) {
            if(!curr->children[val-'a']) {
                return false;
            }
            curr = curr->children[val-'a'];
        }
        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto val : prefix) {
            if(!curr->children[val-'a']) {
                return false;
            }
            curr = curr->children[val-'a'];
        } 
        return true;
    }

    int countWordsEqualTo(string word) {
        TrieNode* curr = root;
        for(auto val : word) {
            if(!curr->children[val-'a']) {
                return 0;
            }
            curr = curr->children[val-'a'];
        }
        return curr->countEnd;
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* curr = root;
        for(auto val : prefix) {
            if(!curr->children[val-'a']) {
                return 0;
            }
            curr = curr->children[val-'a'];
        }
        return curr->countPrefix;
    }

    void erase(string word) {
        TrieNode* curr = root;
        for(auto val : word) {
            curr = curr->children[val-'a'];
            curr->countPrefix--;
        }
        curr->countEnd--;
    }
};
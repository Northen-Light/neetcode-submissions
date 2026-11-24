class Trie {
public:
    Trie *next[26];
    bool isLeaf;

    Trie() {
        for (int i = 0; i < 26; i++) next[i] = NULL;
        isLeaf = false;
    }
};

class PrefixTree {
private:
   Trie *root;

public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie *node = root;

        for (auto &v: word) {
            if (node -> next[v - 'a'] == NULL) {                
                node -> next[v - 'a'] = new Trie();
            }
            node = node -> next[v - 'a'];
        }

        node -> isLeaf = true;
    }
    
    bool search(string word) {
        Trie *node = root;

        for (auto &v: word) {
            if (node -> next[v - 'a'] == NULL) {
                return false;
            }
            node = node -> next[v - 'a'];
        }

        return node -> isLeaf;
    }
    
    bool startsWith(string prefix) {
        Trie *node = root;

        for (auto &v: prefix) {
            if (node -> next[v - 'a'] == NULL) {
                return false;
            }
            node = node -> next[v - 'a'];
        }

        return true;
    }
};

class PrefixTree {
private:
    struct trie {
        trie *next[26];
        bool isLeaf; 
    };

    trie *root;

public:
    PrefixTree() {
        root = (trie *)malloc(sizeof(trie));
        for (int i = 0; i < 26; i++) root -> next[i] = NULL;
        root -> isLeaf = false;
    }
    
    void insert(string word) {
        trie *node = root;

        for (auto &v: word) {
            if (node -> next[v - 'a'] == NULL) {
                trie *newNode = (trie *)malloc(sizeof(trie));
                
                for (int i = 0; i < 26; i++) newNode -> next[i] = NULL;
                newNode -> isLeaf = false;
                
                node -> next[v - 'a'] = newNode;
            }
            node = node -> next[v - 'a'];
        }

        node -> isLeaf = true;
    }
    
    bool search(string word) {
        trie *node = root;

        for (auto &v: word) {
            if (node -> next[v - 'a'] == NULL) {
                return false;
            }
            node = node -> next[v - 'a'];
        }

        return node -> isLeaf;
    }
    
    bool startsWith(string prefix) {
        trie *node = root;

        for (auto &v: prefix) {
            if (node -> next[v - 'a'] == NULL) {
                return false;
            }
            node = node -> next[v - 'a'];
        }

        return true;
    }
};

struct Node {
    Node* child[26];
    bool isEnd = false;
};

class PrefixTree {
private:
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char ch: word) {
            if(!curr->child[ch - 'a']) {
                curr->child[ch - 'a'] = new Node();
            }
            curr = curr->child[ch - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char ch: word) {
            if(!curr->child[ch - 'a']) return false;
            curr = curr->child[ch - 'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch: prefix) {
            if(!curr->child[ch -'a']) return false;
            curr = curr->child[ch - 'a'];
        }
        return true;
    }
};

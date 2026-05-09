struct Node {
    unordered_map<char, Node*> child;
    bool isEnd = false;
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(char ch: word) {
            if(curr->child.find(ch) == curr->child.end()) curr->child[ch] = new Node();
            curr = curr->child[ch];
        }
        curr->isEnd = true;
    }
    
    bool dfs(Node* curr, int ind, string &word) {
        if(ind == word.size()) {
            return curr->isEnd;
        }

        char ch = word[ind];
        if(word[ind] != '.') {
            if(curr->child.find(ch) == curr->child.end()) {
                return false;
            }
            return dfs(curr->child[ch], ind + 1, word);
        } else {
            for(auto it: curr->child) {
                if(dfs(it.second, ind + 1, word)) return true;
            }
            return false;
        }
    }

    bool search(string word) {
        Node* curr = root;
        return dfs(curr, 0, word);
    }
};

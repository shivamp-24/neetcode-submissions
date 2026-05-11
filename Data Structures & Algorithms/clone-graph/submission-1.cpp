/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*, Node*> cloned;
        cloned[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* og = q.front();
            q.pop();

            for(auto child: og->neighbors) {
                if(cloned.find(child) == cloned.end()) {
                    cloned[child] = new Node(child->val);
                    q.push(child);
                }
                cloned[og]->neighbors.push_back(cloned[child]);
            }
        }
        return cloned[node];
    }
};

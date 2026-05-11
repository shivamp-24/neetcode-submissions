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
        Node* cloneNode = new Node(node->val);
        queue<pair<Node*, Node*>> q;
        q.push({node, cloneNode});

        unordered_set<Node*> vis;
        unordered_map<Node*, Node*> cloned;
        cloned[node] = cloneNode;
        vis.insert(node);
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            Node *og = it.first, *clone = it.second;
            for(auto child: og->neighbors) {
                if(cloned.find(child) == cloned.end()) {
                    Node* cloneChild = new Node(child->val);
                    cloned[child] = cloneChild;
                    clone->neighbors.push_back(cloneChild);
                } else {
                    clone->neighbors.push_back(cloned[child]);
                }

                if(vis.find(child) == vis.end()) {
                    vis.insert(child);
                    q.push({child, cloned[child]});
                }
            }
        }
        return cloneNode;
    }
};

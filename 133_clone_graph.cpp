 #include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> cloneMap;
        queue<Node*> q;
        q.push(node);
        cloneMap[node] = new Node(node->val);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (auto neighbor : cur->neighbors) {
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                cloneMap[cur]->neighbors.push_back(cloneMap[neighbor]);
            }
        }

        return cloneMap[node];
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        vector<vector<int>> ret;
        if (root == nullptr)
            return ret;
        q.push(root);
        // ret.push_back(vector<int>{root->val});
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level_vec;
            for (int i = 0; i < size; ++i)
            {
                Node *tmp = q.front();
                q.pop();
                level_vec.push_back(tmp->val);
                for (auto i : tmp->children)
                {
                    if(i != nullptr)
                        q.push(i);
                }
            }
            ret.emplace_back(level_vec);
        }
        return ret;
    }
};
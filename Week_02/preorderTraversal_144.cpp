class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        while(!stk.empty() || root != nullptr)
        {
            while(root != nullptr)
            {
                stk.push(root);
                ret.push_back(root->val);
                root = root->left;
            }
            if(!stk.empty())
            {
                root = stk.top();
                stk.pop();
                root = root->right;
            }
        }
        return ret;
    }
    
private:
    vector<int> ret;
};

class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        ret.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    
private:
    vector<int> ret;
};


//recursion 
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ret;
    }
    void dfs(TreeNode *t)
    {
        if(t == nullptr)
        {
            return;
        }
        dfs(t->left);
        ret.push_back(t->val);
        dfs(t->right);
    }
private:
    vector<int> ret;
};

//non_recursion
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        while(!stk.empty() || root != nullptr)
        {
            while(root != nullptr)
            {
                stk.push(root);
                root = root->left;
            }
            if(!stk.empty())
            {
                root = stk.top();
                stk.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }
private:
    vector<int> ret;
};
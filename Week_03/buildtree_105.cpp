/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return nullptr;
        return maketree(preorder, inorder, 0, preorder.size()-1, 0,inorder.size()-1);
    }

    TreeNode *maketree(vector<int> &preorder, vector<int> &inorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if(pre_left > pre_right || pre_left > preorder.size()-1)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_left]);
        int root_index = in_left;
        for(int i = in_left; i < in_right; ++i)
        {
            if(inorder[i] == preorder[pre_left])
            {
                root_index = i;
                break;
            }
        }
        root->left = maketree(preorder, inorder, pre_left + 1, root_index + pre_left - in_left, in_left, root_index - 1);
        root->right = maketree(preorder, inorder, root_index + pre_left - in_left + 1, pre_right, root_index + 1, in_right);
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int k;

    optional<int> kthSmallest_p(TreeNode* root)
    {
        if(root->left!=nullptr) {
            auto ret = kthSmallest_p(root->left);
            if(ret.has_value()) return ret;
        }  

        this->k--;
        if(this->k ==0) {
            throw root->val;
        }


        if(root->right!=nullptr) {
            auto ret = kthSmallest_p(root->right);
            return ret;
        }  

        return {};
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        try{
            this->k = k;
            auto ret = kthSmallest_p(root).value();
        }
        catch(int v) {
            return v;
        }
        return 1;
    }
};

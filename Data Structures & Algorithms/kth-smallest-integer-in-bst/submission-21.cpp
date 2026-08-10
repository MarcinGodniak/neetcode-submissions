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
    optional<int> kthSmallest_p(TreeNode* root, int &k)
    {
        if(root->left!=nullptr) {
            auto ret = kthSmallest_p(root->left, k);
            if(ret.has_value()) return ret;
        }  

        k--;
        if(k ==0) {
            throw root->val;
        }


        if(root->right!=nullptr) {
            auto ret = kthSmallest_p(root->right, k);
            return ret;
        }  

        return {};
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        try{
            auto ret = kthSmallest_p(root, k).value();
        }
        catch(int v) {
            return v;
        }
        return 1;
    }
};

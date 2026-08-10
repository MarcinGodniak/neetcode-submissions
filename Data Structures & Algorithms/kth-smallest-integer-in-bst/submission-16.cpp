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
    
    optional<int> kthSmallest_p(TreeNode* root, int k, int &d)
    {
        if(root->left!=nullptr) {
            auto ret = kthSmallest_p(root->left, k, d);
            if(ret.has_value()) return ret;
        }  

        d++;
        //std::cout<< "d " << d << " k "<< k<< " val " << root->val << std::endl;
        if(k ==d) return root->val;


        if(root->right!=nullptr) {
            auto ret = kthSmallest_p(root->right, k, d);
            return ret;
        }  

        return {};
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int d =0;
        auto ret = kthSmallest_p(root, k, d).value();
        std::cout<< ret <<std::endl;
        return ret;
    }
};

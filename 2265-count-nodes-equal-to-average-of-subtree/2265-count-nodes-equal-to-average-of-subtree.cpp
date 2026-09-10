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
public:
    int c = 0;
    pair<int,int> prev(TreeNode* node){
        if(!node) return {0, 0};
        auto const& left = prev(node->left);
        auto const& right = prev(node->right);
        int pn = left.second + right.second;
        int s = left.first + right.first;
        if(node->val == ((s + node->val) / (pn + 1))) c++;
        return {s + node->val, pn + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        prev(root);
        return c; 
    }
};
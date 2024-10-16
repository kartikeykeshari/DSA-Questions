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
    void inorder(TreeNode* root,long long& min,long long& secMin){
        if(root == NULL) return;
        if(min > root->val){
            secMin = min;
            min = root->val;
        }
        if(secMin >= root->val && root->val != min){
            secMin = root->val;
        }
        inorder(root->left,min,secMin);
        inorder(root->right,min,secMin);
        
    }
    int findSecondMinimumValue(TreeNode* root) {
        long long min = LONG_MAX;
        long long secMin = LONG_MAX;
        if(root == NULL) return -1;
        inorder(root,min,secMin);
        return (secMin != LONG_MAX) ? secMin : -1;
    }
};
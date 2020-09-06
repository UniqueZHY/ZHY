/*************************************************************************
	> File Name: 669.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 15时00分27秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if (!root)  return NULL;

    if (root->val < L) {
        return trimBST(root->right, L, R);
    }
    else if (root->val > R) {
        return trimBST(root->left, L, R);
    }
    else {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
}

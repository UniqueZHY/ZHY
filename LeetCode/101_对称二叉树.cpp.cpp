/*************************************************************************
	> File Name: 101.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时17分07秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree (struct TreeNode *p, struct TreeNode*q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val != 0) return false;
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) return true;
    return isSameTree(root->left, root->right);
}

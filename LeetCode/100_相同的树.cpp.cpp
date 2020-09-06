/*************************************************************************
	> File Name: 100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 14时53分59秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val - q->val != 0) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

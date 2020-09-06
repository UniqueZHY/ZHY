/*************************************************************************
	> File Name: 111_二叉树的最小深度.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 15时21分31秒
 ************************************************************************/
int minDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    if (root->left == NULL || root->right == NULL)
        return minDepth(root->right ? root->right : root->left) + 1;
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}

/*************************************************************************
	> File Name: 112_路径总和.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 16时09分17秒
 ************************************************************************/

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

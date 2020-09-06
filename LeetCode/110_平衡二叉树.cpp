/*************************************************************************
	> File Name: 110_平衡二叉树.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 15时01分13秒
 ************************************************************************/
/*int hight(struct TreeNode *node) {
    if (node == NULL) return 0;
    int l = hight(node->left);
    int r = hight(node->right);
    return fmax(l, r) + 1;
}
bool isBalanced(struct TreeNode* root){
    if (root == NULL) return true;
    int d = abs(hight(root->left) - hight(root->right));
    return (d <= 1) && isBalanced(root->left) && isBalanced(root->right);
}
*/
int Depth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = Depth(root->left), r = Depth(root->right);
    if (l == -2 || r == -2 || abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode *root) {
    return Depth(root) >= 0;
}

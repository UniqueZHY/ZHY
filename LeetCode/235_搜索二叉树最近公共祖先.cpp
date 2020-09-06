/*************************************************************************
	> File Name: 235_搜索二叉树最近公共祖先.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 19时48分47秒
 ************************************************************************/
struct TreeNode *__lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (root->val == p->val) return p;//p == 2 q == 4
    if (root->val == q->val) return q;//p == 0 q == 2
    if (root->val > p->val && root->val < q->val) return root;// p == 0 q == 4 
    if (p->val > root->val) return __lowestCommonAncestor(root->right, p, q);//p == 4 q == 5
    return __lowestCommonAncestor(root->left, p, q);
    }

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (p->val == q->val) return p;
    if (p->val > q->val) {//p永远是小的那个
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }
    return __lowestCommonAncestor(root, p, q);
    
}
/*struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return root;
}*/

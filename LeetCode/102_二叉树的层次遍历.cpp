/*************************************************************************
	> File Name: 102_二叉树的层次遍历.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 13时55分49秒
 ************************************************************************/
int getDepth(struct TreeNode *root) {//树的深度
    if (root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

void getCnt (struct TreeNode *root, int k, int *cnt) {//k层结点数
    if (root == NULL) return ;
    cnt[k] += 1;
    getCnt(root->left, k + 1, cnt);
    getCnt(root->right, k + 1, cnt);
    return ;
}

void getResult(struct TreeNode *root, int k, int *cnt, int **ret){
    if (root == NULL) return ;
    ret[k][cnt[k]++] = root->val;
    getResult(root->left, k + 1, cnt, ret);
    getResult(root->right, k + 1, cnt, ret);
    return ;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);
    int *cnt = (int *)calloc(sizeof(int), depth);
    int **ret = (int **)malloc(sizeof(int *) * depth);
    getCnt(root, 0, cnt);
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root, 0, cnt, ret);
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;
}

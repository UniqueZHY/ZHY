/*************************************************************************
	> File Name: 107_二叉树层序遍历2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月28日 星期五 14时56分36秒
 ************************************************************************/

int getDepth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int d1 = getDepth(root->left);
    int d2 = getDepth(root->right);
    return fmax(d1, d2) + 1;
}

void getSize(struct TreeNode *root, int k, int *size) {
    if (root == NULL) return ;
    size[k] += 1;
    getSize(root->left, k - 1, size);
    getSize(root->right, k - 1, size);
    return ;
}

void getData(struct TreeNode *root, int **ret, int *size, int k) {
    if (root == NULL) return ;
    ret[k][size[k]++] = root->val;
    getData(root->left, ret, size, k - 1);
    getData(root->right, ret, size, k - 1);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    if (root == NULL) return NULL;
    int n = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * n);
    int *size = (int *)calloc(sizeof(int), n);
    getSize(root, n - 1, size);
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * size[i]);
        size[i] = 0;
    }
    getData(root, ret, size, n - 1);
    *returnSize = n;
    *columnSizes = size;
    return ret;
}

/*************************************************************************
	> File Name: 257_二叉树所有路径.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 20时44分53秒
 ************************************************************************/
int getpathCnt(struct TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return getpathCnt(root->left) + getpathCnt(root->right);
}
//k 第几层的值， len用来记录每个路径数存放位置
int getREsult(struct TreeNode *root, int len, int k, char **ret, char *buff) {
    if (root == NULL) return 0;
    len += sprintf(buff + len, "%d", root->val);
    buff[len] = 0;
    if (root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buff);
        return 1;
    } 
    len += sprintf(buff + len, "->");
    int cnt = getREsult(root->left, len, k, ret, buff);
    cnt += getREsult(root->right,len, k + cnt, ret, buff); 
    return cnt;//返回当前这是第几条路径
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getpathCnt(root);
    char **ret = (char **) malloc(sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buff = (char *) malloc(sizeof(char)* max_len);
    getREsult(root, 0, 0, ret, buff);
    *returnSize = pathCnt;
    return ret;
}


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;//栈
        vector<int> ret;
        if (root) s.push(root); //判断根节点
        while (!s.empty()) {
            TreeNode *node = s.top();
            if (node != NULL) {
                s.pop();//先弹出避免重复操作
                if (node->right) s.push(node->right); //终须遍历应是左根右 所以入栈顺序为 右根左
                s.push(node);
                s.push(NULL);//给根节点后加NULL用来做标记
                if (node->left) s.push(node->left);
            } else {
                s.pop(); //弹出NULL
                node = s.top();//获取到当前跟结点
                ret.push_back(node->val);//放进答案数组
                s.pop();//删除以放入答案数组中的元素
            }
        }
        return ret;
    }
};


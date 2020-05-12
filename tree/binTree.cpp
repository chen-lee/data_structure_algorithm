#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 树的定义：二叉树是n个节点的有限集合，该集合或者为空集，或者由一个根节点和两棵互不相交的、分别成为根节点的左子树和右子树组成
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// 递归创建
// 前序遍历
void Create(const vector<string>& vals, TreeNode* tree_node) {
    static int i = 0;
    // 递归的终止条件
    auto& val = vals[i++];
    if (val == "#")
        return;
    tree_node = new TreeNode(stoi(val));
    Create(vals, tree_node->left);
    Create(vals, tree_node->right);
}

int main() {
    vector<string> vals = {"1", "2", "#", "3", "#", "#", "4", "#", "#"};
    TreeNode* root = NULL;
    Create(vals, root);
    return 0;
}

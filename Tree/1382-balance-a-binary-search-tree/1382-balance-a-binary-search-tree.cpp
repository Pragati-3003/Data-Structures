/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> nodes;

    void sorting(TreeNode* root) {
        if (root == NULL)
            return;
        sorting(root->left);
        nodes.push_back(root->val);
        sorting(root->right);
    }
    TreeNode* balanced(int start, int end) {
        if (start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nodes[mid]);
        node->left = balanced(start, mid - 1);
        node->right = balanced(mid + 1, end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        sorting(root);
        int n = nodes.size() - 1;
        return balanced(0, n);
    }
};
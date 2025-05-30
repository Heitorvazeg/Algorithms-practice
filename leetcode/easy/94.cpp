class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vetor;
        if (root == nullptr) return vetor;

        vetor = traverseTree(root, vetor);
        return vetor;
    }

    vector<int> traverseTree(TreeNode* node, vector<int>& vetor) {
        if (node == nullptr) return vetor;
        vetor = traverseTree(node->left, vetor);
        vetor.push_back(node->val);
        vetor = traverseTree(node->right, vetor);
        return vetor;
    }
};
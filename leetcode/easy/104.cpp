class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int maxi = traverseTree(root, 1, 0);
        return maxi;
    }

    int traverseTree(TreeNode* root, int maxi, int atual) {
        atual += 1;
        if (root == nullptr) {
            maxi = max(maxi, atual-1);
            return maxi;
        }
        maxi = traverseTree(root->left, maxi, atual);
        maxi = traverseTree(root->right, maxi, atual);
        return max(atual, maxi);
    }
};
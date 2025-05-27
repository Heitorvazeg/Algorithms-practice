class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vetorP;
        vector<int> vetorQ;

        vetorP = traverseTree(p, vetorP);
        vetorQ = traverseTree(q, vetorQ);

        if (vetorP == vetorQ) return true;
        return false;
    }

    vector<int> traverseTree(TreeNode* t, vector<int>& vetor) {
        if (t == nullptr) {
            vetor.push_back(-10001);
            return vetor;
        }
        vetor.push_back(t->val);
        vetor = traverseTree(t->left, vetor);
        vetor = traverseTree(t->right, vetor);
        return vetor;
    }
};
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

class Info{
    public:
    int min;
    int max;
    bool isBST;
    int size;
};

Info solve(TreeNode* &root, int &ans){
    if(root == NULL){
        return {INT_MAX, INT_MIN, true, 0};
    }

    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);

    Info curr;

    curr.size = left.size + right.size + 1;
    curr.min = min(left.min, root->data);
    curr.max = max(right.max, root->data);
    curr.isBST = left.isBST && right.isBST && (root->data > left.max && root->data < right.min);

    if(curr.isBST){
        ans = max(ans, curr.size);
    }

    return curr;

}

int largestBST(TreeNode * root){
    int ans = 0;
    Info i = solve(root, ans);
    return ans;
}
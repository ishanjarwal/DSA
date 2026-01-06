
class TreeNode{
      public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};



bool isBST(TreeNode* root, long min, long max){

        if(root == NULL) return true;

        if(root->data > min && root->data < max){
            bool left = isBST(root->left, min, root->data);
            bool right = isBST(root->right, root->data, max);
            return left && right;
        }else{
            return false;
        }
    }

int size(TreeNode* &root){
    if(root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

int check(TreeNode* root){
    if(root == NULL) return 1;

    if(isBST(root, LONG_MIN, LONG_MAX)){
        return size(root);
    }

    return max(check(root->left), check(root->right));
    
}

int largestBST(TreeNode * root){
    return check(root);
}
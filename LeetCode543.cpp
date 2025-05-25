class Solution { // O(n)
public:
    int ans=0;
    int diameter(TreeNode* root){
        if(!root) return 0;
        int leftAnswer =  diameter(root->left);
        int rightAnswer =  diameter(root->right);
        ans = max(ans,leftAnswer+rightAnswer+1);
        return max(leftAnswer,rightAnswer) +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return ans-1;
    }
};

class Solution { // O(n^2)
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    void helper(TreeNode* root, int &maxDiameter){
        if(root==NULL) return;
        int diameter =  maxDepth(root->left) + maxDepth(root->right);
        maxDiameter = max(maxDiameter,diameter);
        helper(root->left,maxDiameter);
        helper(root->right,maxDiameter);
        return;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        helper(root,maxDiameter);
        return maxDiameter;
    }
};

class Solution {
public:
    int maxDiameter = 0;
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter =  maxDepth(root->left) + maxDepth(root->right);
        maxDiameter = max(maxDiameter,diameter);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxDiameter;
    }
};

class Solution {
public:
    int maxDiameter = 0;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int diameter =  maxDepth(root->left) + maxDepth(root->right);
        maxDiameter = max(maxDiameter,diameter);
        helper(root->left);
        helper(root->right);
        return maxDiameter;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        else return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0; // reinitialize kardo
        return helper(root);
    }
};
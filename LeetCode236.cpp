class Solution {
public:
    bool existsIn(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return existsIn(root->left,target) || existsIn(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q) return root;
        else if(existsIn(root->left,p) && existsIn(root->right,q)) return root;
        else if(existsIn(root->right,p) && existsIn(root->left,q)) return root;
        else if(existsIn(root->left,p) && existsIn(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }
};

class Solution {
public:
    bool existsIn(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true;
        return existsIn(root->left,target) || existsIn(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(existsIn(root->left,p) && existsIn(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else if(existsIn(root->right,p) && existsIn(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }
};
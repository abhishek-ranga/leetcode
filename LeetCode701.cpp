class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* root = new TreeNode(val);
            return root;
        }
        if(root->val>val){
            if(root->left) insertIntoBST(root->left,val);
            else{
                TreeNode* temp = new TreeNode(val);
                root->left = temp;
                return root;
            }
        }
        else{
            if(root->right) insertIntoBST(root->right,val);
            else{
                TreeNode* temp = new TreeNode(val);
                root->right = temp;
                return root;
            }
        }
        return root;
    }
};
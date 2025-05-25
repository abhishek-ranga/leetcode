class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right) pred = pred->right;
        return pred;
    }
    TreeNode* ios(TreeNode* root){
        TreeNode* succ = root->right;
        while(succ->left) succ = succ->left;
        return succ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key){
            // case 1 : no child / leaf node
            if(root->left==NULL&&root->right==NULL) return nullptr;
            // case 2 : single child
            else if(root->left==NULL||root->right==NULL){
                if(root->left) return root->left; // root = root->left;
                else return root->right; // root = root->right;
            }
            // case 3 : two child nodes
            else{
                // replace the root with its inorder predeccesor or inorder successor
                TreeNode* predeccesor = iop(root);
                root->val = predeccesor->val;
                // after replacing delete the node you replaced with
                root->left = deleteNode(root->left,predeccesor->val); // for pred
            }
        }
        else if(root->val>key) root->left = deleteNode(root->left,key);
        else root->right = deleteNode(root->right,key);
        return root;
    }
};
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& ans){
        if(root==NULL){
            return;
        }
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        if(root->left==NULL && root->right==NULL) return {root->val};
        vector<int> ans;
        inOrder(root,ans);
        return ans;
    }
};

class Solution { // morris traversal
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root; vector<int> ans;
        while(curr!=NULL){
            if(curr->left!=NULL){ // find the predeccesor
                TreeNode* pred = curr->left;
                while(pred->right!=NULL && pred->right!=curr) pred = pred->right;
                if(pred->right==NULL){ // link
                    pred->right = curr;
                    curr = curr->left;
                }
                else{ // pred->right == curr
                    pred->right = NULL; // unlink and then visit;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{ // curr->left == NULL
                // visit
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
};
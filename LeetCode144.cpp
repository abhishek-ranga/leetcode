class Solution {
public:
    void preOrder(TreeNode* root, vector<int>& ans){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        if(root->left==NULL && root->right==NULL) return {root->val};
        vector<int> ans;
        preOrder(root,ans);
        return ans;
    }
};
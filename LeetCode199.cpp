class Solution { // crazy fucking code
public:
    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        else return 1 + max(Levels(root->left),Levels(root->right));
    }
    void preorder(TreeNode* root, vector<int>& ans, int level){
        if(!root) return;
        ans[level] = root->val;
        preorder(root->left,ans,level+1);
        preorder(root->right,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(Levels(root));
        preorder(root,ans,0);
        return ans;
    }
};

class Solution { // using level order and repeatedly updating values of the level
public:
    int Levels(TreeNode* root){
        if(root==NULL) return 0;
        else return 1 + max(Levels(root->left),Levels(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& ans){
        if(root==NULL) return; 
        if(curr==level){
            ans[curr] = root->val;
        }
        nthLevel(root->left,curr+1,level,ans);
        nthLevel(root->right,curr+1,level,ans);
    }
    void levelOrder(TreeNode* root, vector<int>& ans){
        int n = ans.size();
        for(int i=0; i<n; i++){
            nthLevel(root,0,i,ans);
        }
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(Levels(root));
        levelOrder(root,ans);
        return ans;
    }
};
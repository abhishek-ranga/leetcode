class Solution { // inorder constant space
public:
    TreeNode* temp = NULL;
    bool flag = true;
    void inOrder(TreeNode* root){
        if(!root) return;
        inOrder(root->left);
        if(temp && temp->val>=root->val) flag = false;
        else temp = root;
        inOrder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        return flag;
    }
};

class Solution { // inorder traversal extra space
public:
    void helper(TreeNode* root, vector<int>& v){
        if(!root) return;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        for(int i=0; i<v.size()-1; i++) if(v[i]>=v[i+1]) return false;
        return true;
    }
};

class Solution { // brute force
public:
    int maxTree(TreeNode* root){
        if(!root) return INT_MIN;
        return max(root->val,max(maxTree(root->left),maxTree(root->right)));
    }
    int minTree(TreeNode* root){
        if(!root) return INT_MAX;
        return min(root->val,min(minTree(root->left),minTree(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left&&!root->right) return true;
        if(root->val<=maxTree(root->left)){
            if(root->left) return false;
        }
        if(root->val>=minTree(root->right)){
            if(root->right) return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
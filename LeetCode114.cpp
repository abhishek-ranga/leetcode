class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                // save the right node
                TreeNode* r = curr->right;
                // change the connections
                curr->right = curr->left;
                // find predecessor
                TreeNode* pred = curr->left;
                while(pred->right!=NULL) pred = pred->right;
                // link
                pred->right = r;
                // aage ka kaam
                curr = curr->left;
            }
            else curr = curr->right;
        }
        TreeNode* temp = root;
        while(temp!=NULL){
            temp->left = NULL;
            temp = temp->right;
        }
        return;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = NULL;
        root->right = NULL;
        flatten(l);
        flatten(r);
        root->right = l;
        TreeNode* temp = root;
        while(temp->right) temp = temp->right;
        temp->right = r;
        return;
    }
};

class Solution {
public:
    void helper(TreeNode* root, queue<TreeNode*>& q){
        if(!root) return;
        q.push(root);
        helper(root->left,q);
        helper(root->right,q);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*> q;
        helper(root,q);
        q.pop();
        TreeNode* temp = root;
        while(!q.empty()){
            temp->left = NULL;
            temp->right = q.front();
            q.pop();
            temp = temp->right;
        }
        return;
    }
};
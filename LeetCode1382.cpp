class Solution {
public:
    TreeNode* helper(vector<int>& arr, int lo, int hi){
        if(lo>hi) return nullptr;
        int mid = lo+(hi-lo)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(arr,lo,mid-1);
        root->right = helper(arr,mid+1,hi);
        return root;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if(!root) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return helper(arr,0,arr.size()-1);
    }
};
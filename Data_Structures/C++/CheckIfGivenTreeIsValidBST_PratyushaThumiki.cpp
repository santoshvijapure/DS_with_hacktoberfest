class Solution {
private:
        bool bstHelper(TreeNode *root,int *lower_lim,int *higher_lim){
            if(root==NULL) return true;
        if((root->val <= lower_lim && min)||(max&&higher_lim <= root->val))
                return false;
        return bstHelper(root->left,lower_lim,root->val)&&isValidBST(root->right,root->val,higher_lim);
    }
    public:
    bool isValidBST(TreeNode* root) {
        return bstHelper(root,NULL,NULL);
    }
};
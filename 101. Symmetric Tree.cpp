//根上一题类似，上一题是p树和q树是否相同，只要把q树反过来遍历对比，即为判断p和q是否对称

bool isSymmetric(TreeNode* root) {
    return checkSymmetric(root,root);
}
bool checkSymmetric(TreeNode* root1,TreeNode* root2){
    if(!(root1==NULL && root2==NULL )){
        if(!(root1!=NULL && root2!=NULL && root1->val==root2->val))
            return false;
    }else
        return true;
    if(!(checkSymmetric(root1->left,root2->right)))
        return false;
    if(!checkSymmetric(root1->right,root2->left))
        return false;
    return true;
}

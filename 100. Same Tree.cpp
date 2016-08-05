//直接利用前序遍历，递归判断就可以
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!(p==NULL && q==NULL )){
        if(!(p!=NULL && q!=NULL && p->val==q->val))
            return false;
    }
    else
        return true;
    if(!isSameTree(p->left,q->left))
        return false;
    if(!isSameTree(p->right,q->right))
        return false;
    return true;
}

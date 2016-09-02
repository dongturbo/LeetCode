//根据二分查找树的特性，若两个元素都大于根节点，那么祖先应该在右子树，若都小于根节点，那么都在左子树，否则根节点就是祖先。
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* node=root;
    while(node!=nullptr){
        if(node->val>p->val && node->val>q->val)
            node=node->left;
        else if(node->val <p->val && node->val <q->val){
            node=node->right;
        }else{
            break;
        }
    }
    return node;
}

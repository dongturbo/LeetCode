/*第一种比较水的方法。即用中序遍历两次。
 1.由于排序二叉树中序遍历恰好是递增的顺序，把第一遍遍历的结果放到一个队列里
 2.把队列里的元素进行排序，
 3.然后再次中序遍历把队列里的元素依次赋值给节点
 这种方法占用空间O(n)
*/
void recurTree(TreeNode* root,vector<int> &queue){
    if(root->left!=NULL)
        recurTree(root->left,queue) ;
    queue.push_back(root->val);
    if(root->right!=NULL)
        recurTree(root->right,queue);
}
void recovTree(TreeNode* root,vector<int> &queue){
    if(root->left!=NULL)
        recovTree(root->left,queue) ;
    root->val=queue[0];
    queue.erase(queue.begin());
    if(root->right!=NULL)
        recovTree(root->right,queue);
}
void recoverTree(TreeNode* root) {
    vector<int> queue;
    recurTree(root,queue);   
    sort(queue.begin(),queue.end());  
    recovTree(root,queue);
}

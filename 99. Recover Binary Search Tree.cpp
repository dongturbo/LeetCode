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

/*O(n)空间的解法是开一个指针数组，中序遍历，将节点指针一次存放到数组里，然后寻找两处逆向的位置，先从前向后找第一个逆序的位置，然后从后往前
找第二个逆序的位置，交换着两个指针的值。
 中序遍历一般需要用到栈，空间也是O(n),利用Morris中序遍历空间才是O(1)
*/

void recoverTree(TreeNode* root) {
     pair<TreeNode*, TreeNode*> broken;
     TreeNode* prev = nullptr;
     TreeNode* cur = root;
     while (cur != nullptr) {
         if (cur->left == nullptr) {
             detect(broken, prev, cur);
             prev = cur;
             cur = cur->right;
         } else {
             auto node = cur->left;
             while (node->right != nullptr && node->right != cur)
             node = node->right;
             if (node->right == nullptr) {
                 node->right = cur;
                 //prev = cur; 
                 cur = cur->left;
             } else {
                 detect(broken, prev, cur);
                 node->right = nullptr;
                 prev = cur;
                 cur = cur->right;
             }
         }
     }
     swap(broken.first->val, broken.second->val);
 }
 void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev,
     TreeNode* current) {
     if (prev != nullptr && prev->val > current->val) {
         if (broken.first == nullptr) {
             broken.first = prev;
         } 
         broken.second = current;
     }
 }

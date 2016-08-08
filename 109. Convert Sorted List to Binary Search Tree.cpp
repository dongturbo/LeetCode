//可以利用上一题的思路，即遍历一遍ListNode，把数据存放到vector<int>中
TreeNode* sortedBST(vector<int> &nums,int begin,int end){
    if(begin>=end){
        return NULL;
    }
    int mid=(begin+end)/2;
    TreeNode* root=new TreeNode(nums[mid]);
    root->left=sortedBST(nums,begin,mid);
    root->right=sortedBST(nums,mid+1,end); 
    return root;
}


TreeNode* sortedListToBST(ListNode* head) {
     vector<int> nums;
     while(head!=NULL){
         nums.push_back(head->val);
         head=head->next;
     }
     return sortedBST(nums,0,nums.size());
}

//第二种方法，直接对ListNode进行遍历，和上一题类似
TreeNode *sortedListToBST(ListNode *head) {
    int len = 0;
    ListNode *p = head;
    while (p) {
        len++;
        p = p->next;
    }
    return sortedListToBST(head, 0, len );
}
TreeNode* sortedListToBST(ListNode*& list, int start, int end) {
    if (start >= end) return nullptr;
    int mid =  (end +start) / 2;
    TreeNode *leftChild = sortedListToBST(list, start, mid );
    TreeNode *parent = new TreeNode(list->val);
    parent->left = leftChild;
    list = list->next;
    parent->right = sortedListToBST(list, mid + 1, end);
    return parent;
}

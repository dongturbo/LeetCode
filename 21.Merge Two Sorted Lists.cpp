//此题是按照递增排序的，题目比较简单，首先两个链的值小的排在前面，排完其中一条链后，直接把另一条链接到末尾就行
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode * head,*node,num(0);
	head = &num;
	node = head;
	while (l1!=NULL && l2!=NULL){
		if (l1->val<l2->val){
			node->next = l1;
			node = l1;
			l1= l1->next;
		}
		else{
			node->next = l2;
			node = l2;
			l2= l2->next;
		}
	}
	if (l1 == NULL){
		if (l2 != NULL){
			node->next = l2;
		}
	}
	else if(l2==NULL){
		if (l1 != NULL){
			node->next = l1;
		}
	}
	return head->next;
}

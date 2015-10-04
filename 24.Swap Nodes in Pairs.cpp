struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}	
};


ListNode* swapPairs(ListNode* head) {
	ListNode node(0),*p,*l1,*l2;
	if (head == NULL){
		return NULL;
	}
	node.next =l1=l2= head;
	p = &node;
	while (true){
		//这里交换的是两个节点的值，不是他们的链
		if (l1->next != NULL){
			l2 = l1->next;
			int temp;
			temp = l1->val;
			l1->val = l2->val;
			l2->val = temp;
			p = l1=l2;			
		}
		else{
			break;
		}
		if (l1->next != NULL){
			l1 = l1->next;
		}
		else{
			break;
		}
	}
	return node.next;
}
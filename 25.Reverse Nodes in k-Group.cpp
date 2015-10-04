struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode node(0), *p, *l1, *l2, *l3, *nextHead=NULL, *thisEnd,*temp;
	if (head == NULL || k==1){
		return head;
	}
	temp=node.next = l1 = l2 = head;
	p = &node;
	while (true){
		bool check = true;   //判断剩余的节点数是否够k个
		//判断剩余的节点数是否够k个，不够的话跳出循环，置check为false;此时剩余节点不做翻转。
		for (int i = 0; i < k; i++){
			if (l2 == NULL){
				check = false;
				break;
			}
			nextHead = l2 = l2->next;
		}
		//剩余节点数够k个的话做翻转，if语句内是翻转过程
		if (check){
			thisEnd = l1;
			l2 = l1->next;
			l3 = l2->next;
			//翻转时，同时标记三个连续节点为p1,p2,p3；每个循环步中，使p2->next指向p1，
			//然后三个节点同时向后移动一步，直到完成翻转
			for (int i = 0; i < k - 1; i++){
				l2->next = l1;
				l1 = l2;
				l2 = l3;
				if (i < k - 2){
					l3 = l3->next;
				}
			}
			p->next = l1;
			p = thisEnd;
			temp=l1 = l2 = nextHead;
		}
		else{
			p->next = temp;
			break;
		}
	}
	return node.next;
}

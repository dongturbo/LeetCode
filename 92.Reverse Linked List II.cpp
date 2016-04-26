/*定义五个指针，三个指针负责交换链表节点的方向，两个指针负责保存链表交换段的头和尾，这样保证交换后能与没交换的那部分链接上。
*/

ListNode* reverseBetween(ListNode* head, int m, int n) {
	 ListNode node(0),*begin,*end,*p,*q,*r;
	 node.next = head;
	 p = begin = &node;
	 end=q = head;
	 r = head->next;
	 int count = 0;
	 while (q != nullptr){
		 count++;
		 if (count<m){
			 begin = p = q;
			 end=q = r;
			 r = r->next;
		 }
		 else if (count >= m ){
			 q->next = p;
			 if (count == n){
				 begin->next = q;
				 end->next = r;
				 break;
			 }			 
			 p = q;
			 q = r;
			 r = r->next;			 
		 }
	 }
	 return node.next;
 }
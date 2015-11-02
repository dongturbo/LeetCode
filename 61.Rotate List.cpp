/*这里有一点要注意，就是如果k大于ListNode的length的话，取k%length处翻转，而不是不翻转
解题思路：
	1.记录整个ListNode的长度length
	2.记录k-k%length，即此位置即为需要翻转的位置
	3.进行翻转
*/
ListNode* rotateRight(ListNode* head, int k){
	if (head == NULL)return NULL;
	ListNode *p = head;
	int n = 0;
	while (p->next)
	{
		p = p->next;
		n++;
	}
	n++;
	k = k%n;
	p->next = head;
	ListNode *q = head;
	for (int i = 0; i<n - k - 1; i++)
		q = q->next;
	head = q->next;
	q->next = NULL;
	return head;
}
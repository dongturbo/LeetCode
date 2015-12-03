/*解题思路：
	1.首先创建一个begin节点指向head，防止出现所有元素都相同时，list为空的情况。
	2.p1指向begin，p2指向head，然后循环p2，并判断p2是否下一个元素相同，相同的话，p2一直后移，知道移到不相同的为止，然后p1的next指向p2
	3.若p2和下一个元素不相同，则p1和p2依次后移
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* deleteDuplicates(ListNode* head) {
	ListNode node(0);
	ListNode * begin = &node, *p1, *p2;
	if (head == nullptr)
		return nullptr;
	p1 = begin;
	p2 = begin->next = head;
	while (p2->next != nullptr){
		if (p2->val!=p2->next->val){
			p2 = p2->next;
			p1 = p1->next;
		}
		else{
			while (p2->next!=nullptr && p2->val == p2->next->val)
				p2 = p2->next;
			if (p2->next == nullptr){
				p1->next = nullptr;
				break;
			}
			p2 = p2->next;
			p1->next = p2;
		}
	}
	return begin->next;
}
/*解题思路：
	和上一题思路一致，只是在遇见相同的元素时，不是全部略过，而且保留一个。
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
				p1->next = p2;
				break;
			}
			p1->next = p2;
		}
	}
	return begin->next;
}
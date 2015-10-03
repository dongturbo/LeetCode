/*有点类似于MergeSort的思路,就是分治法，不了解MergeSort的朋友，请参见 归并排序-维基百科 ，
是一个比较经典的O(nlogn)的排序算法，还是比较重要的。思路是先分成两个子任务，然后递归求子任务，最后回溯回来。这个题目也是这样，
先把k个list分成两半，然后继续划分，知道剩下两个list就合并起来，合并时会用到 Merge Two Sorted Lists 这道题，不熟悉的朋友可以复习一下。
*/
ListNode* mergeTowLists(ListNode* l1, ListNode * l2){
	ListNode  head(-1), *node;
	node = &head;
	while (l1 != NULL && l2 != NULL){
		if (l1->val<l2->val){
			node->next = l1;
			l1 = l1->next;
		}
		else{
			node->next = l2;
			l2 = l2->next;
		}
		node = node->next;
	}
	if (l1 == NULL){
		if (l2 != NULL){
			node->next = l2;
		}
	}
	else if (l2 == NULL){
		if (l1 != NULL){
			node->next = l1;
		}
	}
	return head.next;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.empty()){
		return NULL;
	}
	if (lists.size() == 1){
		return lists[0];
	}
	int length = lists.size();
	int mid = (length - 1) / 2;
	vector<ListNode*> list1, list2;
	for (int i = 0; i < length; i++){
		if (i <= mid){
			list1.push_back(lists[i]);
		}
		else{
			list2.push_back(lists[i]);
		}
	}
	ListNode * l1 = mergeKLists(list1);
	ListNode * l2 = mergeKLists(list2);
	return mergeTowLists(l1, l2);
}

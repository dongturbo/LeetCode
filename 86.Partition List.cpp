/*解题思路
    题意说的是把List进行分割，分割为小于x节点的部分，和不小于x节点的部分
    1.小于x节点的部分必须放到不小于x节点的部分前面
    2.两部分中的节点的相对顺序保持不变
    根据题意可按下列步骤求解：
        循环List中的节点，back表示循环的节点，front表示back的前一个节点，first表示比x小的节点应该移动的位置
        1.对所有节点进行遍历，节点比x小时继续遍历，若都小于x则结束，若遇到大于x的值时执行步骤2
        2.遇到比x大的节点时用first记录比x大的节点前面那个节点的位置（即后面若出现比x小的节点时的插入位置），执行步骤3
        3.继续遍历节点，若都不小于x则结束，若存在小于x的节点则执行步骤4
        4.把小于x的节点从中摘除，然后放到first之后，继续执行步骤3，直到遍历结束
*/
ListNode* partition(ListNode* head, int x) {
	 ListNode begin(0),*front,*back,*first=nullptr;
	 begin.next = head;
	 front = &begin;
	 back = head;
	 while (back != nullptr){
		 if (back->val < x && first==nullptr){
			 front = front->next;
			 back = back->next;
		 }
		 else if (back->val<x && first!=nullptr){
             //摘除小于x的节点，并插入到first之后
			 front->next = back->next;
			 back->next = first->next;
			 first->next = back;
			 back = front->next;
			 first = first->next;
		 }
		 else{
			 if (first == nullptr){
				 first = front;
			 }
			 front = front->next;
			 back = back->next;
		 }	 
	 }
	 return begin.next;
 }
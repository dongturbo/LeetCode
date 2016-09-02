 //迭代的同时，改变链表前后两个节点的next指针，使当前节点的next指针指向前一个节点，依次迭代下去，返回最后一个访问的节点即可。
 ListNode* reverseList(ListNode* head) {
    if(head==nullptr)
        return head;
    ListNode* prior,* curr,*next;
    prior=nullptr;
    curr=head,next=head->next;
    while(next!=nullptr){
        curr->next=prior;
        prior=curr;
        curr=next;
        next=next->next;
    }
    curr->next=prior;
    return curr;
}

//主要第一个节点比较麻烦，得先创建一个新节点指向第一个节点，这样就可以顺利迭代了
ListNode* removeElements(ListNode* head, int val) {
    ListNode *prior,*cur,first(0);
    prior=&first;
    first.next=cur=head;
    while(cur!=nullptr){
        if(cur->val==val){
            prior->next=cur->next;
            cur=cur->next;
            continue;
        }
        prior=cur;
        cur=cur->next;
    }
    return first.next;
}

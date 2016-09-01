void deleteNode(ListNode* node) {
    ListNode* p=node,* q;
    while(p->next!=nullptr){
        p->val=p->next->val;
        q=p;
        p=p->next;
    }
    q->next=nullptr;
}

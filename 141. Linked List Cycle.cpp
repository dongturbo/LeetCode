//设置两个指针，一个一次走一步，一个一次走两步，若出现他俩相等的情况就存在环，否则不存在
bool hasCycle(ListNode *head) {
    ListNode * next,*doubleNext;
    next=doubleNext=head;
    int step=0;
    while(doubleNext!=nullptr){
        doubleNext=doubleNext->next;
        if(doubleNext==next){
            return true;
        }
        if(step%2==1){
            next=next->next;
            step=1;
        }
        step++;
    }
    return false;
}

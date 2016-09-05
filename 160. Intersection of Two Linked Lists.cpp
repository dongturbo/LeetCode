ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *nodeA=headA,*nodeB=headB;
    int lenA=0,lenB=0;
    while(nodeA!=nullptr){
        nodeA=nodeA->next;
        lenA++;
    }
    while(nodeB!=nullptr){
        nodeB=nodeB->next;
        lenB++;
    }
    nodeB=headB;
    nodeA=headA;
    if(lenA>lenB){
        for(int i=0;i<lenA-lenB;i++)
            nodeA=nodeA->next;
    }else if(lenA<lenB){
        for(int i=0;i<lenB-lenA;i++)
            nodeB=nodeB->next;
    }
    while(nodeA!=nullptr){
        if(nodeA==nodeB)
            return nodeA;
        nodeA=nodeA->next;
        nodeB=nodeB->next;
    }
    return NULL;
}

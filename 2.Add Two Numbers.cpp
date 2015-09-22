ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp=0;
        ListNode * head=l2;
        while(l1->next!=null || l2->next!=null){
            l2->val=(l1->val+l2->val)%10;
            temp=(l1->val+l2->val)/10;
            l1=li->next;
            l2=l2->next;
        }
        if(l1->next==null){
            l2->val=(temp+l2->val+l1->val)%10;
            l2->next-val=l2->next-val+
        }
        if(l2=null){
            l2-
        }
    }
/*设i为0，从head开始计数，往后移动一个node，i++,当i=n时此时的node到head的距离恰好是n个，
然后head和node一起移动到最后，这时head所指向的位置既是倒数第n个*/
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * node=head,*preNode;
        preNode->next=head;
        if(n==0){
            return head;
        }
        int i=0,k=0;
        while(true){
            if(node->next==NULL){
                if(n==1){
                    preNode->next=NULL;
                }else{
                    preNode->next=preNode->next->next;
                    
                }
                if(k==0){
                    head=preNode->next;
                }
                return head;
            }
            if(i!=n-1){
                i++;
            }else{
                preNode=preNode->next;
                k++;
            }
            node=node->next;
        }
        
    }
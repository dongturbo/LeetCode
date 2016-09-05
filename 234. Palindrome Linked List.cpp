//把链表的前一半翻转，然后匹配两者是否回文
bool isPalindrome(ListNode* head) {
    ListNode *pfast = head, *pr, *pl, *pt;
    if (!pfast || !(pfast->next)) {
        return true;
    }
    pl = head;
    pr = head->next;
    pfast = pfast->next;
    head->next = NULL;
    while (pfast->next && pfast->next->next) {
        pfast = pfast->next->next;
        pt = pr->next;
        pr->next = pl;
        pl = pr;
        pr = pt;
    }
    pr = pfast->next ? pr->next : pr;
    while (pr) {
        if (pl->val != pr->val) {
            return false;
        } else {
            pl = pl->next;
            pr = pr->next;
        }
    }
    return true;
}

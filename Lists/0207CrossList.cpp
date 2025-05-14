 #include <iostream>

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getListLen(ListNode *head)
{
    int len = 0;
    ListNode * cur = head;
    while (cur)
    {
        len++;
        cur = cur->next;
    }
    return len;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = getListLen(headA);
    int lenB = getListLen(headB);
    ListNode * fast = new ListNode();
    ListNode * slow = new ListNode();
    int deltaLen;
    if (lenA > lenB)
    {
        fast = headA;
        slow = headB;
        deltaLen = lenA - lenB;
    } else 
    {
        fast = headB;
        slow = headA;
        deltaLen = lenB - lenA;
    }

    while (deltaLen--)
    {
        fast = fast->next;
    }
    // 此时fast和slow应该对齐
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
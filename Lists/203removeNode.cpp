 #include <iostream>

 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* fakeHead = new ListNode(0, head);
        ListNode* curNode = head;
        ListNode* lastNode = fakeHead;
        ListNode* tmpNode = new ListNode;
        while (curNode != nullptr)
        {
            if (curNode->val == val) 
            {
                tmpNode = curNode;
                lastNode->next = curNode->next;
                // 更新cur
                curNode = tmpNode->next;
            } else 
            {
                tmpNode = curNode;
                curNode = curNode->next;
                lastNode = tmpNode;
            }
            
        }
        return fakeHead->next;
    }
};
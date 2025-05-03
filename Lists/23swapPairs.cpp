/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            ListNode * dummy = new ListNode(0, head);
            ListNode * cur = dummy;
            ListNode * tmpNode = new ListNode();
            while(cur->next && cur->next->next)
            {
                tmpNode = cur->next;
                cur->next = tmpNode->next;
                tmpNode->next = cur->next->next;
                cur->next->next = tmpNode;
                cur = tmpNode;
            }
            return dummy->next;
        }
    };
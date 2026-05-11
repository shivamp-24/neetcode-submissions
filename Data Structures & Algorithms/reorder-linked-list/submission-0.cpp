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
private:
    ListNode* reverseList(ListNode* node) {
        if(!node->next) return node;

        ListNode* newHead = reverseList(node->next);
        node->next->next = node;
        node->next = NULL;

        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head->next;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = reverseList(slow->next);
        slow->next = NULL;
        slow = head;

        while(slow) {
            ListNode* slowNext = slow->next, *fastNext = fast->next;
            slow->next = fast;
            if(slowNext) fast->next = slowNext;

            slow = slowNext;
            fast = fastNext;
        }
    }
};

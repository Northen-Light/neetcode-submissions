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
    int lengthOfLL(ListNode *head) {
        ListNode *node = head;
        int len = 0;

        while (node != 0) {
            len++;
            node = node -> next;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lengthOfLL(head);

        int idx = 0;
        n = len - n;

        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *next;

        while (idx <= n) {
            next = cur -> next;
            if (idx == n) {
                if (prev) {
                    prev -> next = next;
                } else {
                    head = next;
                }
                delete cur;
            } else {
                prev = cur;
            }
            cur = next;
            idx++;
        }

        return head;
    }
};

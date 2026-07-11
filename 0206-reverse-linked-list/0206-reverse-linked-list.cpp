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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head;
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* curr = head->next;
        ListNode* front = head->next->next;

        head->next = NULL;
        while (front != NULL) {
            curr->next = prev;
            prev = curr;
            curr = front;
            front = front->next;
        }
        curr->next = prev;
        head = curr;
        return head;
    }
};
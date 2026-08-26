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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        ListNode* temp = head;
        while (temp != NULL) {
            vec.push_back(temp);
            temp = temp->next;
        }

        int k = vec.size();
        if (k <= 1)
            return NULL;

        if (k == n)
            return head->next;
        vec[k - n - 1]->next = vec[k - n - 1]->next->next;
        return head;
    }
};
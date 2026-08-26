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
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* head = NULL;
        ListNode* tempHead = NULL;
        for (auto& x : lists)
            if (x != NULL)
                pq.push(x);
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            if (head == NULL) {
                head = temp;
                tempHead = temp;
            } else {
                tempHead->next = temp;
                tempHead = temp;
            }

            if (temp->next != NULL)
                pq.push(temp->next);
        }
        if (head != NULL)
            tempHead->next = NULL;
        return head;
    }
};
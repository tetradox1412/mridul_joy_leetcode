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
    void reorderList(ListNode* head) {
        if (head != NULL) {
            vector<ListNode*> vec;
            for (ListNode* i = head; i != NULL; i = i->next)
                vec.push_back(i);

            int n = vec.size();
            int left = 1, right = n - 1;
            ListNode* tail = head;
            bool leftChance = false;
            while (left <= right) {
                if (leftChance) {
                    tail->next = vec[left];
                    tail = vec[left++];
                } else {
                    tail->next = vec[right];
                    tail = vec[right--];
                }
                leftChance = !leftChance;
            }
            tail->next = NULL;
        }
    }
};
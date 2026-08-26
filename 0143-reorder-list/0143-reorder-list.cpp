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
            vector<ListNode*> finalVec;
            for (ListNode* i = head; i != NULL; i = i->next)
                vec.push_back(i);

            int n = vec.size();
            int left = 0, right = n - 1;

            bool leftChance = true;
            while (left <= right) {
                if (leftChance)
                    finalVec.push_back(vec[left++]);
                else
                    finalVec.push_back(vec[right--]);
                leftChance = !leftChance;
            }

            ListNode* tail = head;
            for (int i = 1; i < n; i++) {
                tail->next = finalVec[i];
                tail = finalVec[i];
            }
            tail->next = NULL;
        }
    }
};
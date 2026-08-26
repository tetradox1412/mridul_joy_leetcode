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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        int minVal = min(list1->val, list2->val);
        if (minVal == list1->val)
            list1 = list1->next;
        else
            list2 = list2->next;
        ListNode* ans = new ListNode(minVal);
        ListNode* tail = ans;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                ListNode* a = new ListNode(list1->val);
                list1 = list1->next;
                tail->next = a;
                tail = a;
            } else {
                ListNode* a = new ListNode(list2->val);
                list2 = list2->next;
                tail->next = a;
                tail = a;
            }
        }

        if (list1 != NULL)
            tail->next = list1;
        if (list2 != NULL)
            tail->next = list2;

        return ans;
    }
};
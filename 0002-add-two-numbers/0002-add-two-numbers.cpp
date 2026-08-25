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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        int val;
        while (temp1 != NULL && temp2 != NULL) {
            val = temp1->val + temp2->val + carry;
            s += (val % 10) + '0';
            carry = val / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1 != NULL) {
            val = temp1->val + carry;
            s += (val % 10) + '0';
            carry = val / 10;
            temp1 = temp1->next;
        }

        while (temp2 != NULL) {
            val = temp2->val + carry;
            s += (val % 10) + '0';
            carry = val / 10;
            temp2 = temp2->next;
        }

        if (carry)
            s += carry + '0';

        ListNode* ans = new ListNode(s[0] - '0');
        ListNode* tail = ans;
        for (int i = 1; i < s.size(); i++) {
            ListNode* a = new ListNode(s[i] - '0');
            tail->next = a;
            tail = a;
        }
        return ans;
    }
};
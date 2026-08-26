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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> vec;
        ListNode* temp = head;
        while (temp != NULL) {
            vec.push_back(temp);
            temp = temp->next;
        }

        if (vec.size() < k)
            return head;

        int present = k;
        while (present <= vec.size()) {
            int left = present - k, right = present - 1;
            while (left < right)
                swap(vec[left++], vec[right--]);
            present += k;
        }

        head = vec[0];
        temp = head;
        for (int i = 1; i < vec.size(); i++) {
            temp->next = vec[i];
            temp = vec[i];
        }
        temp->next = NULL;
        return head;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> list_org;
        vector<Node*> ans_list;
        unordered_map<Node*, Node*> map;

        if (head == NULL)
            return NULL;

        Node* temp = head;
        while (temp != NULL) {
            list_org.push_back(temp);
            temp = temp->next;
        }

        int n = list_org.size();
        for (int i = 0; i < n; i++) {
            Node* a = new Node(list_org[i]->val);
            map[list_org[i]] = a;
            ans_list.push_back(a);
        }

        for (int i = 0; i < n - 1; i++)
            ans_list[i]->next = ans_list[i + 1];
        ans_list[n - 1]->next = NULL;

        for (int i = 0; i < n; i++) {
            if (list_org[i]->random == NULL)
                ans_list[i]->random = NULL;
            else
                ans_list[i]->random = map[list_org[i]->random];
        }

        return ans_list[0];
    }
};
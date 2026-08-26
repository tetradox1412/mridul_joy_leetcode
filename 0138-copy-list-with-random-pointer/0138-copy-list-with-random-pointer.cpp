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
        if (head == NULL)
            return head;

        unordered_map<Node*, Node*> map;
        Node* ans = new Node(head->val);
        map[head] = ans;
        Node* temp = ans;
        Node* tempHead = head;
        while (tempHead->next != NULL) {
            Node* a = new Node(tempHead->next->val);
            temp->next = a;
            temp = a;
            map[tempHead->next] = a;
            tempHead = tempHead->next;
        }
        temp = ans;
        while (head != NULL) {
            if (head->random == NULL)
                temp->random == NULL;
            else
                temp->random = map[head->random];
            head = head->next;
            temp = temp->next;
        }
        return ans;
    }
};
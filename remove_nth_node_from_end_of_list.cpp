class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        int size = nodes.size();
        if (n == size) {
            return head->next;
        }
        int removeIndex = size - n;
        nodes[removeIndex - 1]->next = nodes[removeIndex]->next;
        return head;
    }
};

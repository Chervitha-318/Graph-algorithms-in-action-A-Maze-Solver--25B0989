class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        int left = 0;
        int right = nodes.size() - 1;
        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;
            if (left == right)
                break;
            nodes[right]->next = nodes[left];
            right--;
        }
        nodes[left]->next = NULL;
    }
};

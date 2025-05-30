class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode dummy(0);
        ListNode* tail = &dummy;
        unordered_map<int, int> map;
        while (head != nullptr) {
            if (seen.count(head->val) == 0) {
                seen.insert(head->val);
                tail->next = head;
                tail = tail->next;
        while (head != nullptr) {
            if (!map.count(head->val)) {
                tail->next = head;
                tail = tail->next;
                map[head->val] = head->val;
            }
            head = head->next;
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
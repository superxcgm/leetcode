//
// Created by Yujia Li  on 2020/5/25.
//

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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        stack<ListNode*> st;

        ListNode *p = head;
        while(p) {
            st.push(p);
            p = p->next;
        }

        ListNode *new_head;

        new_head = st.top();
        st.pop();
        p = new_head;
        while(!st.empty()) {
            p->next = st.top();
            st.pop();
            p = p->next;
        }
        p->next = nullptr;

        return new_head;
    }
};
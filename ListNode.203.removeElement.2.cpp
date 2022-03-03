#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
  
struct ListNode* removeElement(struct ListNode* head, int val) {
     //删除头结点
     while (head != NULL && head->val == val) { // 注意这里不是if
            ListNode* tmp = head;
            head = head->next;
            free(tmp);
        }

        // 删除非头结点
        ListNode* cur = head;
        while (cur != NULL && cur->next!= NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                free(tmp);
            } else {
                cur = cur->next;
            }
        }
        return head;
}

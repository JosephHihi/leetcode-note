#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};
 
struct ListNode* removeElement(struct ListNode* head, int val) {
    ListNode* dummyHead;
    dummyHead = (ListNode*)malloc(sizeof(ListNode));
    dummyHead->next = head;
    ListNode* cur = dummyHead;
     while(cur->next != NULL){
        if (cur->next->val == val){
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            free(tmp);
        }
        else{
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    free(dummyHead);
    return head;
}
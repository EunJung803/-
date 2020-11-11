//리스트 역순 

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head) {
    for(ListNode *p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("NULL \n");
}

ListNode *reverse(ListNode *head) {

    //순회 포인터로 p, q, r을 사용
    ListNode *p, *q, *r;
    
    p = head;       // p는 역순으로 만들 리스트
    q = NULL;       // q는 역순으로 만들 노드
    while(p != NULL) {
        // r은 q, q는 p 를 차례대로 따라간다
        
        r = q;          // r은 역순으로 된 리스트
        q = p;
        p = p->link;

        q->link = r;    // q의 링크 방향을 바꾼다
    }
    return q;
}

int main(void) {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);
    return 0;
}
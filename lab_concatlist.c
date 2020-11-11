//두개의 리스트를 하나로 합치기

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

ListNode *concat_list(ListNode *head1, ListNode *head2) {
    if(head1 == NULL) return head2;
    else if (head2 == NULL) return head1;
    else {
        ListNode *p;                    // p 선언
        p = head1;                      // p = head1
        while (p->link != NULL)         // p의 link가 NULL을 만날때까지 (첫번째 리스트의 끝 = NULL 까지)
            p = p->link;                // p를 link를 따라 움직이면서 옆으로 이동 (link가 NULL인 노드를 만날 때 까지)
        p->link = head2;                // NULL을 link로 가지고 있는 노드를 만나면 그 link를 head2가 가리키는 노드를 가리키게 하기 (head2로 연결)
        return head1;   
    }
}

int main(void) {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    print_list(head2);

    ListNode *total = concat_list(head1, head2);
    print_list(total);
    return 0;
}   
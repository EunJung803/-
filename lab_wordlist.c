//단어들을 저장하는 연결리스트

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode *insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));     // 노드형 포인터 p 생성
    p->data = value;                                        // data 자리에 value (단어) 삽입
    p->link = head;                                         // link를 head가 가리키는 애를 가리키게 하기
    head = p;                                               // 포인터 p를 head로 바꿔주기
    return head;
}

void print_list(ListNode *head) {
    for(ListNode *p = head; p != NULL; p = p->link) {
        printf("%s->", p->data.name);
    }
    printf("NULL \n");
}

int main(void) {
    ListNode *head = NULL;
    element data;

    strcpy(data.name, "APPLE");         //단어를 name 배열에 data로 복사
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}
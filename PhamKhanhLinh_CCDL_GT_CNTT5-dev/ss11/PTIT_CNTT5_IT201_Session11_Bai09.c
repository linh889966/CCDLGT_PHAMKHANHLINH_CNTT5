#include "../common.h"
struct NODE {
    int data;
    struct NODE *next;
    struct NODE *prev;
};

struct NODE* create_node(int data) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void append_node(struct NODE** head, int value) {
    struct NODE* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct NODE* tail = *head;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = new_node;
    new_node->prev = tail;
}

void insert_at_position(struct NODE** head, int value, int position) {
    if (position < 0) return;
    struct NODE* new_node = create_node(value);

    if (position == 0) {
        new_node->next = *head;
        if (*head) (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    struct NODE* curr = *head;
    int index = 0;
    while (curr != NULL && index < position - 1) {
        curr = curr->next;
        index++;
    }

    if (curr == NULL) {
        free(new_node);
        return;
    }

    new_node->next = curr->next;
    new_node->prev = curr;
    if (curr->next)
        curr->next->prev = new_node;
    curr->next = new_node;
}

void delete_at_position(struct NODE** head, int position) {
    if (*head == NULL || position < 0) return;

    struct NODE* curr = *head;
    int index = 0;

    if (position == 0) {
        *head = curr->next;
        if (*head) (*head)->prev = NULL;
        free(curr);
        return;
    }

    while (curr != NULL && index < position) {
        curr = curr->next;
        index++;
    }

    if (curr == NULL) return;

    if (curr->prev) curr->prev->next = curr->next;
    if (curr->next) curr->next->prev = curr->prev;
    free(curr);
}

void reverse_list(struct NODE** head) {
    struct NODE* curr = *head;
    struct NODE* temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
        *head = temp->prev;
}

void print_list(struct NODE* head) {
    struct NODE* curr = head;
    printf("Danh sach: ");
    while (curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL) printf("<->");
        curr = curr->next;
    }
    printf("->NULL\n");
}

int main() {
    struct NODE* head = NULL;
    int values[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        append_node(&head, values[i]);

    printf("Ban dau:\n");
    print_list(head);

    int val, pos;
    printf("\nNhap gia tri muon chen: ");
    scanf("%d", &val);
    printf("Nhap vi tri muon chen (bat dau tu 0): ");
    scanf("%d", &pos);
    insert_at_position(&head, val, pos);
    print_list(head);

    printf("\nNhap vi tri muon xoa (bat dau tu 0): ");
    scanf("%d", &pos);
    delete_at_position(&head, pos);
    print_list(head);

    printf("\nDao nguoc danh sach:\n");
    reverse_list(&head);
    print_list(head);

    return 0;
}

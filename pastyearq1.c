#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Staff {
    char name[20];
    double salary;
} Staff;

typedef struct StaffNode {
    Staff staffData;
    struct StaffNode *next;
} StaffNode;

// Fungsi cari gaji maksimum dalam linked list
double findMax(StaffNode *head) {
    if (head == NULL) {
        return 0.0; // atau return -1.0 untuk tandakan kosong
    }

    double maxSalary = head->staffData.salary;
    StaffNode *current = head->next;

    while (current != NULL) {
        if (current->staffData.salary > maxSalary) {
            maxSalary = current->staffData.salary;
        }
        current = current->next;
    }

    return maxSalary;
}

// Fungsi buang satu node dari stack (pop)
void pop(StaffNode **head) {
    if (*head == NULL) {
        printf("Stack is empty. Nothing to pop.\n");
        return;
    }

    StaffNode *temp = *head;
    *head = (*head)->next;
    printf("Popped: %s (%.2lf)\n", temp->staffData.name, temp->staffData.salary);
    free(temp);
}

int main() {
    int i;
    char staffName[20];
    double staffSalary;

    StaffNode *head = NULL, *p1;

    for(i = 0; i < SIZE; i++) {
        printf("\nEnter name: ");
        scanf("%s", staffName);
        printf("Enter salary: ");
        scanf("%lf", &staffSalary);

        p1 = malloc(sizeof(StaffNode));

        strcpy(p1->staffData.name, staffName);
        p1->staffData.salary = staffSalary;
        p1->next = NULL;

        // Stack insertion (insert at head)
        if (head == NULL)
            head = p1;
        else {
            p1->next = head;
            head = p1;
        }
    }

    // Cari gaji maksimum
    double max = findMax(head);
    printf("\nMaximum salary: %.2lf\n", max);

    // Buang satu node (stack pop)
    pop(&head);

    // Papar semula senarai selepas pop
    printf("\nList after one pop:\n");
    StaffNode *curr = head;
    while (curr != NULL) {
        printf("%s - %.2lf\n", curr->staffData.name, curr->staffData.salary);
        curr = curr->next;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
typedef struct Node {
    char data[50];
    struct Node* next;
} Node;

void initializeList(Node** head, const char* states[], int size);
void insert(Node** head, const char* value, int index);
void display(Node* head);
void displayAtIndex(Node* head, int index);
void sortAscending(Node** head);
void sortDescending(Node** head);
void search(Node* head, const char* value);
int deleteNode(Node** head, const char* value);
int deleteByIndex(Node** head, int index);
void displayMenu(void);

int main() 
{
    int choice, result, insertChoice, index, type;
    char input[50];

    const char* states[] = {
        "Johore", "Kelantan", "Sabah", "Perak", "Kedah", "Malacca",
        "Putrajaya", "Pahang", "Perlis", "Labuan", "Negeri Sembilan",
        "Sarawak", "Pulau Pinang", "Selangor", "Terengganu", "Kuala Lumpur"
    };
    int numStates = sizeof(states) / sizeof(states[0]);

    Node* head = NULL;

    initializeList(&head, states, numStates);

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch (choice) {
            case 1: // Insert

                printf("\nWhere do you want to insert?\n");
                printf("1. Start\n2. End\n3. Specific Index\nEnter choice: ");
                scanf("%d", &insertChoice);
                getchar(); // Clear newline

                printf("\nEnter state/territory name to insert: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline

                switch (insertChoice) {
                    case 1:
                        insert(&head, input, 0);
                        break;
                    case 2:
                        insert(&head, input, 9999); // Large number to ensure it's at the end
                        break;
                    case 3:
                        printf("Enter index to insert at: ");
                        scanf("%d", &index);
                        getchar(); // Clear newline
                        insert(&head, input, index);
                        break;
                    default:
                        printf("Invalid insertion option.\n");
                        break;
                }

                break;

            case 2: // Display 
                printf("\n1. Display whole list\n2. Display specific index\n");
                printf("Enter your choice: ");
                scanf("%d", &type);
                getchar();
                switch (type)
                {
                    case 1:
                        printf("\nCurrent List :\n");
                        display(head);
                        break;

                    case 2: 
                        printf("Enter index to display (starting from 0): ");
                        scanf("%d", &index);
                        getchar(); // Clear newline
                        displayAtIndex(head, index);
                        break;

                    default:
                        printf("Invalid display option.\n");
                        break;
                }
                break;

            case 3: // Sort (Ascending)
            {
                sortAscending(&head);
                printf("\nList sorted in ascending order:\n");
                display(head);
            }
                break;

            case 4: // Sort (Descending)
            {
                sortDescending(&head);
                printf("\nList sorted in descending order:\n");
                display(head);
            }
                break;

            case 5: // Search
                printf("Enter state/territory name to search: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0';
                search(head, input);
                break;

            case 6: // Delete
                printf("\n1. Delete by name \n2. Delete by specific index\n");
                printf("Enter your choice: ");
                scanf("%d", &type);
                getchar();
                switch (type)
                {
                    case 1:
                        printf("Enter state/territory name to delete: ");
                        fgets(input, sizeof(input), stdin);
                        input[strcspn(input, "\n")] = '\0';
                        result = deleteNode(&head, input);
                        break;

                    case 2: 
                        printf("Enter index to delete (starting from 0): ");
                        scanf("%d", &index);
                        getchar();
                        result = deleteByIndex(&head, index);
                        break;

                    default:
                        printf("Invalid display option.\n");
                        break;
                }

                if(result == 1)
                {
                    printf("List is empty. Cannot delete.\n");
                }
                else if (result == 2)
                {
                    if(type == 1)
                    {
                        printf("'%s' not found in the list.\n", input);
                    }
                    else if (type == 2)
                    {
                        printf("Index %d not found in the list\n", index);
                    }
                }
                else if (result == 3)
                {
                    if(type == 1)
                    {
                        printf("'%s' deleted successfully.\n", input);
                    }
                    else if (type == 2)
                    {
                        printf("Node at index %d deleted successfully\n", index);
                    }  
                }
                break;

            case 7: // Exit
                printf("Exiting program. Memory freed.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Funtion to initialize data in array into linked list / aslo used to display the data in original data.
void initializeList(Node** head, const char* states[], int size) {
    for (int i = 0; i < size; i++) {
        insert(head, states[i], 9999);
    }
}

// Function to insert a node into the list
void insert(Node** head, const char* value, int index) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->data, value);
    newNode->next = NULL;

    // Insert at the start or if list is empty
    if (index <= 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to node just before the target index
    Node* temp = *head;
    int currentIndex = 0;
    while (temp->next != NULL && currentIndex < index - 1) {
        temp = temp->next;
        currentIndex++;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the list
void display(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    int i = 0;
    Node* temp = head; //the best practice is copy the head pointer to a temporary pointer
    while (temp != NULL) 
    {
        printf("[%d] %s\n", i, temp->data);
        temp = temp->next;
        i++;
    }
}

void displayAtIndex(Node* head, int index) {
    int count = 0;
    while (head != NULL) {
        if (count == index) {
            printf("Index %d : %s\n", index, head->data); //not the best practice 
            return;
        }
        count++;
        head = head->next;
    }
    printf("Index %d is out of bounds.\n", index);
}

// Function to sort the list in ascending order (bubble sort)
void sortAscending(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    int swapped;
    Node* ptr1;
    Node* lastPointer = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lastPointer) {
            if (strcmp(ptr1->data, ptr1->next->data) > 0) {
                // Swap data
                char temp[50];
                strcpy(temp, ptr1->data);
                strcpy(ptr1->data, ptr1->next->data);
                strcpy(ptr1->next->data, temp);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lastPointer = ptr1;
    } while (swapped);
}

// Function to reverse the list (for descending order)
void sortDescending(Node** head) {

    sortAscending(head);

    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to search for a state/territory
void search(Node* head, const char* value) {
    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data, value) == 0) {
            printf("'%s' found in the list.\n", value);
            return;
        }
        temp = temp->next;
    }
    printf("'%s' not found in the list.\n", value);
}

// Function to delete a node
int deleteNode(Node** head, const char* value) {
    //If list empty return 1
    if (*head == NULL) {
        return 1;  
    }

    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->data, value) != 0) {
        prev = temp;
        temp = temp->next;
    }
    //If list value not found return 2
    if (temp == NULL) {
        return 2;  
    }

    //If list found and deleted return 3
    if (temp == *head) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    return 3;  
}

int deleteByIndex(Node** head, int index) {
   // If the list is empty, return 1
   if (*head == NULL) {
        return 1;
    }
    // If index is 0, delete the head node and return 3
    if (index == 0) {
        Node* temp = *head;
        *head = temp->next;
        free(temp);
        return 3;
    }

    Node* current = *head;
    int i = 0;

    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    // If index is out of bounds or if the next node is NULL, return 2
    if (current == NULL || current->next == NULL) {
        return 2;
    }
    // If the node at the index is found, delete it and return 3    
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);

    return 3;
}

// Function to display the menu
void displayMenu(void) 
{
    printf("\n--- Malaysia States & Territories Linked List ---\n");
    printf("1. Insert a new state/territory\n");
    printf("2. Display list \n");
    printf("3. Sort list (Ascending Order)\n");
    printf("4. Sort list (Descending Order)\n");
    printf("5. Search for a state/territory\n");
    printf("6. Delete a state/territory\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}
#include <stdio.h>

void initializeArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        A[i] = -1;
    }
}

int showMenu() {
    int choice;
    printf("======== MENU ================\n");
    printf("1--> Insert a new ID\n");
    printf("2--> Find an ID\n");
    printf("3--> Show all IDs\n");
    printf("4--> Exit\n");
    printf("Select an option (1,2,3,4): ");
    scanf("%d", &choice);
    return choice;
}

void insertID(int A[], int size, int ID) {
    int index = ID % size;
    int i = 0;
    while (i < size) {
        if (A[index] == -1) {
            A[index] = ID;
            printf("ID %d inserted at index %d.\n", ID, index);
            return;
        }
        index = (index + 1) % size;
        i++;
    }
    printf("The array is full.\n");
}

void findID(int A[], int size, int ID) {
    int index = ID % size;
    int i = 0;
    while (i < size) {
        if (A[index] == ID) {
            printf("ID %d found at index %d.\n", ID, index);
            return;
        }
        if (A[index] == -1) {
            printf("ID %d not found.\n", ID);
            return;
        }
        index = (index + 1) % size;
        i++;
    }
    printf("ID %d not found.\n", ID);
}

void showAllIDs(int A[], int size) {
    printf("All IDs in the array:\n");
    for (int i = 0; i < size; i++) {
        if (A[i] != -1) {
            printf("Index %d: %d\n", i, A[i]);
        }
    }
}

void processChoice(int choice, int A[], int size) {
    int ID;
    if (choice == 1) {
        printf("Enter a new ID: ");
        scanf("%d", &ID);
        insertID(A, size, ID);
    } else if (choice == 2) {
        printf("Enter an ID to find: ");
        scanf("%d", &ID);
        findID(A, size, ID);
    } else if (choice == 3) {
        showAllIDs(A, size);
    } else if (choice == 4) {
        printf("Exiting...\n");
    } else {
        printf("Invalid option. Please try again.\n");
    }
}

int main() {
    int A[100];
    int size = 100;
    int choice;

    initializeArray(A, size);

    choice = showMenu();
    while (choice != 4) {
        processChoice(choice, A, size);
        choice = showMenu();
    }

    return 0;
}

#include <stdio.h>

int Show_Menu() {
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

int Insert(int A[], int ID) {
    int index = ID % 100;
    for (int i = 0; i < 100; i++) {
        if (A[index] == -1) {
            A[index] = ID;
            return index;
        }
        index = (index + 1) % 100;
    }
    printf("The array is full.\n");
    return -2;
}

int Find(int A[], int ID) {
    int index = ID % 100;
    for (int i = 0; i < 100; i++) {
        if (A[index] == ID) {
            return index;
        }
        if (A[index] == -1) {
            return -2;
        }
        index = (index + 1) % 100;
    }
    return -2;
}

void Show_All(int A[]) {
    printf("All IDs in the array:\n");
    for (int i = 0; i < 100; i++) {
        if (A[i] != -1) {
            printf("Index %d: %d\n", i, A[i]);
        }
    }
}

int main() {
    int A[100],choice, ID, result;
    for (int i = 0; i < 100; i++) {
        A[i] = -1;
    }
    while (1) {
        choice = Show_Menu();

        switch (choice) {
            case 1:
                printf("Enter a new ID: ");
                scanf("%d", &ID);
                result = Insert(A, ID);
                if (result != -2) {
                    printf("ID %d inserted at index %d.\n", ID, result);
                }
                break;
            case 2:
                printf("Enter an ID to find: ");
                scanf("%d", &ID);
                result = Find(A, ID);
                if (result != -2) {
                    printf("ID %d found at index %d.\n", ID, result);
                } else {
                    printf("ID %d not found.\n", ID);
                }
                break;
            case 3:
                Show_All(A);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

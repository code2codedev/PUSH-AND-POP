#include <stdio.h>

#define MAX 10

int arr[MAX];
int size = 0;   /* number of elements currently stored */

/* DISPLAY: show all elements with their positions */
void display() {
    int i;

    if (size == 0) {
        printf("ARRAY IS EMPTY!\n");
        return;
    }

    printf("Array elements:\n");
    for (i = 0; i < size; i++) {
        printf("Index %d : %d\n", i, arr[i]);
    }
}

/* TRAVERSE: visit every element from first to last */
void traverse() {
    int i;

    if (size == 0) {
        printf("ARRAY IS EMPTY! Nothing to traverse.\n");
        return;
    }

    printf("Traversing array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* INSERT: add a value at a given position (shifts elements right) */
void insert(int pos, int value) {
    int i;

    if (size == MAX) {
        printf("ARRAY IS FULL! Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > size) {
        printf("INVALID POSITION! Choose 0 to %d.\n", size);
        return;
    }

    for (i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    size++;
    printf("%d inserted at index %d.\n", value, pos);
}

/* DELETE: remove the value at a given position (shifts elements left) */
void delete_at(int pos) {
    int i, removed;

    if (size == 0) {
        printf("ARRAY IS EMPTY! Nothing to delete.\n");
        return;
    }
    if (pos < 0 || pos >= size) {
        printf("INVALID POSITION! Choose 0 to %d.\n", size - 1);
        return;
    }

    removed = arr[pos];
    for (i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("%d deleted from index %d.\n", removed, pos);
}

/* SEARCH: linear search for a value */
void search(int value) {
    int i, found = 0;

    for (i = 0; i < size; i++) {
        if (arr[i] == value) {
            printf("%d found at index %d.\n", value, i);
            found = 1;
        }
    }
    if (!found) {
        printf("%d not found in the array.\n", value);
    }
}

/* UPDATE: replace the value at a given position */
void update(int pos, int value) {
    int old;

    if (size == 0) {
        printf("ARRAY IS EMPTY! Nothing to update.\n");
        return;
    }
    if (pos < 0 || pos >= size) {
        printf("INVALID POSITION! Choose 0 to %d.\n", size - 1);
        return;
    }

    old = arr[pos];
    arr[pos] = value;
    printf("Index %d updated: %d -> %d.\n", pos, old, value);
}

int main() {
    int choice, pos, value;

    do {
        printf("\n===== ARRAY OPERATIONS =====\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Traverse\n");
        printf("6. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position (0 to %d): ", size);
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(pos, value);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete_at(pos);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 4:
                printf("Enter position to update: ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(pos, value);
                break;

            case 5:
                traverse();
                break;

            case 6:
                display();
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("INVALID CHOICE! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

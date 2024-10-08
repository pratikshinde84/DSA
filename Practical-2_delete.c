#include <stdio.h>
#define SIZE 50

int main() {
    int arr[SIZE];
    int n = 10;
    int choice, position;

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Delete from Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Specific Position\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                    for (int i = 0; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                break;

            case 2:
                    n--;
                break;

            case 3:
                    printf("Enter position (1 to %d): ", n);
                    scanf("%d", &position);
                    if (position < 1 || position > n) {
                        printf("Invalid position! Please enter a valid position.\n");
                    } else {
                        for (int i = position - 1; i < n - 1; i++) {
                            arr[i] = arr[i + 1];
                        }
                        n--;
                    }
                break;
        }
    } while (choice != 4);

    return 0;
}

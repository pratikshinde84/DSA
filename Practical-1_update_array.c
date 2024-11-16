#include <stdio.h>
#include<conio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int index, newValue;
    printf("Enter the index to update: ");
    scanf("%d", &index);
    printf("Enter the new value: ");
    scanf("%d", &newValue);
    arr[index] = newValue;
    printf("Updated element at index %d to %d\n", index, arr[index]);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    getch();
}
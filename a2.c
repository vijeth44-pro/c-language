//swapping two elements
#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter Two Numbers:");
    scanf("%d%d", &a, &b);
    printf("Before Swapping: a:%d, b:%d\n", a, b);

    temp = a;
    a = b;
    b = temp;

    printf("Swapped elements are:\n");
    printf("a:%d\n", a);
    printf("b:%d\n", b);

    return 0;
}

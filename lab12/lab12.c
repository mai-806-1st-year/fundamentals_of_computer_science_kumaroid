#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void read_array(int n, int** values) {
    for (int i = 0; i < n; ++i) {
        printf("values[%d] = ", i);
        scanf("%d", &((*values)[i]));
    }
}

void print_array(int n, int* values) {
    for (int i = 0; i < n; ++i) {
        printf("values[%d] = %d\n", i, values[i]);
    }
}

void shift_left(int *a, int n) {
    if (0 == n)
        return;
    int first = a[0];
    
    for (int i = 1; i < n; ++i)
        a[i-1] = a[i];
    
    a[n-1] = first;
}

void shift_left_on(int *a, int n, int shift_size) {
    for (int i = 0; i < shift_size; ++i) {
        shift_left(a, n);
    }
}
int main() {
    int n, m;
    int *values;
    
    printf("n: ");
    scanf("%d", &n);
    
    printf("m: ");
    scanf("%d", &m);
    
    int array_size = n+m;
    
    values = malloc(sizeof(int) * array_size);
    
    read_array(array_size, &values);
    
    shift_left_on(values, array_size, m);
    
    printf("\n");
    print_array(array_size, values);

    return 0;
}

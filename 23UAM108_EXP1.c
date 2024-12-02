#include <stdio.h>
#include <math.h>

int func(int n, int a[]) {
    int i, sum = 0, avg;
    for (i = 0; i < n; i++) { // Loop should iterate from 0 to n-1
        sum += a[i];         // Correct indexing of array elements
    }
    avg = sum / n;           // Average calculation (sum / n)
    return avg;
};

int main() {
    int std, n, var, i, avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n], u[n], U[n];    // Declaring arrays

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) { // Loop should iterate from 0 to n-1
        scanf("%d", &a[i]);   // Correct indexing of input
    }

    avg = func(n, a);        // Get average using func()

    for (i = 0; i < n; i++) { // Loop should iterate from 0 to n-1
        u[i] = a[i] - avg;    // Calculate deviation
        U[i] = u[i] * u[i];   // Square the deviation
    }

    var = func(n, U);        // Variance is the average of squared deviations

    std = sqrt(var);         // Standard deviation is square root of variance

    printf("Standard Deviation: %d\n", std); // Print the standard deviation

    return 0;
}


#include <stdio.h>
#include <pthread.h>

#define MAX 100

// Global variables
int a[MAX];
int m1, m2, n;

// Thread 1: Finds the max in the first half of the array
void *fm1(void *args) {
    m1 = a[0];
    int i;
    for (i = 1; i < n / 2; i++) {
        if (a[i] > m1) {
            m1 = a[i];
        }
    }
    pthread_exit(NULL);
}

// Thread 2: Finds the max in the second half of the array
void *fm2(void *args) {
    m2 = a[n / 2];
    int i;
    // Note: There is a likely bug here, see explanation below
    for (i = n / 2 + 1; i < n; i++) {
        if (a[i] > m1) { // This should likely be if (a[i] > m2)
            m2 = a[i];
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Create two threads to find the max in each half
    pthread_create(&t1, NULL, fm1, NULL);
    pthread_create(&t2, NULL, fm2, NULL);

    // Wait for both threads to complete
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Determine the overall maximum
    int om = (m1 > m2) ? m1 : m2;
    printf("Max value = %d\n", om);

    return 0;
}

// Enter number of elements: 8
// Enter elements:
// 3 5 2 9 12 4 8 1
// Max value = 12
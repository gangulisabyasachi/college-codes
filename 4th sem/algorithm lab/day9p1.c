#include <stdio.h>
#include <string.h>

// Function to build the partial match table (also known as the "failure function")
void buildKMPTable(char *P, int M, int *lps) {
    int length = 0; // Length of the previous longest prefix suffix
    lps[0] = 0; // lps[0] is always 0
    int i = 1;

    // Loop to fill lps array
    while (i < M) {
        if (P[i] == P[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to perform KMP search
void KMPSearch(char *T, char *P) {
    int N = strlen(T); // Length of the text
    int M = strlen(P); // Length of the pattern

    // Create the LPS array to store the longest prefix suffix values
    int lps[M];
    buildKMPTable(P, M, lps);

    int i = 0; // index for T (text)
    int j = 0; // index for P (pattern)

    // Start matching process
    while (i < N) {
        if (P[j] == T[i]) {
            i++;
            j++;
        }

        // If we have matched the entire pattern
        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1]; // Get the next position to check
        }
        // Mismatch after j matches
        else if (i < N && P[j] != T[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    char text[1000], pattern[100];
    
    // Taking input from the user
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character at the end

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove newline character at the end

    // Perform the KMP search
    KMPSearch(text, pattern);

    return 0;
}

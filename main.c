#include <stdio.h>

/* ============================================================
   SECTION 1 - Declaring, accessing, and modifying arrays
   ============================================================ */
void section1_declare_access(void) {
    printf("--- Section 1: Declare & Access ---\n");

    int A[] = {1, 2, 3};

    printf("%d\n", A[0]);   // 1
    printf("%d\n", A[1]);   // 2
    printf("%d\n", A[2]);   // 3
    // printf("%d\n", A[3]);  
                               // (garbage, crash, or silent corruption)

    A[2] = 100;              // modifying an element
    printf("A[2] after modify: %d\n\n", A[2]);
}

/* ============================================================
   SECTION 2 - Looping through arrays (fixed size vs sizeof trick)
   ============================================================ */
void section2_loops(void) {
    printf("--- Section 2: Loops & sizeof ---\n");

    int A[] = {1, 2, 3};

    // Fixed loop - you already know the size
    printf("Fixed loop: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    // sizeof trick to get size without hardcoding it
    printf("sizeof(A[0]) = %zu (bytes per int)\n", sizeof(A[0]));
    printf("sizeof(A)    = %zu (total bytes)\n", sizeof(A));

    int size = sizeof(A) / sizeof(A[0]);
    printf("Computed size = %d\n", size);

    // Dynamic loop using computed size
    printf("Dynamic loop: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n\n");
}

/* ============================================================
   SECTION 3 - Strings as a special case of char arrays
   ============================================================ */
void section3_strings(void) {
    printf("--- Section 3: Strings ---\n");

    char name[] = "menna";

    printf("%c\n", name[0]);   // m  (single character)
    printf("%s\n", name);      // menna (whole string, stops at '\0')
    printf("\n");
}

/* ============================================================
   SECTION 4 - Pass by value (int) vs pass by reference (array)
   ============================================================ */
void add2_value(int n) {
    n = n + 2;   // only changes the LOCAL copy
}

void add2_array(int n[]) {
    n[0] = n[0] + 2;   // changes the ORIGINAL array's data
}

void section4_value_vs_reference(void) {
    printf("--- Section 4: Pass by value vs. array ---\n");

    int x = 2;
    add2_value(x);
    printf("x after add2_value: %d (unchanged)\n", x);

    int arr[] = {1, 2, 3, 4, 5};
    add2_array(arr);
    printf("arr[0] after add2_array: %d (changed)\n\n", arr[0]);
}

/* ============================================================
   SECTION 5 - Proof: arrays decay to a pointer (same address)
   ============================================================ */
void print_address(int n[]) {
    printf("Address inside function: %p\n", (void *)n);
}

void section5_pointer_proof(void) {
    printf("--- Section 5: Pointer decay proof ---\n");

    int arr[] = {1, 2, 3, 4, 5};
    printf("Address outside function: %p\n", (void *)arr);
    print_address(arr);   // should print the SAME address
    printf("\n");
}

/* ============================================================
   MAIN - run every section in order
   ============================================================ */
int main(void) {
    section1_declare_access();
    section2_loops();
    section3_strings();
    section4_value_vs_reference();
    section5_pointer_proof();
    return 0;
}
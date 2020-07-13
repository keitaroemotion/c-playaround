#include <stdio.h>

void test_assignment_operator();

int main(int argc, char *argv[]) {
    test_assignment_operator();
    return 0;
}

void test_assignment_operator() {
                        // OR
    int v1 = 10;        // 1010
    v1 |= 1;            // 0001 
                        // ----
    printf("%d\n", v1); // 1011 =  11 
                        // OR
    int v2 = 10;        // 1010
    v2 |= 5;            // 0101 
                        // ----
    printf("%d\n", v2); // 1111 = 15 
}

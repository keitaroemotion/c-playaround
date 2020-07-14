#include <stdio.h>

void test_assignment_operator();
void test_inline_asm();

int main(int argc, char *argv[]) {
    test_assignment_operator();
    test_inline_asm();
    return 0;
}

int sum;

//
// inline assembly sample
//
void test_inline_asm() {
    __asm__(
        "mov $100, %rax;"
        "add $200, %rax;"
        "mov %rax, _sum(%rip);"
    );
    printf("The sum is %d.\n", sum);
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

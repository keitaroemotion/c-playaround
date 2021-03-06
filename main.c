#include <stdio.h>

void test_assignment_operator();
void test_inline_asm();
void test_inline_asm2();
void test_size_of();

int x = 10, y = 20, sum;

int main(int argc, char *argv[]) {
    test_assignment_operator();
    test_inline_asm();
    test_size_of();
    return 0;
}

//
//
// inline assembly sample: * this code targets MacOSX(64bit)
//
void test_inline_asm() {
    __asm__(
        "mov $100,     %rax;"
        "add $200,     %rax;"
        "add _x(%rip), %rax;"
        "add _y(%rip), %rax;"
        "mov %rax,     _sum(%rip);"
    );
    printf("The sum is %d.\n", sum);

    __asm__(
        "mov  %%rdx, %%rax;"
        "imul %%rcx, %%rax;"
        "xor  %%rsi, %%rsi;"
        "mov  $1,    %%rsi;"
        "add  %%rsi, %%rax;"
        :"=a"(sum)
        :"d"(x), "c"(y)
        :"rsi"
    );
    printf("Another sum is %d.\n", sum);
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

void test_size_of() {
   printf("%lu\n", sizeof("people") / sizeof(char)); 
   double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
   printf("%lu\n", sizeof(balance) / sizeof(balance[0])); 
}

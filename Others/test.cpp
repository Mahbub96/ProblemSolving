
#include <stdio.h>

int main() {
    // Write C code here
    if(fork() && fork())
        fork();
    printf("Hello ");
    
    return 0;
}

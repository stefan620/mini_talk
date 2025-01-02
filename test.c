#include <stdio.h>

// this method will print all the 32 bits of a number
void decimalToBinary(int num) {
    // assuming 32-bit integer
    for (int i = 7; i >= 0; i--) {
        
        // calculate bitmask to check whether
        // ith bit of num is set or not
        int mask = (1 << i);
        
        // ith bit of num is set 
        if (num & mask)
           printf("1");
        // ith bit of num is not set   
        else 
           printf("0");
    }
    printf("\n");   
    num = 127;
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", num >> i & 1);
    }
}

int main() {
   int num = 32;
   decimalToBinary(num);
   return 0;
}
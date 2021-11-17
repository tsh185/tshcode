/*happy number*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BITSIZE (32)
#define ARRSIZE (1000/32 + 1)
#define BIT(x) (1 << (x))

int next_n(int n)
{
    int d, sum = 0;
    do {
        d = n % 10;
        sum += d * d;
        n /= 10;
    } while(n != 0); 

    return sum;
}

#if 0 
void cls_bit(int *history, int n)
{
    int idx = n / BITSIZE;  
    int left = n % BITSIZE;
    history[idx] &= ~(BIT(left));  
}
#endif

void set_bit(int *history, int n)
{
    int idx = n / BITSIZE;  
    int left = n % BITSIZE;
    history[idx] |= BIT(left);  
}

int test_bit(int *history, int n)
{
    int idx = n / BITSIZE;
    int left = n % BITSIZE;
    return (history[idx] & BIT(left));
}

int is_happy(int n)
{
    int history[ARRSIZE] = {0};
    n = next_n(n);  
    while (!test_bit(history, n)) { 
        set_bit(history, n);
        n = next_n(n);
    } 

    return (n == 1);
}

int main()
{
    int i, k = 1;
    printf("Happy Number: \n");
    for (i = 1; i < 101; i++) {
        if (is_happy(i)) {
            printf("%4d%c", i, k%5==0 ? (k = 0, '\n') : ' ');
            k++;
        }
    }
    printf("\n");
    return 0;
}

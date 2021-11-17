/*happy number*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int contains(int *history, int size, int n)
{
    int i;
    for (i = 0; i < size; i++) {
        if (history[i] == n) return 1;
    }
    return 0;
}

int is_happy(int n)
{
    int history[1000];
    int size = 0;
    n = next_n(n);
    while (!contains(history, size, n)) { 
        history[size++] = n;
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

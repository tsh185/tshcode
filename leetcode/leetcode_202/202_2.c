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


int is_happy(int n)
{
    int slow = n;
    int fast = n;
    
    do {
        slow = next_n(slow);
        fast = next_n(next_n(fast));
        //fast = next_n(fast);
        //fast = next_n(fast);
    } while (slow != fast);

    return (slow == 1);
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

#include <stdio.h> 
#include <stdlib.h>
#include<conio.h>

#define MAX(a,b) ((a > b))? (a) : (b)
#define MIN(a,b) ((a < b))? (a) : (b)

int sign(int a)
{
    if (a > 0){
        return 1;
    }

    if (a == 0){
        return 0;
    }

    return -1;
}

int main()
{
    int i = 24;
    int j = -14;
    int l = 9;
    int f = 0;
    int ik = i, jk = j, lk = l;

    for (int k = 0; k <= 50; ++k)
    {
        
        i = ik;
        j = jk;
        l = lk;

        ik = ((i + k)*(j - k)*(l+k))%25;

        jk = MIN((i+k),MAX((j-k),(l-k)));

        lk = abs(j-k)*sign(i) - abs(i-l)*sign(j);

        printf("%d, %d, %d, %d\n", k, ik, jk, lk);

        if ((ik >= 5 && ik <= 15) && (jk <= -5 && jk >= -15)){
            f = 1;
            printf("got it in %d = count of attempts, %d = x coord, %d = y coord, %d\n", k, ik, jk, lk);
            break;
        }
    }
    if (f==0)
    {
        printf("missed. %d - x coord, %d - y coord, %d - l variable \n", ik, jk, lk);
    }

    return 0;
}

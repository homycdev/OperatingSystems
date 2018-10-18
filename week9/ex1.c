#include <stdio.h>
#include <stdlib.h>

const int NF = 10,NB = 31, EV = -1, RE = 1;

int p[NF];
int a[NF];

int main()
{
    FILE *fp = fopen("lab9.txt", "r");
    int i;
    for (i = 0; i < NF; i++)
        p[i] = EV;
    i = 0;
    int t = 0, n_of_miss = 0, j;

    while (fscanf(fp, "%d", &j) == RE)
    {
        int fault = 1;
        int elder = 0;

        for (i = 0; i < NF; i++)
        {
            if (p[i] == j)
            {
                a[i] = (1 << (NB - 1)) & (a[i] >> 1);
                fault = 0;
            }
            else
            {
                a[i] = a[i] >> 1;
            }
            if (a[i] < a[elder] || p[i] == EV)
                elder = i;
        }

        ++t;
        if (!fault)
            continue;
        ++n_of_miss;
        a[elder] = 1 << (NB - 1);
        p[elder] = j;
    }

    printf("frames => %d\t in total => %d\t #hits => %d\t #misses => %d\n", NF, t, t - n_of_miss, n_of_miss);
    printf("hits/miss => %.2f\n", (double)(t - n_of_miss) / (n_of_miss));

    return 0;
}
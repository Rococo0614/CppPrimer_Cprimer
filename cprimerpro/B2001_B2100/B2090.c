#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    if(scanf("%d",&N) != 1)
    return -1;

    int *people = malloc(N*sizeof(int));
    double a,b,c,d;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &people[i]);
        if(people[i] <= 18)
        a++;
        else if(people[i] > 18 && people[i] <= 35)
        b++;
        else if(people[i] > 35 && people[i] <= 60)
        c++;
        else
        d++;
    }

    printf("%.2lf%%\n%.2lf%%\n%.2lf%%\n%.2lf%%\n", a / N * 100, b / N * 100, c / N * 100, d / N * 100);
    free(people);
    return 0;
}
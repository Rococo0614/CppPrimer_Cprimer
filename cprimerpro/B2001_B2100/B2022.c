#include <stdio.h>

int main()
{
    char s1;
    int s2;
    float s3;
    double s4;
    scanf(" %c", &s1);
    scanf("%d", &s2);
    scanf("%f", &s3);
    scanf("%lf", &s4);
    printf("%c %d %.6f %.6lf", s1, s2, s3, s4);
    return 0;
}
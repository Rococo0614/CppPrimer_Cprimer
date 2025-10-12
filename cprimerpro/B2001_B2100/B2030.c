#include <stdio.h>
#include <math.h>

int main()
{
    double xa, ya, xb, yb, distance;
    scanf("%lf %lf", &xa, &ya);
    scanf("%lf %lf", &xb, &yb);
    distance = sqrt(((xa - xb) * (xa - xb)) + ((ya - yb) * (ya - yb)));
    printf("%.3lf", distance);
    return 0;
}
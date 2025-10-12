#include <stdio.h>

int main()
{
    double distance, Walktime, Biketime;
    scanf("%lf", &distance);
    Walktime = distance / 1.2;
    Biketime = distance / 3 + 27 + 23;
    if(Walktime > Biketime)
    printf("Bike");
    else if(Walktime < Biketime)
    printf("Walk");
    else
    printf("All");
    return 0; 

}
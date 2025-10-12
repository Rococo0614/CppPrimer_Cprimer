#include <stdio.h>
#include <string.h>

#define len 9

struct patient{
    char name[len];
    float temperature;
    int ifcough;
};

int main()

{
    int num;
    if(scanf("%d", &num) != 1)
    return -1;

    struct patient people[num];
    for(int i = 0; i < num; i++)
    {
        scanf("%s %f %d", people[i].name, &people[i].temperature, &people[i].ifcough);
    }

    int infected = 0;
    for(int i = 0; i < num; i++)
    {
        if(people[i].temperature >=37.5 && people[i].ifcough == 1){
        printf("%s\n", people[i].name);
        infected++;
        }

    }
    printf("%d", infected);
    return 0;
}
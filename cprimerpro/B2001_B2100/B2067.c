#include <stdio.h>
#include <stdlib.h>


int main()
{
    int total_medicine;
    int people_count;
    scanf("%d", &total_medicine);
    scanf("%d", &people_count);
    int *pills_take = malloc(people_count * sizeof(int));
    for(int i = 0; i < people_count; i++)
    scanf("%d", &pills_take[i]);

    int not_get_pills = 0, get_pills = 0;
    for(int i = 0; i < people_count; i++)
    {
        if(total_medicine >= pills_take[i])
        {
            total_medicine -= pills_take[i];
            get_pills++;
        }
        else if(total_medicine < pills_take[i])
        not_get_pills++;
    }

    printf("%d", not_get_pills);
    
    return 0;

}
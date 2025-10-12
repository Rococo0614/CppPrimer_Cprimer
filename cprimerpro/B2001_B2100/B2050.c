#include <stdio.h>

int main()
{
    int length[3],tri=0;
    for(int i = 0; i < 3; i++)
    scanf("%d", &length[i]);
    for(int i = 0; i < 3; i++)
    {
        if(length[i] < length[(i + 1) % 3] + length[(i + 2) % 3] )
        tri++;
        else 
        tri = 0;
    }
    if(tri == 3)
    printf("1");
    else
    printf("0");
    return 0;
}
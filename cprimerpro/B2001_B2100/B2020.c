#include <stdio.h>

int main()
{
    int candy[5], next[5], candyeat = 0;
    for (int i = 0; i < 5; i++)
    scanf("%d", &candy[i]);

    for (int i = 0; i < 5; i++)
    {
        next[i] = candy[i] / 3;
        candyeat += candy[i] % 3;
        candy[(i+1) % 5] = candy[(i+1) % 5] + candy[i] / 3;
        candy[(i+4) % 5] = candy[(i+4) % 5] + candy[i] / 3;
        next[(i+1) % 5] = candy[(i+1) % 5];
        next[(i+4) % 5] = candy[(i+4) % 5];
        candy[i] = next[i];
    }

    for (int i = 0; i < 5; i++)
    printf("%d ", next[i]);
    printf("\n%d", candyeat);
    return 0;
}
//为了提高可读性及方便之后的迭代扩展，我们建议将程序的输入变量与迭代变量分开，在循环中不要更改最初输入变量。
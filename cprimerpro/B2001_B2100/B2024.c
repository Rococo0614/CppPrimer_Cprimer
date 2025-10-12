#include <stdio.h>

int main()
{
    double num;
    scanf("%lf", &num);
    printf("%f\n", num);
    printf("%.5f\n", num);
    printf("%e\n", num);
    printf("%g\n", num);
    return 0;
}
//根据数值的大小，决定使用哪种形式：

//如果 指数（即 e 的幂）大于等于 -4 或小于给定有效位数，用 %f

//否则用 %e

//默认保留 6 位有效数字（而不是固定的小数位数）

//会自动去掉末尾的 0 和小数点（如果后面没有数字）
#include <stdio.h>
void string();
 
int main()
{
    printf("请输入一个字符串\n");
    string();
    printf("\n");
    return 0;
}
 
void string()
{
    char c;
    scanf("%c", &c);
    if (c != '\n')
    {
        string();
        printf("%c", c);
    }
}
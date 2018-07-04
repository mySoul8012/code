#include <stdio.h>
#include <string.h>
 
char* move(char *p_str);
 
int main()
{
    char str[50];
 
    printf("请输入要翻转前的字符串\n");
    scanf("%s", str);
 
    printf("翻转后的字符串为\n");
    printf("%s\n", move(str));
 
    return 0;
}
 
// 字符串翻转
char* move(char *p_str)
{
    int i, j;
    char tmp;
 
    i = 0;
    j = strlen(p_str) - 1;
    while(i < j)
    {
        tmp = *(p_str + i);
        *(p_str + i) = *(p_str + j);
        *(p_str + j) = tmp;
        i++;
        j--;
    }
 
    return p_str;
}
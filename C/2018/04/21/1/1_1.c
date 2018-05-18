#include <stdio.h>

int main ()
{
	int i;
	char letter, judge;

	printf("Uppercase u,A lowercase letter l\n");
	scanf("%c", &letter);

	judge=(letter=='u')?'A':'a';

	for(i=0; i<=25; i++)
	{
		printf("%c\t", judge + i);
	}

	printf("\n");

	getchar();getchar();

	return 0;
}
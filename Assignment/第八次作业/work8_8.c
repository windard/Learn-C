#include<stdio.h>
int main (void)
{
	int			arr[]={3,1,4,2,5};
	int			i;
	int			*piarr[5];
	int			m;
	int			j;

	
	for(i=0;i<5;i++)
	{
		piarr[i]=&arr[i];
		printf("%4d",arr[i]);
	}

	printf("\n");

	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(*piarr[i]<*piarr[j])
			{
				m=*piarr[i];
				*piarr[i]=*piarr[j];
				*piarr[j]=m;
			}
		}
	}
	
	for(i=0;i<5;i++ )
	printf("%4d",*piarr[i]);
	return 0;

}

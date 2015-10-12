/************************************

  **内容：第八次上机作业第三题
  **作者：空间科学技术学院实验班 杨文强
  **时间：2014年12月9日
  **邮箱：18607571914@163.com
  
************************************/

#include<stdio.h>
#include<math.h>
#include"tri_area.h"

int main (void)
{
	int			a,b,c;
	double		m;

	printf("Please input a,b,c:\n");

	scanf("%d%d%d",&a,&b,&c);

	m=tri_area(a,b,c);

	if(m==-1)
		printf("Your input is wrong \n");

	else
	{
		printf("The area is %f \n",m);
	}




	return 0;
}


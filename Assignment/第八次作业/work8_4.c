/************************************

  **内容：第八次上机作业第四题
  **作者：空间科学技术学院实验班 杨文强
  **时间：2014年12月9日
  **邮箱：18607571914@163.com
  
************************************/
#include<stdio.h>
#include"is_perfect_num.h"

int main (void)
{
	int			a;
	int			i;

	for(i=1;i<1000;i++)
	{
		a=is_perfect_num(i);
		if(a)
			printf("%4d\n",i);
	}
		
	return 0;

}



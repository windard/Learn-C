/************************************

  **内容：第八次上机作业第二题
  **作者：空间科学技术学院实验班 杨文强
  **时间：2014年12月9日
  **邮箱：18607571914@163.com
  
************************************/

#include <stdio.h>
#include <math.h>

int			x1,x2;

int root (double a,double b,double c);

int main (void)
{
	int			a,b,c;
	int			m;

	printf("Please input  a,b,c :\n");
	scanf("%d%d%d",&a,&b,&c);

	m=root(a,b,c);

	if(m==-1)
	printf("The question has no answer\n");
	else if(m==1)
	printf("The question has two same answer is %d\n",x1);
	else if(m==2)
	printf("The question has two different answer is %d and %d\n",x1,x2);



	return 0;
}

int root (double a,double b,double c)
{
	int			m;


	m=b*b-4*a*c;
	if(m<0)
		return -1;
	else if(m==0)
	{
		x1=x2=(-b)/(2*a);
		return 1;
	}
	else if(m>0)
	{
		x1=((-b)+sqrt(m))/(2*a);
		x2=((-b)-sqrt(m))/(2*a);
		return 2;
	}


}
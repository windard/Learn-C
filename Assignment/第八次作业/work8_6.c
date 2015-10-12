/************************************

  **内容：第八次上机作业第六题
  **作者：空间科学技术学院实验班 杨文强
  **时间：2014年12月9日
  **邮箱：18607571914@163.com
  
************************************/

#include<stdio.h>
#include<math.h>

int root(double a,double b,double c,double *x1,double *x2);

int main (void)
{
	double			a;
	double			b;
	double			c;
	double			x1;
	double			x2;

	int				root_num=1;

	printf("Please input the coefficients of the equation\n");
	scanf("%d%d%d",&a,&b,&c);

	root_num = root (a,b,c,&x1,&x2);

	if(root_num !=0)
	{
		printf("There are %d roots for the equtation:\n",root_num);
		printf("x1 = %f\n",x1);
		printf("x2 = %f\n",x2);
	}
	else
		printf("No roots for the equtation.\n");

	return 0;
}

int root (double a,double b,double c,double *x1,double *x2)
{
	double		m;

	m = b*b-4*a*c;
	if(m<0)
		return  1;
	else
	{
		*x1=((-b)+sqrt(m))/(2*a);
		*x2=((-b)-sqrt(m))/(2*a);
		return 2;
	}
}
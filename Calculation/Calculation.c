#include<stdio.h>
#include<conio.h>
int main (void)
{	
	int				x;
	int				y;
	double	  		m;
	int				a;

	printf("********************************************\n\n");
	printf("           ASIORS科学计算器                   \n");
	printf("                        杨文强设计开发2014版  \n");
	printf("\n********************************************\n");

	// printf("\n");

	// printf("请按ENTER以继续操作\n");

	// getchar();

	printf("============================================\n");
	printf("     1   加法               2    减法         \n");
	printf("     3   乘法               4    除法         \n");
	printf("     5   取整               6    取余         \n");
	printf("               7  结束程序                    \n");
	printf("============================================\n");


	printf("温馨提示：只有在输入7时才能结束程序:)\n");

	printf("请按ENTER以继续操作\n");

	getchar();


	for(;a!=7;)
	{
	printf("\n请选择所需操作:\n");
	scanf("%d",&a);

	if(a<1||a>7)
		printf("你的选择有误，请再输入一次:\n");
	else
	{

	printf("你选择的是 : %d\n",a);
	switch(a)
	{
	case 1:
		printf("加法\n");
		break;
	case 2:
		printf("减法\n");
		break;
	case 3:
		printf("乘法\n");
		break;
	case 4:
		printf("除法\n");
		break;
	case 5:
		printf("取整\n");
		break;
	case 6:
		printf("取余\n");
		break;
	case 7:
		printf("结束\n");
		printf("感谢您的使用\n");
		break;

	}

	if(a!=7)
	{
	printf("请输入两个值：\n");
	scanf("%d%d",&x,&y);


	printf("结果为：\n");
	switch(a)
	{
	case 1:
		printf("%d+%d=%d\n",x,y,x+y);
		break;
	case 2:
		printf("%d-%d=%d\n",x,y,x-y);
		break;
	case 3:
		printf("%d*%d=%d\n",x,y,x*y);
		break;
	case 4:
		m=(double)x/y;
		printf("%d/%d=%.2f\n",x,y,m);
		break;
	case 5:

		printf("%d(/)%d=%d\n",x,y,x/y);
		break;
	case 6:
		printf("%d(%)%d=%d",x,y,x%y);
		break;
	}
	}
	}
	}

	printf("请按ENTER退出\n");
	getchar();
	return 0;
}

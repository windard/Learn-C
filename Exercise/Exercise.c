/*******************第一题****************************************				
#include<stdio.h>

int qiuchangdu (char *str);

int main (void)
{
	char				str[80];
	int					size;
	int					i;

	printf("Please input a string :\n");
	gets(str);

	size=qiuchangdu(str);
	printf("The size of %s is %d\n",str,size);

	return 0;
}

int	qiuchangdu (char *str)
{
		int			size;
		int			i;

		for(i=0;*str!='\0';i++,str++)
		{}
		size=i;

		return (size);

}
************************************************************/

/**********************第二题**************************************
#include<stdio.h>

void process (int a,int b,int *max,int *ave);

int main (void)
{
	int				a;
	int				b;
	int				max;
	int				ave;
	int				* pmax;
	int				* pave;

	printf("Please input two numbers :\n");
	scanf("%d%d",&a,&b);

	pmax=&max;
	pave=&ave;

	process(a,b,pmax,pave);

	printf("The biggest is %d\n",max);
	printf("The ave of numbers is %d\n",ave);

	return 0;
}

void process (int a,int b,int *max,int *ave)
{
	if(a>b)
		*max=a;
	else
		*max=b;

	*ave=(a+b)/2.0;

	return ;
}
***************************************************************/

/***********************第三题***************************************
#include<stdio.h>
int main (void)
{
	int				i;
	int				sum=0;

	for(i=200;i<=300;i++)
	{
		if(i%3==0)
		{
			if(i%4==0)
			{
				sum+=i;
			}
		}
	}

	printf("求200-300之间所有能同时被3和4整除的所有整数之和\n");
	printf("The sum = %d\t (including 300)\n",sum);

	return 0;
}
****************************************************************************/

/***********************第四题*****************************************************
#include<stdio.h>
char *mystrcpy (char *d,char *s);
int main (void)
{
	char				str[80];
	char				arr[80];
	char				*d;
	char				*s;


	printf("Please input your string \n");
	gets(str);

	s=str;
	d=arr;

	d=mystrcpy (d,s);

	puts(d);

	return 0;
}

char *mystrcpy (char *d,char *s)
{
	int					i;

	for(i=0;*s!='\0';s++,d++,i++)
		*d=*s;

	*d='\0';

	for(;i>0;i--,d--)
	{}
	
	return (d);
}
************************************************************************/

/****************************第五题*******************************************
#include<stdio.h>
void	exchange (int *pa,int *pb);
int main (void)
{
	int			a;
	int			b;
	int			*pa;
	int			*pb;

	printf("Please input two numbers \n");
	scanf("%d%d",&a,&b);

	printf("The former are : \n");
	pa=&a;
	pb=&b;

	printf("a=%d\n",a);
	printf("b=%d\n",b);

	exchange(pa,pb);
	printf("\n");

	printf("The later are : \n");
	printf("a=%d\n",a);
	printf("b=%d\n",b);
	
	return 0;
}

void	exchange (int *pa,int *pb)
{
	int			m;

	m=*pa;
	*pa=*pb;
	*pb=m;

	return ;
}
*****************************************************************/

/**************************第六题********************************************************************
#include<stdio.h>
void process(char *pstr,int *pa,int *pb,int *pc,int *pd);
int main (void)
{
	char			str[80];
	char			*pstr;
	int				a=0,*pa=&a;
	int				b=0,*pb=&b;
	int				c=0,*pc=&c;
	int				d=0,*pd=&d;



	printf("Please input a string :\n");
	gets(str);

	printf("\n");
	pstr=str;

	process(pstr,pa,pb,pc,pd);

	puts(str);
	printf("字母的个数: %d\n数字的个数: %d\n空格的个数: %d\n其他字符的个数: %d\n",a,b,c,d);
 
	return 0;
}

void process(char *pstr,int *pa,int *pb,int *pc,int *pd)
{
		for(;*pstr!='\0';pstr++)
		{
			if((*pstr>='a'&&*pstr<='z')||(*pstr>='A'&&*pstr<='Z'))
				(*pa)++;
			else if(*pstr>='0'&&*pstr<='9')
				(*pb)++;
			else if(*pstr==' ')
				(*pc)++;
			else
				(*pd)++;
		}

		return ;
}
************************************************************************************************/

/************************第七题************************************************
#include<stdio.h>
int main (void)
{
	int				i;
	int				sum=0;
	int				j;
	int				m;

	for(i=200;i<300;i++)
	{
		m=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				m=0;
				break;
			}
		}
		if(m)
		{
			sum+=i;
		}
	}

	printf("求100-200之间所有素数之和\n");
	printf("The sum is : %d\n",sum);
	return 0;
}
**********************************************************************/

/*************************第八题********************************************
#include<stdio.h>
int main (void)
{
	int			arr[5];
	int			i;
	int			j;
	int			m;

	printf("Please input 5 numbers :\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("\nThe former arr is : \n");
	for(i=0;i<5;i++)
		printf("%4d",arr[i]);

	for(i=0;i<5;i++)
	{
		for(j=i;j<5;j++)
		{
			if(arr[i]<arr[j])
			{
				m=arr[i];
				arr[i]=arr[j];
				arr[j]=m;
			}
		}
	}

	printf("\nThe later arr is : \n");
	for(i=0;i<5;i++)
		printf("%4d",arr[i]);

	printf("\n");

	return 0;
}
***************************************************************************/

/**************************第九题************************************************
#include<stdio.h>
void find_max(int *a,int n,int *max);
int main (void)
{
	int				arr[5];
	int				*parr;
	int				n;
	int				max=0;
	int				*pmax;
	int				i;

	printf("Please input 5 numbers :\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	n=sizeof(arr)/sizeof(arr[0]);

	parr=arr;
	pmax=&max;
	find_max (parr,n,pmax);

	printf("The biggest number is : %d\n",max);

	return 0;
}
void find_max(int *a,int n,int *max)
{
	int				i;
	int				m;

	for(i=0;i<n;i++,a++)
	{
		if(*max<*a)
		{
			m=*max;
			*max=*a;
			*a=m;
		}
	}

	return ;
}
**************************************************************************/

/*************************第十题*************************************************
#include<stdio.h>
int main (void)
{
	char			str[80];
	int				i;
	char			m;
	int				j;
	int				n;

	printf("Please input a string \n");
	gets(str);

	printf("\nThe former string is : \n");
	puts(str);

	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			str[i]=str[i]+'A'-'a';
		}
	}

	printf("\nThe laster string is : \n");
	puts(str);

	n=strlen(str);

	for(i=0;i<n-1-i;i++)
	{
		m=str[i];
		str[i]=str[n-1-i];
		str[n-1-i]=m;
	}

	printf("\nThe lastest string is : \n");
	puts(str);

	return 0;
}
*************************************************************************/

/***************************第十一题**********************************************
#include<stdio.h>
void process(int a,int b,int *max ,int *min);
int main (void)
{
	int				a;
	int				b;
	int				max;
	int				min;
	int				*pmax;
	int				*pmin;

	printf("Please input two numbers : \n");
	scanf("%d%d",&a,&b);

	pmax=&max;
	pmin=&min;

	process(a,b,pmax,pmin);

	printf("Max is : %d\n",max);
	printf("Min is : %d\n",min);

	return 0;
}

void process(int a,int b,int *max ,int *min)
{
	if(a>b)
	{
		*max=a;
		*min=b;
	}
	else
	{
		*max=b;
		*min=a;
	}
	return ;
}
***************************************************************************/

/*****************************第十二题**********************************************
#include<stdio.h>
void find_max (int *a,int n,int *max);
int main (void)
{
	int				str[5];
	int				n;
	int				max=0;
	int				*pstr;
	int				*pmax;
	int				i;

	n=sizeof(str)/sizeof(str[0]);

	printf("Please input 5 numbers : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&str[i]);
	}

	pmax=&max;
	pstr=str;
	find_max (pstr,n,pmax);

	printf("\nMax is %d\n",max);

	return 0;
}

void find_max (int *a,int n,int *max)
{
	int			i;

	for(i=0;i<n;i++,a++)
	{
		if(*max<*a)
			*max=*a;
	}
	return ;
}
****************************************************************************/

/*************************第十三题************************************************
#include<stdio.h>

int qiuchangdu (char *str);

int main (void)
{
	char				str[80];
	int					size;
	int					i;

	printf("Please input a string :\n");
	gets(str);

	size=qiuchangdu(str);
	printf("The size of %s is %d\n",str,size);

	return 0;
}

int	qiuchangdu (char *str)
{
		int			size;
		int			i;

		for(i=0;*str!='\0';i++,str++)
		{}
		size=i;

		return (size);

}
**********************************************************************/

/************************第十四题************************************
#include<stdio.h>
int main (void)
{
	int				str[10];
	int				i;
	int				max;
	int				max_loc;
	int				min;
	int				min_loc;
	int				m;

	printf("Please input 10 numbers :\n");
	for(i=0;i<10;i++)
		scanf("%d",&str[i]);

	min=max=str[0];

	for(i=0;i<10;i++)
	{
		if(max<str[i])
		{
			max=str[i];
			max_loc=i;
		}

		if(min>str[i])
		{
			min=str[i];
			min_loc=i;
		}
	}

	m=str[max_loc];
	str[max_loc]=str[0];
	str[0]=m;

	m=str[min_loc];
	str[min_loc]=str[9];
	str[9]=m;

	printf("\n");
	for(i=0;i<10;i++)
		printf("%4d\n",str[i]);

	return 0;
}
***************************************************************/

/**********************第十五题****************************************
#include<stdio.h>
int main (void)
{
	int					arr[10];
	int					i;
	int					j;
	int					m;

	printf("Please input 10 numbers : \n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}

	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if(arr[i]<arr[j])
			{
				m=arr[i];
				arr[i]=arr[j];
				arr[j]=m;
			}
		}
	}

	for(i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);
	}

	return 0;
}
**********************************************************************/

/**********************第十六题*************************************				
#include<stdio.h>

int qiuchangdu (char *str);

int main (void)
{
	char				str[80];
	int					size;
	int					i;

	printf("Please input a string :\n");
	gets(str);

	size=qiuchangdu(str);
	printf("The size of %s is %d\n",str,size);

	return 0;
}

int	qiuchangdu (char *str)
{
		int			size;
		int			i;

		for(i=0;*str!='\0';i++,str++)
		{}
		size=i;

		return (size);

}
************************************************************/

/**********************第十七题*************************************
#include<stdio.h>

int	chengfang(int a,int b);
int jiecheng (int a);

int main (void)
{
	int				i;	
	double			sum=1;
	int				n;
	int				x;
	double			m;
	double			p;
	
	printf("Your x is :\n");
	scanf("%d",&x);
	printf("Your n is :\n");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		m=(double)chengfang(x,i);
		p=(double)jiecheng(i);
		sum+=m/p;
	}

	printf("Your answer is : %lf\n",sum);

	return 0;
}

int	chengfang(int a,int b)
{
		int		sum=1;
		int		i;

		for(i=1;i<=b;i++)
			sum*=a;

		return (sum);
		
}
int jiecheng (int a)
{
	int			i;
	int			sum=1;

	for(i=1;i<=a;i++)
		sum*=i;

	return (sum);

}
*********************************************************/

/************************第十八题***********************************
#include<stdio.h>

int jiecheng(int a);

int main (void)
{
	int			n;
	int			i;
	double		m;
	double		sum=1;

	printf("Please input your n :\n");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		m=(double)jiecheng(i);
		sum+=1.0/m;
	}

	printf("Your amswer is : %lf\n",sum);

	return 0;
}

int jiecheng (int a)
{
	int			i;
	int			sum=1;

	for(i=1;i<=a;i++)
		sum*=i;

	return (sum);
}
*************************************************************/

/**********************第十九题***************************************
#include<stdio.h>
int main (void)
{
	char			str[80];
	int				i;
	int				m=0;

	printf("Please input your string :\n");
	gets(str);

	for(i=0;str[i]!='\0';i++)
	{
		if((str[i]!=' '&&str[i+1]==' ')||str[i]!=' '&&str[i+1]=='\0')
			m++;
	}

	printf("There are %d words.\n",m);

	return 0;
}
***************************************************************/

/*************************第二十题*************************************
#include<stdio.h>
int main (void)
{
	int			n;
	int			i;
	int			j;

	printf("Please input your number :\n");
	scanf("%d",&n);

	for(i=n;i>0;i--)
	{
		for(j=i;j>0;j--)
			printf("%d",i);
		printf("\n");
	}
	return 0;
}
***************************************************************/

/**************************第二十一题*************************************
#include<stdio.h>

int		jiecheng(int a);
double	fun(int n);

int main (void)
{
	int			n;
	double		sum;

	printf("Please input your n :\n");
	scanf("%d",&n);

	sum=fun(n);

	printf("Your amswer is : %lf\n",sum);

	return 0;
}

int		jiecheng (int a)
{
	int			i;
	int			sum=1;

	for(i=1;i<=a;i++)
		sum*=i;

	return (sum);
}

double	fun(int n)
{
	double		sum=1;
	int			i;
	double		m;

	for(i=1;i<=n;i++)
	{
		m=(double)jiecheng(i);
		sum+=1.0/m;
	}

	return (sum);
}
****************************************************************/

/***********************第二十二题*************************************************
#include<stdio.h>

int fun (int *a,int b);

int main (void)
{
	int			arr[10];
	int			i;
	int			n;
	int			m;
	
	printf("Please input 10 numbers : \n");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);

	printf("\nPlease input your want to find number :\n");
	scanf("%d",&n);

	m=fun(arr,n);

	if(m>=0)
		printf("Your finding is No.%d\n",m);
	else
		printf("Sorry,There is no finding.\n");

	return 0;
}

int fun (int *a,int b)
{
	int			i;
	int			loc=-1;

	for(i=0;i<10;i++,a++)
	{
		if(*a==b)
		{
			loc=i;
			break;
		}
	}

	return(loc);
}
***********************************************************************************/

/******************************第二十三题******************************************************
#include<stdio.h>

int count (char *s,char c);

int main (void)
{
	char			str[80];
	int				i;
	char			c;

	printf("Please input your string : \n");
	gets(str);

	printf("Please input your want to find char :\n");
	scanf("%c",&c);

	i=count(str,c);

	printf("Your char has %d times appreaing.\n",i);

	return 0;
}

int count (char *s,char c)
{
	int				i=0;
	
	for(;*s!='\0';s++)
	{
		if(*s==c)
		{
			i++;
		}
	}
	return (i);
}
*********************************************************************/
		#include<stdio.h>

		

		struct COMPLEX 
		{
			int			real;
			int			img;

		};

		struct  COMPLEX  multi_complex(struct  COMPLEX  x, struct  COMPLEX  y);

		int main (void)
		{
			struct COMPLEX		x;
			struct COMPLEX		y;
			struct COMPLEX		sum;
			struct COMPLEX		multi;

			printf("Please input two number : \n");
			scanf("%d%d",&x.real,&x.img);
			scanf("%d%d",&y.real,&y.img);

			printf("x=\t\t(%d+%di)\n",x.real,x.img);
			printf("y=\t\t(%d+%di)\n",y.real,y.img);
			
			sum.real = x.real + y.real ;
			sum.img  = x.img  + y.img  ;

			printf("sum=\t\t(%d+%di)\n",sum.real,sum.img);

			multi=multi_complex(x,y);
			
			printf("multi=\t\t(%d+%di)\n",multi.real,multi.img);

			return 0;
		}
		
		struct  COMPLEX  multi_complex(struct  COMPLEX  x, struct  COMPLEX  y)
		{
			int						a;
			int						b;
			struct COMPLEX			multi;

			a=x.real * y.real - x.img * y.img  ;
			b=x.real * y.img  + x.img * y.real ;

			multi.real = a;
			multi.img  = b;

			return (multi);
		}
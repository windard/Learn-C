	#include<stdio.h>

	struct  GOODS
	{
		char				name[20];
		int					price;
		int					kucun;
		int					inventory;

	};

	void    print_string(struct GOODS * pstu);
	void	find_good_by_name(struct  GOODS  * goods, char * name);
	void	find_good_by_price(struct  GOODS  * goods, int price);
	void	find_good_by_inventory(struct  GOODS  * goods, int inventory);

	int main (viod)
	{
		struct  GOODS				good[5];
		int							i;
		char						name[20];
		struct  GOODS				*p;
		int							price;
		int							inventory;

		for(i=0;i<5;i++)
		{
		printf("Please input your date :\n");
		printf("Name:\n");
		scanf("%s",good[i].name);
		printf("Price:\n");
		scanf("%d",&good[i].price);
		printf("Kucun:\n");
		scanf("%d",&good[i].kucun);
		printf("Xiaoshouliang:\n");
		scanf("%d",&good[i].inventory);

		printf("\n");
		}

		printf("Press ENTER to show \n");
		getche();

		for(i=0;i<5;i++)
			print_string(&good[i]);

		while(1)
		{
			printf("Please input your finding name :\n");
			printf("Press N to stop\n");
			scanf("%s",name);		
			if(strcmp(name,"N")==0)
				break;
			find_good_by_name(good,name);
		}

		printf("\nPlease input your price:\n");
		scanf("%d",&price);
		find_good_by_price(good,price);

		printf("\nPlease input your inventory:\n");
		scanf("%d",&inventory);
		find_good_by_inventory(good,inventory);

		return 0;
	}


	void   print_string(struct GOODS * pstu)
	{

		int				j;

		printf("Name:\t\t\t%s\n",pstu->name);
		printf("Price:\t\t\t%d\n",pstu->price);
		printf("Kucun:\t\t\t%d\n",pstu->kucun);
		printf("Xiaoshouliang:\t\t%d\n",pstu->inventory);

		printf("\n");
		printf("\n");
		
		return ;
	}
	void	find_good_by_name(struct  GOODS  * goods, char * name)
	{
		struct  GOODS			* p;
		int						m=1;


		for(p=goods;p<(goods+5);p++)
		{
			if(strcmp(p->name,name)==0)
			{
					print_string(p);
					m=0;
			}
		}

		if(m)
		{
			printf("Your input is wrong \n\n");
		}

		return ;
	}
	void	find_good_by_price(struct  GOODS  * goods, int price)
	{
				int				i;
				int				m=1;

				for(i=0;i<5;i++,goods++)
				{
					if(price<goods->price )
					{
						print_string(goods);
						m=0;
					}
				}

				if(m)
					printf("Sorry ,there isn't anything more experience than your price.\n ");

				return ;
	}
	void	find_good_by_inventory(struct  GOODS  * goods, int inventory)
	{
		
				int				i;
				int				m=1;

				for(i=0;i<5;i++,goods++)
				{
					if(inventory>goods->inventory )
					{
						print_string(goods);
						m=0;
					}
				}

				if(m)
					printf("Sorry ,there isn't anything less than your inventory.\n ");

				return ;
	}
	#include<stdio.h>
	#include<string.h>
	#include<math.h>

	struct STUDENT
	{
		int			id;
		char		name[20];
		char		gender;
		char		adress[80];
		int			score[5];

	};

	float get_average(struct STUDENT *stu);
	struct STUDENT *find_by_name(struct STUDENT *pstu,char  *name);
	struct STUDENT * find_max(struct STUDENT * pstu);
	void   print_string(struct STUDENT * pstu);
	void sort_by_score(struct STUDENT * pstu);

	int main (void)
	{
		struct STUDENT			stu[5]={
			{1416001,"yang",'m',"hubei",{100,98,95,98,100}},
			{1416002,"huang",'m',"gansu",{94,96,95,100,97}},
			{1416003,"guo",'w',"hebei",{99,98,100,94,98}},
			{1416004,"pan",'m',"shanxi",{100,98,95,100,93}},
			{1416005,"liu",'w',"shanxi",{100,98,100,98,100}}
			};
		float					ave;
		int						i;
		struct STUDENT			*p;
		char					name[20];
		struct STUDENT			*m;

		for(i=0;i<5;i++)
		{
			printf("No %d\n",i);
			print_string(&stu[i]);
		}

			printf("Press ENTER to continue\n");
		printf("\n");

		getche();

		for(i=0;i<5;i++)
		{
			ave=get_average(&stu[i]);
			printf("The ave of No.%d:\t%f\n",i,ave);
		}

		printf("\n");

		printf("Press ENTER to continue \n");

		getche();

		while(1)
		{
			printf("Please input your find name :\n");
			printf("Press N to stop\n");
			gets(name);

			if(strcmp(name,"N")==0)
				break;
			p=find_by_name(stu,name);
			print_string(p);
		}

		printf("\nPress ENTER to continue\n\n");

		getche();

		printf("Who is found has the highest score is :\n");
		m=find_max(stu);
		print_string(m);

		printf("Press ENTER to continue \n");

		getche();

		sort_by_score(stu);

			return 0;
	}


	float get_average(struct STUDENT * stu)
	{
		float			ave;

		int				j;
		float			sum=0;

		for(j=0;j<5;j++)
			{
				sum+=(float)stu->score [j];
			}
		
		ave=sum/5;
		
		return (ave);
	}

	struct STUDENT *find_by_name(struct STUDENT *pstu,char  *name)
	{

		struct STUDENT		*p;

		for(p=pstu;p<(pstu+5);p++)
		{
			if(strcmp(name,p->name)==0)
			{
				return(p);
			}
		}
	}

	struct STUDENT * find_max(struct STUDENT * pstu)
	{
		struct STUDENT			*p;
		int						sum[5]={0};
		int						i;
		int						j;
		int						max;
		int						max_loc=0;


		for(p=pstu,i=0;p<(pstu+5);p++,i++)
		{
			for(j=0;j<5;j++)
			{
				sum[i]+=p->score[j];
			}
		}

		max=sum[0];
		
		for(i=0;i<5;i++)
		{
			if(max<sum[i])
			{
				max_loc=i;
				max=sum[i];
			}
		}

		return(pstu+max_loc);
	}

	void   print_string(struct STUDENT * pstu)
	{

		int				j;

			printf("Name:\t\t%s\n",pstu->name);
			printf("Id:\t\t%d\n",pstu->id );
			printf("Gender:\t\t%c\n",pstu->gender);
			printf("Adress:\t\t%s\n",pstu->adress);
			printf("Score:\t\t");
				for(j=0;j<5;j++)
				{
					printf("%-4d",pstu->score[j]);
				}
			
			printf("\n");
			printf("\n");
		
		return ;
	}

	void sort_by_score(struct STUDENT * pstu)
	{
		int						i;
		int						j;
		float					temp;
		float					ave[5];

		for(i=0;i<5;i++)
			ave[i]=get_average(pstu+i);

		
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(ave[i]>ave[j])
				{
					temp=ave[i];
					ave[i]=ave[j];
					ave[j]=temp;
				}
			}
		}

		printf("\nFrom the highest to the lowest : \n\n ");

		for(i=0;i<5;i++)
		{

			for(j=0;j<5;j++)
			{


				if(fabs(ave[i]-get_average(pstu+j))<=0.01)
				{
					print_string(pstu+j);
				}
			}
		}
		return ;
	}

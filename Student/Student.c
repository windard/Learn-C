#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct student{
	char 	No[6],name[20],sex[5],age[4];
	char 	className[10],address[40],email[30],QQ[10],tel[15];
	struct student *next;
}student;

student 	*head;

int AddStudent(void);
int DeleteStudent(void);
int RepairStudent(void);
int VerificationIdentity(void);
int maintain(void);
int FindName(void);
int findAddr(void);
int FindNumber(void);
int find(void);
int initStuInfo(void);
void Print(student *);

int initStuInfo(void){
	FILE 	*fp;
	student 	*p1,*p2;
	fp = fopen("FILE.DAT","r");
	if(fp==NULL){
		printf("未能初始化学生信息\n");
		fclose(fp);
		return 0;
	}else{
		head = (student*)malloc(sizeof(student));		
		p1 = head;
		while(!feof(fp)){
			p2 = (student*)malloc(sizeof(student));
			fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",p2->No,p2->name,p2->sex,p2->age,p2->className,p2->address,p2->email,p2->QQ,p2->tel);
			p1->next = p2;
			p1 = p2;
		}
		p2->next = NULL;
		fclose(fp);
		return 1;
	}
}

void Print(student *p){
	printf("学号：  %s\n",p->No);
	printf("姓名：  %s\n",p->name);
	printf("性别：  %s\n",p->sex);
	printf("年龄：  %s\n",p->age);
	printf("班级：  %s\n",p->className);
	printf("住址：  %s\n",p->address);
	printf("E-mail：%s\n",p->email);
	printf("QQ：    %s\n",p->QQ);
	printf("电话：  %s\n",p->tel);
}

int FindNumber(void){
	char 	sno[20];
	student *p;
	int flag;
	flag = 5;
	p = head->next;
	printf("\n请输入您想要查找的学号[0001-1000]\n");
	scanf("%s",&sno);
	fflush(stdin);
	while(p){
		if(strcmp(sno,p->No)==0){
			Print(p);
			flag = 1;
			break;
		}
		p = p->next;
	}
	return flag;	
}

int FindName(void){
	char 	sno[20];
	student *p;
	int flag;
	flag = 5;
	p = head->next;
	printf("\n请输入您想要查找的姓名\n");
	scanf("%s",&sno);
	fflush(stdin);
	while(p){
		if(strcmp(sno,p->name)==0){
			Print(p);
			flag = 1;
			break;
		}
		p = p->next;
	}
	return flag;
}

int findAddr(void){
	char 	sno[40];
	student *p;
	int flag;
	flag = 5;
	p = head->next;
	printf("\n请输入您想要查找的地址\n");
	scanf("%s",&sno);
	fflush(stdin);
	while(p){
		if(strcmp(sno,p->address)==0){
			Print(p);
			flag = 1;
			break;
		}
		p = p->next;
	}
	return flag;		
}

int VerificationIdentity(){
	char 	userID[20],passWord[20];
	char	superID[20],superWord[20];
	int 	i,legalUser;
	char	ch;
	FILE 	*fp;
	legalUser = 0;
	fp = fopen("superUser.DAT","r");
	if(fp==NULL){
		printf("\n权限文件不存在！！！");
	}else{
		do{
			printf("\n请输入用户名\n");
			i = 0;
			while(isalpha(ch=getch())&&i<20){
				putchar(ch);
				userID[i]=ch;
				i++;
			}
			userID[i]='\0';
			printf("\n请输入密码\n");
			i = 0;
			while(isalpha(ch=getch())&&i<20){
				putchar('*');
				passWord[i]=ch;
				i++;
			}
			passWord[i]='\0';
			rewind(fp);
			while(!feof(fp)){
				fscanf(fp,"%s\t%s\t\n",&superID,&superWord);
				if((strcmp(userID,superID)==0)&&(strcmp(passWord,superWord)==0)){
					legalUser = 1;
					break;
				}
			}
			if(legalUser)
				break;
			else{
				printf("\n你的用户名或密码有误，是否重新输入？[y/n]\n");
				ch = getche();
			}
		}while(tolower(ch)=='y');
	}
	return legalUser;
}

int find(void){
	char ch;
	int flag;
	flag = 4;
	while(flag){
		printf("\n\t\t**************************查询*****************************\n");
		printf("\t\t*                         1.学号                          *\n");
		printf("\t\t*                         2.姓名                          *\n");
		printf("\t\t*                         3.地址                          *\n");
		printf("\t\t*                         0.退出                          *\n");
		printf("\t\t***********************************************************\n");
		printf("请选择(1/2/3/0):\n");
		ch = getche();
		switch(ch){
			case '1':flag = FindNumber();
				break;
			case '2':flag = FindName();
				break;
			case '3':flag = findAddr();
				break;
			case '0':flag = 0;
				break;
			default:printf("输入有误，请重新输入\n");
				flag = 4;
				break;
		}
		if(flag == 5){
			printf("您所查找的学生不存在!\n");
				flag = 1;
		}
	}
	return 1;
}

int AddStudent(void){
	student 	*p2,*p3;
	char		ch;
	int 		addFlag;
	p2 = head->next;
	while(p2->next!=NULL){
		p2 = p2->next;
	}
	ch = 'y';
	while(tolower(ch)=='y'){
		p3 = (student*)malloc(sizeof(student));
		printf("请输入以下内容\n");
		printf("学号：");
		scanf("%s",p3->No);
		printf("姓名：");
		scanf("%s",p3->name);
		printf("年龄：");
		scanf("%s",p3->age);
		printf("性别：");
		scanf("%s",p3->sex);
		printf("班级：");
		scanf("%s",p3->className);
		printf("住址：");
		scanf("%s",p3->address);
		printf("E-mail：");
		scanf("%s",p3->email);
		printf("QQ：");
		scanf("%s",p3->QQ);
		printf("电话：");
		scanf("%s",p3->tel);
		p3->next = NULL;
		printf("\n请确认上述输入，[y/n]\n");
		ch = getche();
		if(tolower(ch)=='y'){
			p2->next = p3;
			p2 = p3;
			p3 = NULL;
			printf("\n添加信息成功！\n");
			addFlag = 1;
		}else{
			printf("\n未能添加学生信息。\n");
			addFlag = 0;
		}
		printf("\n是否添加下一个学生信息? [y/n]\n");
		ch = getche();
	}
	return addFlag;
}

int DeleteStudent(void){
	char	ch,stuNo[20];
	int 	deleteFlag;
	student *p,*q;
	ch = 'y';
	do{
		printf("\n请输入待删除的学生的学号：");
		gets(stuNo);
		p = head->next;
		q = head;
		while(p!=NULL){
			if(strcmp(p->No,stuNo)){
				q = p;
				p = p->next;
			}else{
				printf("\n您要删除的学生姓名是：%s\n",p->name);
				printf("\n请您再次确认[y/n]\n");
				ch = getche();
				if(tolower(ch)=='y'){
					q->next = p->next;
					deleteFlag = 3;
					break;
				}else{
					deleteFlag = 4;
					break;
				}
			}
		}
		if(p==NULL){
			printf("\n不存在您要删除的学生。。。\n");
			deleteFlag = 5;
		}
		printf("\n是否删除下一个学生的信息?[y/n]\n");
		ch = getche();
	}while(tolower(ch)=='y');
	return deleteFlag;
}

int RepairStudent(void){
	int repairFlag;
	char ch,stuNo[20];
	student *p,*q;
	do{
		printf("\n请输入待修改的学生的学号\n");
		gets(stuNo);
		p = head->next;
		while(p!=NULL){
			if(strcmp(p->No,stuNo)){
				p = p->next;
			}else{
				break;
			}
		}
		if(p!=NULL){
			do{
				printf("\n你需要修改的学生的原始信息是：\n");
				Print(p);
				printf("\n请输入需要修改的内容：\n");
				printf("1.学号 2.姓名 3.年龄 4.性别 5.班级 6.住址 7.E-mail 8.QQ 9.电话");
				printf("\n请选择:");
				ch = getche();
				switch(ch){
					case '1':printf("\n请输入新的内容：\n");
						gets(p->No);
						repairFlag = 6;
						break;
					case '2':printf("\n请输入新的内容：\n");
						gets(p->name);
						repairFlag = 6;
						break;
					case '3':printf("\n请输入新的内容：\n");
						gets(p->age);
						repairFlag = 6;
						break;
					case '4':printf("\n请输入新的内容：\n");
						gets(p->sex);
						repairFlag = 6;
						break;
					case '5':printf("\n请输入新的内容：\n");
						gets(p->className);
						repairFlag = 6;
						break;
					case '6':printf("\n请输入新的内容：\n");
						gets(p->address);
						repairFlag = 6;
						break;
					case '7':printf("\n请输入新的内容：\n");
						gets(p->email);
						repairFlag = 6;
						break;
					case '8':printf("\n请输入新的内容：\n");
						gets(p->QQ);
						repairFlag = 6;
						break;
					case '9':printf("\n请输入新的内容：\n");
						gets(p->tel);
						repairFlag = 6;
						break;
					default:printf("你的输入有误，请重新输入。");
				}
				printf("\n是否还要修改学生信息?[y/n]\n");
				ch = getche();
			}while(tolower(ch)=='y');
		}else{
			printf("\n不存在您要修改的学生。。。\n");
			repairFlag = 0;
		}
		printf("\n是否继续修改其他学生?[y/n]\n");
		ch = getche();		
	}while(tolower(ch)=='y');
	return repairFlag;
}

int Save(void){
	FILE *fp;
	student *p;
	p = head->next;
	if((fp=fopen("FILE.DAT","w"))==NULL){
		printf("\n保存文件不正常，请核对文件名\n");
		fclose(fp);
		return 0;
	}else{
		rewind(fp);
		while(p!=NULL){
			fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",p->No,p->name,p->sex,p->age,p->className,p->address,p->email,p->QQ,p->tel);
			p = p->next;
		}
		fclose(fp);
		return 1;
	}
}

int maintain(void){
	char ch;
	int success,saveFlag,maintainR = 4;
	success = VerificationIdentity();
	if(success == 0){
		printf("\n您是无权用户！！！\n");
		maintainR = 0;
	}else{
		while(maintainR){
			printf("\n\t\t**************************维护*****************************\n");
			printf("\t\t*                         1.增加                          *\n");
			printf("\t\t*                         2.删除                          *\n");
			printf("\t\t*                         3.修改                          *\n");
			printf("\t\t*                         4.查找                          *\n");
			printf("\t\t*                         0.退出                          *\n");
			printf("\t\t***********************************************************\n");
			printf("请选择(1/2/3/4/0):\n");
			ch = getche();
			switch(ch){
				case '1':maintainR = AddStudent();
					break;
				case '2':maintainR = DeleteStudent();
					break;
				case '3':maintainR = RepairStudent();
					break;
				case '4':maintainR = find();
					break;
				case '0':maintainR = 0;
					break;
				default:printf("输入有误，请重新输入\n");
					break;
			}			
		}
		printf("\n您已完成了对学生信息的维护，\n");
		printf("请您确认是否永久性保存您所做的修改？[y/n]\n");
		ch = getche();
		if(tolower(ch)=='y'){
			saveFlag = Save();
			if(saveFlag){
				maintainR = 4;
			}
			else{
				printf("\n保存失败\n");
				maintainR = 4;
			}
		}
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int initFlag,quitFlag,maintainFlag,findFlag;
	char ch;
	quitFlag  = 1;
	initFlag  = initStuInfo();
	if(initFlag)
		while(quitFlag){
			printf("\n\t\t*******************学生信息查询系统************************\n");
			printf("\t\t*                     1.查询                              *\n");
			printf("\t\t*                     2.维护                              *\n");
			printf("\t\t*                     0.退出                              *\n");
			printf("\t\t***********************************************************\n");
			printf("请选择(1/2/0):\n");
			ch = getche();
			switch(ch){
				case '1':findFlag = find();
					quitFlag = findFlag;
					break;
				case '2':maintainFlag = maintain();
					quitFlag = maintainFlag;
					break;
				case '0':quitFlag = 0;
					break;
				default:printf("\n输入有误，请重新输入：\n\n\n");
					break;
			}
		}
	else{
		printf("初始化学生信息失败！\n");
		return 1;
	}
	printf("\n再见！请按任意键退出\n");
	getchar();
	return 0;
}



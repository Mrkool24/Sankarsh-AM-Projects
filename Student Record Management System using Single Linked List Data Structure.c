//Project Name: Student Record Management System using Single Linked List Data Structure
//File type: .c
//Executed by: Sankarsh AM

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
{
	int rollno;
	char name[20];
	float percentage;
	struct student *next;
}sll;
void add_end(sll **);
void show_in_list(sll *);
void delete_rollno(sll **);
void delete_name(sll **);
void delete_all_the_records(sll **);
void save_and_exit(sll *);
void sort_with_name(sll *);
void sort_with_percentage(sll *);
int count_node(sll *);
void reverse_the_list(sll *);
void search_rollno(sll *);
void search_name(sll *);
void search_percentage(sll *);
int main()
{
	sll *hp=0;
	char op,ch;
	int c;
	while(1){
		printf("enter the choice\n");
		printf("A/a:add_end S/s:show_in_list D/d:delete_record l/L:delete_all_the_records v/V:save c/C:count_node t/T:sort r/R:reverse m/M:modify z:exit\n");
		scanf(" %c",&op);
		switch(op){
			case 'A':
			case 'a':add_end(&hp);break;
			case 'S':
			case 's':show_in_list(hp);break;
			case 'D':
			case 'd':printf("enter a choice\n");
				 printf("R/r:enter roll  to del\n N/n:enter name to del\n");
				 char ch;
				 scanf(" %c",&ch);
				 switch(ch)
				 {
					 case 'R':
					 case 'r':delete_rollno(&hp);break;
					 case 'N':
					 case 'n':delete_name(&hp);
				 }break;
			case 'V':
			case 'v':printf("enter a choice\n");
				 printf("S/s:save and exit\n E/e:exit without\n");
				 scanf(" %c",&ch);
				 switch(ch)
				 {
					 case 'S':
					 case 's':save_and_exit(hp);
					 case 'E':
					 case 'e':exit(0);
				 }break;

			case 'L':
			case 'l':delete_all_the_records(&hp);break;
			case 't':
			case 'T':printf("enter a choice\n");
				 printf("N/n:sort_with_name\n P/p:sort_with_percentage\n");
				 scanf(" %c",&ch);
				 switch(ch)
				 {
					 case 'N':
					 case 'n':sort_with_name(hp);break;
					 case 'p':
					 case 'P':sort_with_percentage(hp);
				 }break;
			case 'c':
			case 'C':c=count_node(hp);break;
			case 'R':
			case 'r':reverse_the_list(hp);break;
			case 'm':
			case 'M':printf("enter a choice\n");
				 printf("R/r:to search a rollno\n N/n:to search a name\n P/p:percentage based\n");
				 scanf(" %c",&ch);
				 switch(ch)
				 {
					 case 'R':
					 case 'r':search_rollno(hp);break;
					 case 'N':
					 case 'n':search_name(hp);break;
					 case 'P':
					 case 'p':search_percentage(hp);
				 }break;



			case 'z':exit(0);
		}
	}
}

void add_end(sll **p)
{
	sll *new,*last;
	static int i=1;
	new=malloc(sizeof(sll));
	new->rollno=i++;
	printf("enter name and percentage\n");
	scanf("%s %f",new->name,&new->percentage);
	new->next=0;
	if(*p==0)
		*p=new;
	else{
		last=*p;
		while(last->next)
			last=last->next;
		last->next=new;
	}
}

void show_in_list(sll *p)
{
	if(p==0)
	{
		printf("no records prsent\n");
		return;
	}
	while(p)
	{
		printf("%d %s %f\n",p->rollno,p->name,p->percentage);
		p=p->next;
	}
}

void delete_rollno(sll **p)
{
	if(*p==0)
	{
		printf("no records present\n");
		return ;
	}

	int num;
	printf("enter a num\n");
	scanf("%d",&num);
	sll *del,*prev;
	del=*p;
	while(del)
	{
		if(del->rollno==num)
		{
			if(del==*p)
				*p=del->next;
			else
				prev->next=del->next;
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("roll no not prsent\n");
}



void delete_name(sll **p)
{
	if(*p==0)
	{
		printf("no records present\n");
		return ;
	}
	char name[20];
	printf("enter a name\n");
	scanf("%s",name);
	sll *del,*prev;
	del=*p;
	while(del)
	{
		if(strcmp(del->name,name)==0)
		{
			if(del==*p)
				*p=del->next;
			else
				prev->next=del->next;
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("name no not prsent\n");
}

void delete_all_the_records(sll **p)
{
	if(*p==0)
	{
		printf("no records are present\n");
		return;
	}
	sll *del;
	del=*p;
	while(del)
	{
		*p=del->next;
		free(del);
		del=*p;
	}
	printf("delete all records\n");
}


void save_and_exit(sll *p)
{
	if(p==0)
	{
		printf("no records are present\n");
		return ;
	}
	FILE *fp;
	fp=fopen("data","w");
	while(p)
	{
		fprintf(fp,"%d %s %f\n",p->rollno,p->name,p->percentage);
		p=p->next;
	}
	printf("records are saved\n");
	fclose(fp);
}

void sort_with_name(sll *p)
{
	if(p==0)
	{
		printf("no records are present\n");
		return;
	}
	sll *p1,*p2,temp;
	p1=p2=p;
	int i,j,c;
	c=count_node(p);
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-1-i;j++)
		{
			if(strcmp(p1->name,p2->name)>0)
			{
				temp.rollno=p1->rollno;
				strcpy(temp.name,p1->name);
				temp.percentage=p1->percentage;

				p1->rollno=p2->rollno;
				strcpy(p1->name,p2->name);
				p1->percentage=p2->percentage;


				p2->rollno=temp.rollno;
				strcpy(p2->name,temp.name);
				p2->percentage=temp.percentage;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}


void sort_with_percentage(sll *p)
{
	if(p==0)
	{
		printf("no records are present\n");
		return;
	}
	sll *p1,*p2,temp;
	p1=p2=p;
	int i,j,c;
	c=count_node(p);
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-1-i;j++)
		{
			if(p1->percentage>p2->percentage)
			{
				temp.rollno=p1->rollno;
				strcpy(temp.name,p1->name);
				temp.percentage=p1->percentage;

				p1->rollno=p2->rollno;
				strcpy(p1->name,p2->name);
				p1->percentage=p2->percentage;


				p2->rollno=temp.rollno;
				strcpy(p2->name,temp.name);
				p2->percentage=temp.percentage;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}

int count_node(sll *p)
{
	int c=0;
	if(p==0)
	{
		printf("records are present\n");
		return;
	}
	while(p)
	{
		c++;
		p=p->next;
	}
	return c;
}


void reverse_the_list(sll *p)
{
	if(p==0)
	{
		printf("no records are present\n");
		return;
	}
	sll *p1,*p2,temp;
	p1=p2=p;
	int i,j,c;
	c=count_node(p);
	for(i=0;i<c/2;i++)
	{
		p2=p;
		for(j=0;j<c-1-i;j++)
			p2=p2->next;

		temp.rollno=p1->rollno;
		strcpy(temp.name,p1->name);
		temp.percentage=p1->percentage;

		p1->rollno=p2->rollno;
		strcpy(p1->name,p2->name);
		p1->percentage=p2->percentage;


		p2->rollno=temp.rollno;
		strcpy(p2->name,temp.name);
		p2->percentage=temp.percentage;

		p1=p1->next;
	}
}


void search_rollno(sll *p)
{
	int g;
	if(p==0)
	{
		printf("no records are present\n");
		return;
	}
	int num;
	printf("enter roll to serach\n");
	scanf("%d",&num);
	printf("enter the rollno to replace:\n");
	scanf("%d",&g);
	while(p)
	{
		if(p->rollno==num)
		{
			p->rollno=g;
			return;
		}
		p=p->next;
	}
	printf("rollno not found\n");
}


void search_name(sll *p)
{
	if(p==0)
	{
		printf("no records are present\n");
		return;
	}
	char name[20],name1[20];
	printf("enter name to serach\n");
	scanf("%s",name);
	printf("enter the name to replace:\n");
	scanf("%s",name1);
	while(p)
	{
		if(strcmp(p->name,name)==0)
		{
			strcpy(p->name,name1);
			return;
		}
		p=p->next;
	}
	printf("name not found\n");
}


void search_percentage(sll *p)
{
	if(p==0)
	{
		printf("no records are present\n");
		return;
	}
	int num,h;
	printf("enter percentage to serach\n");
	scanf("%d",&num);
	printf("enter the percentage to replace:\n");
	scanf("%d",&h);
	while(p)
	{
		if(p->percentage==num)
		{
			p->percentage=h;
			return;
		}
		p=p->next;
	}
	printf("percentage mnot found\n");
}

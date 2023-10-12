//Project Name:Preprocessor Project using C language
//file type: .c
//Executed by:Sankarsh A M

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void remove_comments(char*);
void include_header(void);
void macro_replacement(char *);
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:./a.out src_file");
		return 0;
	}
	int i;
	char b[20];
	strcpy(b,argv[1]);
	for(i=0;b[i]!='.';i++);

	b[i+1]='i';
	b[i+2]='\0';
	printf("%s\n",b);

	//remove_comments(b);
	macro_replacement(argv[1]);
	include_header();
	remove_comments(b);
}

void remove_comments(char *s)
{
	FILE *fp1,*fp2;
	fp1=fopen("pqr","r");
	if(fp1==0)
	{
		printf("no record present\n");
		return;
	}
	fp2=fopen(s,"w");
	char ch,ch1;
	while((ch=fgetc(fp1))!=-1)
	{
		if(ch=='/')
		{
			ch1=ch;
			ch=fgetc(fp1);
			if(ch=='/')
			{
				while((ch=fgetc(fp1))!='\n');
				fputc(ch,fp2);
			}
			else if(ch=='*')
			{
				while((ch=fgetc(fp1))!='*');
				if((ch=fgetc(fp2))=='/')
					fputc('\n',fp2);
			}
			else
			{
				fputc(ch1,fp2);
				fputc(ch,fp2);
			}
		}
		else
			fputc(ch,fp2);
	}
	fclose(fp1);
	fclose(fp2);

}
void include_header(void)
{
	int i,j,l;
	FILE *fp3,*fp4,*fp5;
	char a[50]="/usr/include/",p[200],p1[20]="#include",q1[100],q2[200],m[100]="/usr/include/";
	fp3=fopen("e","r");
	fp5=fopen("pqr","w");

	if(fp3==0)
	{
		printf("file is not present\n");
		return;
	}
	while(fgets(p,200,fp3))
	{
		if(strstr(p,p1))
		{
			l=strlen(p);
			for(i=0;i<l;i++)
			{
				if(p[i]=='<')
				{
					j=0;
					for(i=i+1;p[i]!='>';i++)
						q1[j++]=p[i];
					q1[j]=0;
				}
			}
			//printf("%s",q1);
			strcat(a,q1);
			printf("%s",a);
			fp4=fopen(a,"r");
			if(fp4==0)
			{
				printf("file is not present\n");
				return;
			}
			/*	fp5=fopen("pqr","w");
				if(fp5==0)
				{
				printf("file not present\n");
				return;
				}*/
			while(fgets(q2,100,fp4))
				fputs(q2,fp5);
			fclose(fp4);
			strcpy(a,m);
		}
		else
			fputs(p,fp5);
	}
	fclose(fp3);
	fclose(fp5);
}



void macro_replacement(char *s)
{
	FILE *fp6,*fp7;
	char k[50]="#define",**p,*p1,f[100],macro_name[50],macro_body[50];
	int i,j,x,n,l,y,l1,l2,l3,l4,v,c=0;

	fp6=fopen(s,"r");
	if(fp6==0)
	{
		printf("file is not present\n");
		return;
	}
	while(fgets(f,100,fp6))
		c++;
	rewind(fp6);
	p=malloc(sizeof(char*)*c);
	for(i=0;i<c;i++)
		p[i]=malloc(sizeof(char)*100);
	i=0;
	while(fgets(p[i++],100,fp6));
	i=0;
	while(i<c)
	{
		if(p1=strstr(p[i],k))
		{
			p1=p1+8;
			for(x=0;p1[x]!=' ';x++)
				macro_name[x]=p1[x];
			macro_name[x]='\0';
			y=strlen(macro_name);
			for(l=y,x=0;p1[l]!='\n';l++)
			{
				if(p1[l]!=' ')
					macro_body[x++]=p1[l];
			}
			macro_body[x]='\0';
			//			printf("%s\n",macro_name);
			//			printf("%s\n",macro_body);
			l1=strlen(macro_name);
			l2=strlen(macro_body);
			//printf("%d%d\n",l1,l2);
			j=0;
			if(l1==l2)
			{
				while(j<c)
				{
					if(p1=strstr(p[j],macro_name))
					{
						for(v=0;macro_name[v];v++)
							p1[v]=macro_body[v];
					}
					j++;
				}
			}
			else if(l1>l2)
			{
				//l3=l1-l2;
				j=0;
				while(j<c)
				{
					if(p1=strstr(p[j],macro_name))
					{
						l3=l1-l2;
						while(l3)
						{
							for(n=0;p1[n];n++)
								p1[n]=p1[n+1];
							l3--;
						}
						for(v=0;macro_body[v];v++)
							p1[v]=macro_body[v];
						j--;
					}
					j++;
				}
			}
			else if(l1<l2)
			{
				j=0;
				while(j<c)
				{
					if(p1=strstr(p[j],macro_name))
					{
						l3=l2-l1;
						while(l3)
						{
							l4=strlen(p1);
							for(;l4>=0;l4--)
								p1[l4+1]=p1[l4];
							l3--;
						}
						for(v=0;macro_body[v];v++)
						{
							p1[v]=macro_body[v];
						}
						j--;
					}
					j++;
				}
			}
		}
		i++;
	}
	for(j=0;j<c;j++)
	{
		if(p1=strstr(p[j],k))
		{
			p1[0]='\0';
		}
	}
	fp7=fopen("e","w");
	for(j=0;j<c;j++)
		fputs(p[j],fp7);
	fclose(fp7);


	//	printf("%s\n",p[j]);
}


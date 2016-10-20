#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 200
typedef struct Mystruct{
	char data[MAX];
	short int isLeft;
	struct Mystruct* left;
	struct Mystruct* right;
	struct Mystruct* father;
}Node, *NodeP;

void readIn();
void buildTree();
void printTree(NodeP p);
int compareOp(char op1,char op2);
int conbine(char str1[],char str2[]);
void conbineLeft(NodeP* pp,char strTemp[]);
char getOp(char str[]);

char formula[20][MAX];
int formulaTop=-1;
NodeP root;
int main()
{
	readIn();
	buildTree();
	printTree(root);
	printf("%s\n",root->data);
    return 0;
}
void readIn()
{
    char ch;
    char str[MAX];
    while(1)
    {
        scanf("%s%c",str,&ch);
		strcpy(formula[++formulaTop],str);
        if (ch=='\n')
        {
            break;
        }
    }
}

void buildTree()
{
	NodeP p;
	p=root = (NodeP)malloc(sizeof(Node));
	strcpy(root->data,formula[formulaTop]);
	root->left=NULL;
	root->right=NULL;
	root->father=NULL;
	root->isLeft = 2;
	int i=0;
	for (i = formulaTop-1; i >= 0; )
	{
		while ((p->data[0]>='0' && p->data[0]<='9')||(p->left!=NULL && p->right!=NULL))
        {
			p=p->father;
		}
		if(p==NULL)
			break;
		else if (p->right == NULL)
		{
			p->right = (NodeP)malloc(sizeof(Node));
			p->right->father = p;
			p= p->right;
			strcpy(p->data,formula[i]);
			p->left = NULL;
			p->right = NULL;
			p->isLeft=0;
			i--;
		}
		else if (p->left==NULL)
		{
			p->left = (NodeP)malloc(sizeof(Node));
			p->left->father = p;
			p= p->left;
			strcpy(p->data,formula[i]);
			p->left = NULL;
			p->right = NULL;
			p->isLeft=1;
			i--;
		}
	}
}

char getOp(char str[])
{
	char op='+';
	int len=strlen(str);
	op = str[len-1];
	return op;
}
void printTree(NodeP p)
{
	if(p->left!=NULL)
		printTree(p->left);
	if(p->isLeft==1)
	{
		if(p->father->father!=NULL)
		{
			int compareRet=0;
			if((compareRet = compareOp (getOp(p->father->data),getOp(p->father->father->data))) < 0)
			{
				char strTemp[MAX]="(";
				conbineLeft(&p , strTemp);
			}
			else if((compareRet== 0 && p->father->isLeft==0))
			{
				char strTemp[MAX]="(";
				conbineLeft(&p , strTemp);
			}
			else
			{
				char strTemp[MAX]="";
				conbineLeft(&p , strTemp);
			}
		}
		else
		{
			char strTemp[MAX]="";
			conbineLeft(&p , strTemp);
		}

	}
	else if(p->isLeft==0)
	{
		int len=conbine(p->father->data,p->data);
		int leftBracket=0;
		int rightBracket =0;
		int i=0;
		for(i=0;i<len;i++)
        {
            if(p->father->data[i]=='(')
                leftBracket++;
            else if(p->father->data[i]==')')
                rightBracket++;
        }
		if(rightBracket < leftBracket)
		{
			p->father->data[len++]=')';
		}
		p->father->data[len++]='\0';
		p = p->father;
		p->right = NULL;
	}
	if(p->right!=NULL)
		printTree(p->right);
}
int conbine(char str1[],char str2[])
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int j=0;
	for (j = 0; j < len2; j++)
	{
		str1[len1++]=str2[j];
	}
	str1[len1] = '\0';
	return len1;
}
void conbineLeft(NodeP* pp,char strTemp[])
{
	int len=conbine(strTemp,(*pp)->data);
	strTemp[len++]=(*pp)->father->data[0];
	strTemp[len++] = '\0';
	strcpy((*pp)->father->data,strTemp);
	(*pp) = (*pp)->father;
	(*pp)->left = NULL;
}
int compareOp(char op1,char op2)
{
	if((op1=='+'||op1=='-')&&(op2=='*'||op2=='/'))
		return -1;
	else if((op1=='+'||op1=='-')&&(op2=='+'||op2=='-'))
		return 0;
	else if((op1=='*'||op1=='/')&&(op2=='+'||op2=='-'))
		return 1;
	return 0;
}

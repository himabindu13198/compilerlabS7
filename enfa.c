#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

/*
gcc -o enfa enfa.c -lm

Possible inputs and their representations:

Alphabets - 0
Digits - 1
; - 2
Epsilon - 3
< - 4
= - 5
> - 6
! - 7
. - 8
{ - 9
} - 10
( - 11
) - 12
[ - 13
] - 14

*/

int find_epsilon_closure(int);
void setnfa(int,char,int);
void printnfa();
void printstack();

int nfa[1000][100][1000] = {0};
int clos=0,i,firstloop=1, stack[50], top=-1, temp=0;
int state[10000] = {0};
int go[1000][100] = {0};
int arr[1000] = {0};

void main()
{
        int st,fin,in;
        int f[10];
        int i,j,s=0,final=0,flag=0, k,l;
        int c;

        printf("\nEnter the number of states:");
        scanf("%d",&st);
        printf("\nGive state numbers from 0 to %d", st-1);
        printf("\n\nEnter the number of final states:");
        scanf("%d",&fin);
        printf("\nEnter the final states:");
        for(i=0;i<fin;i++)
        {
                scanf("%d",&f[i]);
        }
        int p,r,rel;
        char q;
        printf("\n Enter the number of rules according to the NFA:");
        scanf("%d",&rel);
        printf("\n\n Define translation rules as \"initial-state input-symbol(write 3 for epsilon) final-state\" \n");

        for(i=0;i<rel;i++)
        {
                scanf("%d %c %d",&p,&q,&r);
                setnfa(p,q,r);
        }
        printf("\n Enter initial state:");
        scanf("%d",&in);
	in = pow(2,in);
       // printnfa();
	printf("\nEpsilon closure");
	c=find_epsilon_closure(0);
	printf("%d", c);
	//printstack();
	/*for(i=0;i<15;i++)
	{	if(c & i)
		{
			printf("%d,",i);
		}
	}*/
	

//printnfa();
}


void setnfa(int a,char b,int c)
{

if(isalpha(b)) { nfa[a][0][c]=1; state[(int)pow(2,0)]=1; }
else if(b==';'){ nfa[a][2][c]=1; state[(int)pow(2,2)]=1; }
else if(b=='3'){ nfa[a][3][c]=1; state[(int)pow(2,3)]=1; }
else if(isdigit(b)) { nfa[a][1][c]=1; state[(int)pow(2,1)]=1; }
else if(b=='<') { nfa[a][4][c]=1; state[(int)pow(2,4)]=1; }
else if(b=='=')  {nfa[a][5][c]=1; state[(int)pow(2,5)]=1; }
else if(b=='>') {nfa[a][6][c]=1; state[(int)pow(2,6)]=1; }
else if(b=='!') {nfa[a][7][c]=1; state[(int)pow(2,7)]=1; }
else if(b=='.') {nfa[a][8][c]=1; state[(int)pow(2,8)]=1; }
else if(b=='{') {nfa[a][9][c]=1; state[(int)pow(2,9)]=1; }
else if(b=='}') {nfa[a][10][c]=1; state[(int)pow(2,10)]=1; }
else if(b=='(') {nfa[a][11][c]=1;  state[(int)pow(2,11)]=1; }
else if(b==')') {nfa[a][12][c]=1; state[(int)pow(2,12)]=1; }
else if(b=='[') {nfa[a][13][c]=1; state[(int)pow(2,13)]=1; }
else if(b==']') {nfa[a][14][c]=1; state[(int)pow(2,14)]=1; }

}

void printnfa()
{
int i,j,k;
for(i=0;i<1000;i++)
        for(j=0;j<100;j++)
                for(k=0;k<1000;k++)
                        if(nfa[i][j][k]==1)printf("\n %d - %d - %d ", i,j,k);
}
/*int find_epsilon_closure(int a)
{
int temp;
//if(firstloop==1){clos=0;}
clos=(int)pow(2,a);
firstloop=0;
//printf("\nclos now = %d",clos);
//clos=go[(int)pow(2,a)][3];
//while(clos!=0) { clos=clos|go[(int)pow(2,clos)][3]; 
for(i=0;i<15;i++)
{
	if(nfa[a][3][i]==1)
	{
		clos=clos|(int)pow(2,i);
		//printf("\nclosure now = %d",clos);
		find_epsilon_closure(i);
	}
}
temp=clos;
clos=0;
return temp;
}*/ 
void printstack()
{
for(i=0;i<top;i++)
{
printf("%d",stack[top]);
}
}
int find_epsilon_closure(int a)
{
stack[++top]=a;
//printstack();
for(i=0;i<15;i++)
{
	if(nfa[a][3][i]==1)
	{
		find_epsilon_closure(i);
	}
}//printstack();
while(top!=-1)
{
	//temp=temp*10 + (int)stack[top--];
	temp=temp|(int)pow(2,stack[top]);
}
return temp;
}

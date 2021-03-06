#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int n,m,next[][2]={{0,1},{1,0},{0,-1},{-1,0}},x,y,p,q;
typedef struct{
	int x;
	int y;
	int s;
}Item;
typedef struct node{
	Item data;
	struct node *next;
}Node;
typedef struct{
	Node *front;
	Node *rear;
	int items;
}Que;
Que hum={NULL,NULL,0};

void input(int [n][m]);
int bfs(int [n][m],int [n][m]);
void queadd(Que *,Item *);
void quedel(Que *,Item *);

int main(){
	int step;
	Item start;
	scanf("%d%d",&n,&m);
	int map[n][m],book[n][m];
	input(map);
	scanf("%d%d%d%d",&start.x,&start.y,&p,&q);
	start.x--,start.y--,p--,q--;
	start.s=0;
	memset(book,0,sizeof(int)*n*m);
	book[start.x][start.y]=1;
	queadd(&hum,&start);
	step=bfs(map,book);
	if(step>=0)
		printf("%d",step);
	else
		puts("No Way!");
	return 0;
}

void input(int map[n][m]){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&map[i][j]);
}

int bfs(int map[n][m],int book[n][m]){
	bool flag=0;
	int i;
	Item temp,place;
	while(hum.front!=NULL){
		quedel(&hum,&place);
		for(i=0;i<4;i++){
			temp.x=place.x+next[i][0];
			temp.y=place.y+next[i][1];
			temp.s=place.s+1;
			if(temp.x==p&&temp.y==q){
				flag=1;
				break;
			}
			if(temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<m\
			&&map[temp.x][temp.y]==0&&book[temp.x][temp.y]==0){
				book[temp.x][temp.y]=1;
				queadd(&hum,&temp);
			}
		}
		if(flag==1)
			break;
	}
	if(flag)
		return temp.s;
	else
		return -1;
}

void queadd(Que *pque,Item *pitem){
	Node *pnew=malloc(sizeof(Node));
	pnew->next=NULL;
	pnew->data=*pitem;
	if(pque->front==NULL){
		pque->front=pque->rear=pnew;
		pque->items=1;
	}else{
		pque->rear->next=pnew;
		pque->rear=pnew;
		pque->items++;
	}
}

void quedel(Que *pque,Item *pitem){
	Node *temp=pque->front;
	*pitem=pque->front->data;
	pque->front=pque->front->next;
	pque->items--;
	if(pque->front==NULL)
		pque->rear=NULL;
	free(temp);
}

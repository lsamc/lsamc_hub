#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>

#define L 23                //棋盘大小
#define INITLIFE 178        //点数

void init(char map[L][L])
{
    int a,b;
    for(int i=0;i<L;i++)
    for(int j=0;j<L;j++)map[i][j]=' ';
    for(int i=0;i<INITLIFE;i++)
    {
        a=rand()%L;
        b=rand()%L;
        if(map[a][b]!='#')map[a][b]='#';
        else i--;
    }
}
void paint(char map[L][L])
{
    printf(" ");
    for(int i=0;i<L;i++)printf("——");
    printf("\n");
    for(int i=0;i<L;i++)
    {
    printf("|");
    for(int j=0;j<L;j++)
    printf("%c ",map[i][j]);
    printf("|\n");
    }
    printf(" ");
    for(int i=0;i<L;i++)printf("——");
    printf("\n");
}
int move(char map[L][L],char maptemp[L][L])
{
    int count=0;
    for(int i=0;i<L;i++)
    for(int j=0;j<L;j++)
    {
        if(i==0)
        {
            if(j==0)
            {
                if(map[i][j+1]=='#')count++;
                if(map[i+1][j]=='#')count++;
                if(map[i+1][j+1]=='#')count++;
            }
            else if(j==L-1)
            {
                if(map[i][j-1]=='#')count++;
                if(map[i+1][j-1]=='#')count++;
                if(map[i+1][j]=='#')count++;
            }
            else 
            {
                if(map[i][j-1]=='#')count++;
                if(map[i+1][j-1]=='#')count++;
                if(map[i][j+1]=='#')count++;
                if(map[i+1][j]=='#')count++;
                if(map[i+1][j+1]=='#')count++;
            }
        }
        else if(i==L-1)
        {
            if(j==0)
            {
                if(map[i][j+1]=='#')count++;
                if(map[i-1][j]=='#')count++;
                if(map[i-1][j+1]=='#')count++;
            }
            else if(j==L-1)
            {
                if(map[i][j-1]=='#')count++;
                if(map[i-1][j-1]=='#')count++;
                if(map[i-1][j]=='#')count++;
            }
            else 
            {
                if(map[i][j-1]=='#')count++;
                if(map[i-1][j-1]=='#')count++;
                if(map[i][j+1]=='#')count++;
                if(map[i-1][j]=='#')count++;
                if(map[i-1][j+1]=='#')count++;
            }
        }
        else if(j==0)
        {
            if(map[i][j+1]=='#')count++;
            if(map[i-1][j+1]=='#')count++;
            if(map[i+1][j]=='#')count++;
            if(map[i-1][j]=='#')count++;
            if(map[i+1][j+1]=='#')count++;
        }
        else if(j==L-1)
        {
            if(map[i][j-1]=='#')count++;
            if(map[i-1][j-1]=='#')count++;
            if(map[i+1][j]=='#')count++;
            if(map[i-1][j]=='#')count++;
            if(map[i+1][j-1]=='#')count++;
        }
        else
        {
            if(map[i][j-1]=='#')count++;
            if(map[i-1][j-1]=='#')count++;
            if(map[i+1][j-1]=='#')count++;
            if(map[i][j+1]=='#')count++;
            if(map[i-1][j+1]=='#')count++;
            if(map[i+1][j]=='#')count++;
            if(map[i-1][j]=='#')count++;
            if(map[i+1][j+1]=='#')count++;
        }
        if(count==3)maptemp[i][j]='#';
        else if(count==2)maptemp[i][j]=map[i][j];
        else maptemp[i][j]=' ';
        count=0;
    }
    for(int i=0;i<L;i++)
    for(int j=0;j<L;j++)map[i][j]=maptemp[i][j];
}
int main()
{
    int new=1,go_on=1;
    srand((unsigned)time(NULL));
    char map[L][L],maptemp[L][L];
    
    printf("——————生命——————\n");
    printf("本模拟程序由罗伯特·J·索耶于《计算中的上帝》中描述\n");
    printf("编写者：lsamc\n于2020.07.30制成\n");
    printf("如果一个方格有且仅有两个相邻的方格被占据，那么它将保持原状态不变。\n");
    printf("如果一个方格有三个被占据的邻居，那么它将保持被占据状态。\n");
    printf("所有其他的条件下，这个方格变为空(原文可能有问题，有改动)\n");
    printf("开始创造世界——");
    getch();
    
    while(new){
    init(map);
    go_on=1;
        while(go_on)
        {
            
            paint(map);
            printf("1代表进化，0代表退出，2代表自动运行50次");
            scanf("%d",&go_on);
            move(map,maptemp);
            if(go_on==2)
            {
                for(int j=0;j<49;j++)
                {
                    paint(map);
                    move(map,maptemp);
                    sleep(1);
                }
            }
        }
    printf("开始一轮新的模拟？(1代表是，0代表否)");
    scanf("%d",&new);
    clrscr();
    }
    
    return 0;
}
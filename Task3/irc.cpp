#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N  12              //随机生成的页地址流的长度 
#define B   3             //分配给当前进程的内存块数 
#define P   5       //进程的页面数
int isInBuf(int buf[], int x, int *p)
 //返回某个数x有没有在缓冲Buf[]中，若在，返回其位置，否则返回－1,*p为缺页次数
{ 
    int i, j = -1; 
    for (i = 0; i < B; i++) 
    { 
      if(buf[i] == x) 
          { 
              j = i; 
              break; 
          } 
          else if (buf[i] == -1) 
          { 
         //有空闲内存块（在装入最初的几个页面时）
              (*p)++;
              buf[i] = x; 
              j = i; 
              break; 
          } 
    } 
       if(j==-1) 
              (*p)++;
       return j; 
} 

int oldlru(int f[ ]) 
{ //功能： 返回最近最久未使用页面的位置
    int i, j = 0, max = -1; 
    for (i = 0; i < B; i++) 
    { 
            if(f[i] > max) 
            {
                    max = f[i];
                    j = i;
            } 
            f[i]++; 
    } 
    return j; 
} 

int main() 
{ 
    int list[N]; //程序的访页地址流
    int change[N]; //记录每次被替换出去的页
    int buf[B], f[B], i, j,k; 
    //buf是分配给进程的内存块，f记录内存中页面多久未被访问
    int result[B][N]; //置换的详细过程
    int old; //指向将要换出去的页
    int absent; //缺页次数
    srand((int)time(NULL));  //初始化随机数种子 
    printf("\n The Random List:\n"); 
    for (i = 0; i < N; i++)
    {//产生随机页面访问序列 
        list[i] = rand() % P+1;  
        printf("%3d", list[i]); 
    }
    printf("\n---------------------------------------------------\n");
    // LRU置换算法 
    printf("\nLRU:\n"); 
    absent = 0; 
    for(i = 0; i < B; i++) 
        buf[i] = f[i] = -1; 
    for(i = 0; i < N; i++) 
    { 
        j = isInBuf(buf, list[i],&absent); 
        old = oldlru(f); 
        if(j== -1) //需置换页面
    	{ 
            change[i]=buf[old]; 
            buf[old] = list[i]; 
            f[old] = 0;      
        } 
        else //不需置换页面
        { 
            f[j]=0; 
            change[i]=-1; 
    	}
 
        //保存当前内存页面情况
        for(k=0;k<B; k++)   
                result[k][i]=buf[k];
    } 
    //输出置换详细过程
    printf("the result is:\n");
    for(i=0;i<B;i++)
    {
        for(j=0;j<N;j++)
        printf("%3d",result[i][j]);
        printf("\n");
    }
    //输出每次被置换出去的页
    printf("\nthe page is changed:\n");
    for(i=0;i<N;i++)
    {
    if(change[i]== -1)
        printf("   "); 
    else
        printf("%3d",change[i]);
    }

    //显示缺页次数及缺页率 
    printf("\nabsent:%d\n",absent); 
    printf("the absent vote is:%f\n",(float)absent/N);
}

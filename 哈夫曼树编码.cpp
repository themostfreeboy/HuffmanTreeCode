#include<conio.h>
#include<stdio.h>
main()
{
      FILE *f1,*f2;
      f1=fopen("Huffman.in","r");
      f2=fopen("Huffman.out","w");
      int tree[2048][5],n,i,j,k,p1=0,p2=0;
      fscanf(f1,"%d",&n);
      int code[n+1][2048],num[n+1];
      float quan[2*n],small1,small2;
      char name[n+1];
      for(i=1;i<=n;i++)
      {
                       fscanf(f1," %c%f",&name[i],&quan[i]);
                       tree[i][1]=-1;
                       tree[i][2]=-1;
                       tree[i][3]=-1;
      }
      for(i=n+1;i<=2*n-1;i++)
      {
                       tree[i][1]=-1;
                       tree[i][2]=-1;
                       tree[i][3]=-1;
                       quan[i]=0;
      }
      for(i=1;i<=n-1;i++)
      {
                         small1=2048,
                         small2=2048;
                         for(j=1;j<=n+i-1;j++)
                         {
                                             if(quan[j]<small1&&tree[j][1]==-1)
                                             {
                                                               small2=small1;
                                                               small1=quan[j];
                                                               p2=p1;
                                                               p1=j;
                                             }
                                             else if(quan[j]<small2&&tree[j][1]==-1)
                                             {
                                                               small2=quan[j];
                                                               p2=j;
                                             }
                         }
                         tree[n+i][2]=p1;
                         tree[n+i][3]=p2;
                         tree[p1][1]=n+i;
                         tree[p2][1]=n+i;
                         quan[n+i]=quan[p1]+quan[p2];
                         tree[p1][4]=0;
                         tree[p2][4]=1;
      }
      for(i=1;i<=n;i++)
      {
                       j=i;
                       k=0;
                       while(tree[j][1]!=-1)
                       {
                                            k++;
                                            code[i][k]=tree[j][4];
                                            j=tree[j][1];
                       }
                       num[i]=k;
      }
      for(i=1;i<=n;i++)
      {
                       fprintf(f2,"%cµÄÂëÎª",name[i]);
                       for(j=num[i];j>=1;j--)
                       {
                                             fprintf(f2,"%d",code[i][j]);
                       }
                       fprintf(f2,"\n");
      }
      fclose(f1);
      fclose(f2);
}

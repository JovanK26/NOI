#include <bits/stdc++.h>

using namespace std;
int n;
int mat[1024][1024];
int f[1024][1024];
int sum(int c1,int c2,int c3,int c4)
{
    if(c1<0 || c1>=n)return -1;
    if(c2<0 || c2>=n)return -1;
    if(c3<0 || c3>=n)return -1;
    if(c4<0 || c4>=n)return -1;
    int rez=f[c3][c4];
    if(c2-1>=0)rez-=f[c3][c2-1];
    if(c1-1>=0)rez-=f[c1-1][c4];
    if(c2-1>=0 && c1-1>=0)rez+=f[c1-1][c2-1];
    return rez;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j]=0;
        }
    }
    int k,x,y;
    cin >> k;
    for(int i=0;i<k;i++)
    {
        cin >> x >> y;
        mat[x][y]=1;
    }
    f[0][0]=mat[0][0];
    for(int i=1;i<n;i++)
    {
        f[i][0]=f[i-1][0]+mat[i][0];
    }
    for(int i=1;i<n;i++)
    {
        f[0][i]=f[0][i-1]+mat[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+mat[i][j];
        }
    }
   int l=0;
   int r=n;
   int m;
   bool check=0;
   while(l<r)
   {
       m=(l+r)/2;
       check=0;
       for(int i=0;i<n;i++)
       {
           if(check)break;
           for(int j=0;j<n;j++)
           {
               if(!sum(i,j,i+m,j+m))
               {
                  check=1;
                  break;
               }
           }
       }
       if(check)
       {
           l=m+1;
       }
       else
       {
           r=m;
       }
   }
   cout << l;
    return 0;
}

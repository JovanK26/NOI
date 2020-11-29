#include <bits/stdc++.h>

using namespace std;
int rez=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,d,k;
    cin >> n >> m >> d >> k;
    char mat1[n][m];
    int mat2[n][m];
    int f[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> mat1[i][j];
            if(mat1[i][j]=='S')mat2[i][j]=1;
            else
            {
                mat2[i][j]=0;
            }
        }
    }
    f[0][0]=mat2[0][0];
    for(int i=1;i<n;i++)
    {
        f[i][0]=f[i-1][0]+mat2[i][0];
    }
    for(int i=1;i<m;i++)
    {
        f[0][i]=f[0][i-1]+mat2[0][i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+mat2[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat1[i][j]=='M')
            {
                int temp=0;
                int i1=max(0,i-d);
                int j1=max(0,j-d);
                int i2=min(n-1,i+d);
                int j2=min(m-1,j+d);
                temp+=f[i2][j2];
                if(i1-1>=0)temp-=f[i1-1][j2];
                if(j1-1>=0)temp-=f[i2][j1-1];
                if(i1-1>=0 && j1-1>=0)temp+=f[i1-1][j1-1];
                if(temp>=k)
                {
                    rez++;
                }
            }
        }
    }
    cout << rez;
    return 0;
}

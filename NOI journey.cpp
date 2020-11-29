#include <bits/stdc++.h>

using namespace std;
long long n,m,h;
long long f[10001][401];
vector <pair<long long,long long> >v[10001];
void solve()
{
    for(long long start=0;start<n-1;start++)
    {
      for(long long i=0;i<v[start].size();i++)
      {
        if(v[start][i].first>start)
        {
            long long sum=0;
            for(long long j=0;j<m-v[start][i].second;j++)
            {
                sum=min(sum+f[start][j],(long long)500000001);
                f[v[start][i].first][j+v[start][i].second]=min(f[v[start][i].first][j+v[start][i].second]+sum,(long long)500000001);
            }
        }
      }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> h;
    long long j,k;
    for(long long i=0;i<n-1;i++)
    {
        for(long long t=0;t<h;t++)
        {
            cin >> j >> k;
            v[i].push_back(make_pair(j,k));
        }
    }
    f[0][0]=1;
    solve();
    for(long long i=0;i<m;i++)
    {
        cout << min((long long)500000001,f[n-1][i])<<' ';
    }
    return 0;
}

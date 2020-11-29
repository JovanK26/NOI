#include <bits/stdc++.h>

using namespace std;
int x[10000001];
int y[10000001];
int pref[10000001];
int suf[10000001];
int rez=0;
static char buf[1 << 19];
static int idx = 0;
static int bytes = 0;
static inline int _read() {
    if (!bytes || idx == bytes) {
        bytes = (int)fread(buf, sizeof(buf[0]), sizeof(buf), stdin);
        idx = 0;
    }
    return buf[idx++];
}
static inline int _readInt() {
    int x = 0, s = 1;
    int c = _read();
    while (c <= 32) c = _read();
    if (c == '-') s = -1, c = _read();
    while (c > 32) x = 10 * x + (c - '0'), c = _read();
    if (s < 0) x = -x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    n=_readInt();
    for(int i=0;i<n;i++)
    {
        x[i]=_readInt();
        y[i]=_readInt();
    }
    pref[0]=x[0]+y[0];
    for(int i=1;i<n;i++)
    {
        pref[i]=max(pref[i-1],x[i]+y[i]);
    }
    suf[n-1]=y[n-1]-x[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suf[i]=max(suf[i+1],y[i]-x[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(!i && suf[i]>suf[i+1])rez++;
        else if(i==n-1 && pref[i]>pref[i-1])rez++;
        else if(pref[i]>pref[i-1] && suf[i]>suf[i+1])
        {
            rez++;
        }
    }
    cout << rez;
    return 0;
}

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define eb emplace_back
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vll;

const int Mxn = 3005;
int n;
int s[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vi a(n);
        s[0] = 0;
        fori(i,0,n) {
            cin >> a[i];
            s[i+1] = s[i] + a[i];
        }
        int ans = n;
        for(int x = 1; x <= n; x++) {
            int l = x, tmp = x-1;
            for(int i = x + 1; i <= n; i++) {
                if(s[i] - s[l] == s[x]) l = i;
                else tmp++;
            }
            if(l == n)
                ans = min(ans, tmp);
        }
        cout << ans << endl;
    }
    return 0; 
}
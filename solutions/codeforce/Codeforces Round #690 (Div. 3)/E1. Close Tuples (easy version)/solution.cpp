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

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi a(n);    
        fori(i,0,n) cin >> a[i];
        sort(all(a));
        ll ans = 0;
        int r = 0;
        for(int i = 0; i < n; i++) {
            while(r < n && a[r] - a[i] <= 2) r++;
            r--;
            ll vl = r - i;
            ans += vl*(vl - 1)/2;
        }
        cout << ans << endl;
    }
    return 0; 
}
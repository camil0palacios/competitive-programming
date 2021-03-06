#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define fori(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
#define ft first
#define sd second
#define all(v) v.begin(), v.end()
#define sz(v) (int) v.size()
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

const int Mxn = 3e4 + 5;
int a[Mxn];

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int,int> m;
        fori(i,0,n) {
            cin >> a[i];
            m[a[i]%3]++;
        }
        n /= 3;
        int ans = 0;
        fori(i,0,6) {
            if(m[i%3] > n) {
                ans += m[i%3] - n;
                m[(i+1)%3] += m[i%3] - n;
                m[i%3] = n;
            }   
        }
        cout << ans << endl;
    }
    return 0; 
}
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
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vl;

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = sz(s);
        bool ok = 0;
        forr(i,n-2,0) {
            if(s[i] < s[i+1]) {
                int idx = i+1;
                fori(j,i+1,n) {
                    if(s[i] < s[j]) idx = j;
                }
                swap(s[i], s[idx]);
                sort(s.begin()+i+1, s.end());
                ok = 1;
                break;
            }
        }
        cout << (ok ? s : "no answer") << endl;
    }
    return 0; 
}
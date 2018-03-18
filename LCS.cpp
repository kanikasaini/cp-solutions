// Kanika Saini
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define MAX 1000000007
#define INF (int)1e9
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
ll mod(ll a) { return a % MAX ; }
ll power(ll a,ll b) { if(b==0) return 1; else if(b%2==0) return power(a*a,b/2); else return a*power(a*a,b/2); }
ll powermod(ll a,ll b) { if(b==0) return 1; else if(b%2==0) return mod(powermod(mod(a*a),b/2)); else return mod(a)*mod(powermod(mod(a*a),b/2)); }
#define cases int t, testcase; cin>>t; testcase=0; while(testcase++<t)
#define PI 3.1415926
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MAPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
ll amin(ll x, ll y) { if(y < x) return y; return x; }
ll amax(ll x, ll y) { if(y > x) return y; return x; }
inline void print( int testcase ) { cout<<"Case #"<<testcase<<": "; }
/* Dynamic Programming implementation of LCS problem */
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
 
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = amax(L[i-1][j], L[i][j-1]);
     }
   }
 

   // Following code is used to print LCS
   int index = L[m][n];
 cout<<index;
   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character
 
   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }
 
      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }
 
   // Print the lcs
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
int main()
{
	string a = "hello";
	string b = "ahbooekldlao";
	lcs(a,b, 5, 12);

	return 0;
}
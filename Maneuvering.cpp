/*
Maneuvering a Cave
The task is to count all the possible paths from top left to bottom right of a 
m
×
n
m×n matrix with the constraints that from each cell you can either move only to right or down.

Since the answer will be large, output the answer modulo 
10
9
+
7
10 
9
 +7

Input Format
First line consists of 
T
T test cases. First line of every test case consists of 
N
N and 
M
M, denoting the number of rows and number of columns respectively.
Output Format
Single line output i.e., count of all the possible paths from top left to bottom right of a 
m
×
n
m×n matrix..

Constraints
1
≤
T
≤
100
1≤T≤100
1
≤
N
≤
100
1≤N≤100
1
≤
M
≤
100
1≤M≤100
Sample 1:
Input
Output
2
2 2
3 3
2
6
Explanation:
Test Case 1: 
2
×
2
2×2 matrix

   (0, 0) ? (0, 1)
     ?        ?
   (1, 0) ? (1, 1)
Paths from top-left 
(
0
,
0
)
(0,0) to bottom-right 
(
1
,
1
)
:
(1,1):

Right ? Down
Down ? Right

Total Paths: 
2
2

Test Case 2: 
3
×
3
3×3 matrix

    (0, 0) ? (0, 1) ? (0, 2)
      ?        ?         ?
    (1, 0) ? (1, 1) ? (1, 2)
      ?        ?         ?
    (2, 0) ? (2, 1) ? (2, 2)
Paths from top-left 
(
0
,
0
)
(0,0) to bottom-right 
(
2
,
2
)
:
(2,2):

Right ? Right ? Down ? Down
Right ? Down ? Right ? Down
Right ? Down ? Down ? Right
Down ? Right ? Right ? Down
Down ? Right ? Down ? Right
Down ? Down ? Right ? Right

Total Paths
:
6
*/

/*
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dr[2][2] = {{0,1},{1,0}};
void v(int n,int m,int x,int y,long long &c){
    if(x==n && y==m){
        c=(c+1)%mod;
        return;
    }
    for(auto& i:dr){
        int x1=x+i[0];
        int y1=y+i[1];
        if(x1>=0 && y1>=0 && x1<n+1 && y1<m+1){
            v(n,m,x1,y1,c);
        }
    }
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   int n,m;
	   long long c=0;
	   cin>>n>>m;
	   v(n-1,m-1,0,0,c);
	   cout<<c%mod<<endl;
	}
	return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long v(int n,int m,vector<vector<long long>>&dp){
    if(n==0 && m==0){
        return 1;
    }
    if(n<0 || m<0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    long long up=v(n-1,m,dp)%mod;
    long long l=v(n,m-1,dp)%mod;
    return dp[n][m]=(up+l)%mod;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	   int n,m;
	   //long long c=0;
	   cin>>n>>m;
	   vector<vector<long long>>dp(n,vector<long long>(m,-1));
	   cout<<v(n-1,m-1,dp)<<endl;
	}
	return 0;
}


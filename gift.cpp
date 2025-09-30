/*
Minimum Gifts
A Company has decided to give some gifts to all of its employees. For that, the company has given some rank to each employee. Based on that rank, the company has made certain rules for distributing the gifts.
The rules for distributing the gifts are:

Each employee must receive at least one gift.
Employees having higher ranking get a greater number of gifts than their neighbors.
What is the minimum number of gifts required by the company?

Input Format
The first line contains integer T, denoting the number of test cases.
For each test case:
The first line contains integer N, denoting the number of employees.
The second line contains N space-separated integers, denoting the rank of each employee.
Output Format
For each test case print the number of minimum gifts required on a new line.

Constraints
1
<
T
<
10
1<T<10
1
<
N
<
10
5
1<N<10 
5
 
1
<
R
a
n
k
<
10
9
1<Rank<10 
9
 
Sample 1:
Input
Output
2
5
1 2 1 5 2
2
1 2
7
3
Explanation:
adhering to the rules mentioned above,
Employee # 1 whose rank is 1 gets one gift
Employee # 2 whose rank is 2 gets two gifts
Employee # 3 whose rank is 1 gets one gift
Employee # 4 whose rank is 5 gets two gifts
Employee # 5 whose rank is 2 gets one gift
Therefore, total gifts required is 1 + 2 + 1 + 2 + 1 = 7
Similarly, for test case 2, adhering to the rules mentioned above,
Employee # 1 whose rank is 1 gets one gift
Employee # 2 whose rank is 2 gets two gifts
Therefore, the total gifts required is 1 + 2 = 3
*/

//Two pass 

#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>rank(n);
	    for(int i=0;i<n;i++){
	        cin>>rank[i];
	    }
	    vector<int>g(n,1);
	    for(int i=1;i<n;i++){
	        if(rank[i]>rank[i-1]){
	            g[i]=g[i-1]+1;
	        }
	    }
	    for(int i=n-2;i>=0;i--){
	        if(rank[i]>rank[i+1]){
	            g[i]=max(g[i],g[i+1]+1);
	        }
	    }
	    cout<<accumulate(g.begin(),g.end(),0)<<endl;
	}
	return 0;
}

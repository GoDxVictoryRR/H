/*Critical Planets
The war between the Republic and the Separatists is escalating. The Separatists are on a new offensive. They have started blocking the path between the republic planets (represented by integers) so that these planets surrender due to the shortage of food and supplies. The Jedi council has taken note of the situation and they have assigned Jedi Knight Skywalker and his Padawan Ahsoka to save the critical planets from blockade (Those planets or systems of planets which can be accessed by only one path and may be lost if that path is blocked by separatist).

Skywalker is preparing with the clone army to defend the critical paths. He has assigned Ahsoka to find the critical planets. Help Ahsoka to find the critical planets(C) in ascending order. You only need to specify those planets which have only one path between them and they cannot be accessed by any other alternative path if the only path is compromised.
Input Format
The first line contains two space-separated integers 
M
M and 
N
N, where 
M
M denotes the number of paths between planets and 
N
N denotes the number of planets.

Next 
M
M lines, each contains two space-separated integers, representing the planet numbers that have a path between them.

Output Format
Clines containing one integer representing the critical planet that they need to save in ascending order of the planet number if no planet is critical then print 
−
1
−1.

Constraints
M
≤
10000
M≤10000
N
≤
7000
N≤7000
Sample 1:
Input
Output
3 4
0 1
1 2
2 3
0
1
2
3
Explanation:

Since all the planets are connected with one path and cannot be accessed by any alternative paths hence all the planets are critical.

Sample 2:
Input
Output
7 6
0 2
0 1
1 2
2 3
4 5
3 4
3 5
2
3
Explanation:
If the republic loses the path between 2 and 3 then the two systems of planets will not be able to communicate with each other. Hence 2 and 3 are critical planets.
*/

#include <bits/stdc++.h>
using namespace std;

const int m=7005;
vector<int> adj[m];
int visited[m];
int in[m];
int low[m];
int t;
set<int>r;

void dfs(int u,int parent){
    visited[u]=1;
    in[u]=low[u]=t++;
    for(int v:adj[u]){
        if(v==parent)continue;
        if(visited[v]){
            low[u]=min(low[u],in[v]);
        }
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>in[u]){
               r.insert(u);
               r.insert(v);
            }
        }
    }
}

int main() {
	// your code goes here
	int n,m;
	cin>>m>>n;
	for(int i=0;i<m;i++){
	    int u,v;
	    cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	for(int i=0;i<n;i++){
	    visited[i]=0;
	}
	t=0;
	dfs(0,-1);
	if(r.empty()){
	    cout<<-1<<endl;
	}
	else{
	    vector<int>s(r.begin(),r.end());
	    sort(s.begin(),s.end());
	    for(int x:s){
	        cout<<x<<endl;
	    }
	}
	return 0;
}


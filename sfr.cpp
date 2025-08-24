/*
String From Rank
In a Super market we will find many variations of the same product. In the same way we can find many types of rice bags which differ in its quantity, price, brand, and type of rice in it. Many variations of same products exist in a super market. Consider rice for example. We get it in varying quantities 
(
q
)
(q) and at different prices 
(
p
)
(p).
Thus rice bag is unique combination of 
q
,
p
q,p. Customers want to buy the rice bags of their own choices. Each bag has two attributes price and the quantity of rice. The customers have some conditions for buying the rice bags, they have a specific price and quantity that have to be compared with the rice bags before buying them. If the price of rice bag is less than or equal to the customer’s preference and if the quantity is more than given preference, then he/she will buy it. There is only one bag of each type and each customer can buy at most one bag.
Given 
n
n,
m
m representing the number of customers and rice bags respectively, along with the variations of rice bags available in the market and the preferences of customers, find the maximum number of bags that can be sold by the end of the day.

Input Format
The first line contains two space separated integers 
n
n and 
m
m denoting the number of customers and number of rice bags respectively.
Next 
n
n lines consist of two space separated integers 
a
a and 
b
b denoting customer’s preferences viz. customer’s quantity and cost preferences, respectively.
Lastly, the next 
m
m lines consist of two space separated integers q and p denoting the bags quantity and cost, respectively.
Output Format
Print the maximum number of rice bags that can be sold.

Constraints
1
≤
n
,
m
≤
1000
1≤n,m≤1000
1
≤
a
,
b
≤
10
5
1≤a,b≤10 
5
 
1
≤
p
,
q
≤
10
5
1≤p,q≤10 
5
 
Sample 1:
Input
Output
5 4
35 2400
70 5500
87 6000
20 1700
12 500
50 2500
75 4875
100 7000
25 1250
2
Explanation:
Since price of bag should be less than or equal to customer’s preference and the quantity should be greater than the preferred quantity, customer 2 can buy bag 2 and customer 4 can buy bag 4.
So, in total, 2 bags can be sold to the customers.

Sample 2:
Input
Output
4 7
32 1500
58 5000
87 6200
45 3000
20 1200
60 4500
100 6000
80 5500
35 1400
40 2000
50 2800
4
Explanation:
Since price of bag should be less than or equal to customer’s preference and the quantity should be greater than the preferred quantity, customer 1 can buy bag 5, customer 2 can buy bag 2, customer 3 can buy bag 3 and customer 4 can buy 7th bag.
So, in total, 4 bags can be sold to the customers.
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj; // adjacency list: customer -> bags
vector<int> matchBag;    // which bag is matched to a customer
vector<int> matchCust;   // which customer is matched to a bag
vector<int> visited;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (visited[v]) continue;
        visited[v] = 1;
        if (matchBag[v] == -1 || dfs(matchBag[v])) {
            matchBag[v] = u;
            matchCust[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;

    vector<pair<int,int>> customers(n); // {quantityPref, pricePref}
    vector<pair<int,int>> bags(m);      // {quantity, price}

    for (int i = 0; i < n; i++) cin >> customers[i].first >> customers[i].second;
    for (int j = 0; j < m; j++) cin >> bags[j].first >> bags[j].second;

    adj.resize(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (bags[j].first > customers[i].first && bags[j].second <= customers[i].second) {
                adj[i].push_back(j); // customer i can buy bag j
            }
        }
    }

    matchBag.assign(m, -1);
    matchCust.assign(n, -1);

    int result = 0;
    for (int i = 0; i < n; i++) {
        visited.assign(m, 0);
        if (dfs(i)) result++;
    }

    cout << result << "\n";
    return 0;
}


/*
#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n, m; 
    cin >> n >> m; 
    
    vector<vector<int>> cust; 
    for (int i = 0; i < n; i++) {
        int q, p; // Variables for quantity and cost
        cin >> q >> p; // Read quantity (q) and cost (p) for each customer
        cust.push_back({p, q}); // Store customer as {cost, quantity} in the vector
    }

    vector<vector<int>> rice; // Vector to store rice bag details (cost, quantity)
    for (int i = 0; i < m; i++) {
        int q, p; // Variables for quantity and cost of rice bags
        cin >> q >> p; // Read quantity (q) and cost (p) for each rice bag
        rice.push_back({p, q}); // Store rice bag as {cost, quantity} in the vector
    }

    // Sort customers by cost (ascending order)
    sort(cust.begin(), cust.end());
    // Sort rice bags by cost (ascending order)
    sort(rice.begin(), rice.end());

    vector<int> good(m, 0); // Vector to track which rice bags have been used (0 = unused, 1 = used)
    int ans = 0; // Variable to count the total number of satisfied customers

    // Loop through each customer
    for (int i = 0; i < n; i++) {
        int quan = -1; // Variable to store the quantity of the selected rice bag
        int index = -1; // Variable to store the index of the selected rice bag

        // Loop through each rice bag
        for (int j = 0; j < m; j++) {
            // Check if the rice bag has not been used
            if (!good[j]) {
                // If the cost of the rice bag is greater than the customer's budget, stop checking further
                if (rice[j][0] > cust[i][0]) break;

                // If the rice bag quantity is greater than the customer's quantity preference
                if (rice[j][1] > cust[i][1]) {
                    // If this is the first suitable rice bag found
                    if (quan == -1) {
                        quan = rice[j][1]; // Set quantity
                        index = j; // Store the index of this rice bag
                    } else {
                        // If we have found a better rice bag (with smaller quantity)
                        if (quan > rice[j][1]) {
                            index = j; // Update index
                            quan = rice[j][1]; // Update quantity
                        }
                    }
                }
            }
        }
        // If a suitable rice bag was found for this customer
        if (index != -1) {
            good[index] = 1; // Mark the rice bag as used
            ans++; // Increment the count of satisfied customers
        }
    }

    cout << ans; // Output the total number of satisfied customers
}
*/

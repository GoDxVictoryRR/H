/*
Good String
A picnic to a famous museum is being planned in a school for class VI. When they reached the spot, the students started quarreling among themselves in the queue. So the teacher came up with an idea of “good string” which is explained below.
Good String is provided as input. All letters in this string are good letters. Good letters need to be used in further computations as explained below.
The teacher asked all the students to convert their names into good names with the help of good string. While converting, they have to calculate the distance. Based on that, she will arrange the students in a queue. For converting a name into good name, for each letter i in the name, select the nearest letter from the good name. Distance is calculated as the differences between the ASCII values of i and selected good letter. If there are two letters which are equidistant from i, select the letter which is nearest to the previously used good letter. In that case, distance will be the difference of ASCII value of previously used good letter and selected letter. If i is already present in the good string then no need to change it. Initially, previous good letter will be the first letter of good string. Calculate the total distance of the given name.
Given the name of the student who is confused of implementing this task. Help him to calculate the total distance for his name.
Note: Letters from good string can be reused any number of times.

Input Format
First line consists of good string.
Second line consists of the name of the student who is confused to implement the task.
Output Format
Print the total distance for that name.

Constraints
1
≤
1≤ len(good string) 
≤
100
≤100
1
≤
1≤ len(name) 
≤
10
4
≤10 
4
 
-Good string will consist of lower, upper case alphabets, digits and symbols.
-Name will consist of only space, lower and upper case alphabets.
-Characters are case sensitive.
The 
A
S
C
I
I
ASCII values for all the characters in the good string and name will be between 
32
32 to 
126
126 (both inclusive).

Sample 1:
Input
Output
(@HR*i{kcQl
Vyom
10
Explanation:
i
Previous good letter
Current good letter for i
V
(
R
y
R
{
o
{
l
m
l
l
The total distance will be |ASCII(V)-ASCII(R)| + |ASCII(y)-ASCII({)| + |ASCII(o)-ASCII(l)| + |ASCII(m)-ASCII(l)| = 4+2+3+1 = 10.

Sample 2:
Input
Output
6*K4AQf]gpi
Nainika
33
Explanation:
i
Previous good letter
Current good letter for i
N
6
K
a
K
]
i
–
–
n
]
p
i
–
–
k
p
i
a
i
]
Initially, Previous good letter=6. Since K and Q are at the same distance from N, so we select the character which is nearest to previous letter(6) which is K.
i is already present in the good string. So no need to change anything.
Therefore, total distance will be |ASCII(6)-ASCII(K)| + |ASCII(a)-ASCII(])| + |ASCII(n)-ASCII(p)| + |ASCII(k)-ASCII(i)| + |ASCII(a)-ASCII(])| = 21+4+2+2+4 = 33.
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    string good, name;
    getline(cin, good);   // Input string of "good" letters (allowed characters)
    getline(cin, name);   // Input student's name (string to check)

    int totalDist = 0;    
    char prev = good[0];  // Keep track of the last chosen "good" letter (start with the 1st good letter)

    // Loop over each character in the student's name
    for (char c : name) {
        
        // Case 1: If the current letter is already in the "good" set
        if (good.find(c) != string::npos) {
            prev = c;   // No change needed, just update `prev`
            continue;
        }

        // Case 2: Letter is not "good" → find the closest "good" letter
        int bestDist = INT_MAX;   // Minimum distance found so far
        char chosen = good[0];    // Best replacement letter found

        for (char g : good) {     // Check each "good" letter
            int d = abs(c - g);   // Distance between current letter and good letter

            // If this letter is closer → choose it
            if (d < bestDist) {
                bestDist = d;
                chosen = g;
            }
            // If tie (equal distance) → break tie by closeness to previous chosen good letter
            else if (d == bestDist) {
                if (abs(prev - g) < abs(prev - chosen)) {
                    chosen = g;
                }
            }
        }

        // Add cost of replacement (difference between original char and chosen good char)
        totalDist += abs(c - chosen);

        // Update prev (last chosen good letter) for tie-breaking in future
        prev = chosen;
    }

    // Print total cost of converting all bad letters into good letters
    cout << totalDist << endl;
    return 0;
}

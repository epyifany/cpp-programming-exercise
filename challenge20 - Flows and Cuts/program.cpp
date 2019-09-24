// program.cpp
// challenge20
// Yifan Yu
// yyu3
// Nov 15, 2018

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

// 3. Calculate the min bandwidth of the path from s to v.
int returnMin(vector<vector<int> > &adjvect, const vector<int> vect, int minband, int v, int s)
{
    int u = vect[v];
    minband = min(minband, adjvect[u][v]);

    if (u != s)
        minband = returnMin(adjvect, vect, minband, u, s);

    adjvect[u][v] -= minband;
    adjvect[v][u] += minband;
    return minband;
}

int main()
{
    int network = 1, temp;
    while (cin >> temp, temp != 0)
    {
        vector<vector<int> > adjvect(temp + 1, vector<int>(temp + 1, 0));

        int s, t, c;
        cin >> s >> t >> c;
        for (int i = 1; i <= c; ++i)
        {
            int u, v, bandwidth;
            cin >> u >> v >> bandwidth;
            adjvect[u][v] += bandwidth;
            adjvect[v][u] += bandwidth;
        }

        int maxBand = 0;

        //2. Using BFS to find a path from s to t.
        while (true)
        {

            vector<int> vect(temp + 1, -1); // The path.
            queue<int> q;

            vect[s] = s;
            q.push(s);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int v = 1; v <= temp; ++v)
                    if (adjvect[u][v] > 0 && vect[v] == -1)
                    {
                        vect[v] = u;
                        q.push(v);
                    }
            }
            if (vect[t] == -1) {break; }

            maxBand += returnMin(adjvect, vect, 100, t, s);
        }
        //4. Output
        cout << "Network " << network++ << ": Bandwidth is " << maxBand << "." << endl;
    }
    return 0;
}

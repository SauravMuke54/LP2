//Maze problem using A* (man hatten distance)
#include <bits/stdc++.h>

using namespace std;

int heuristic(int x,int y,int endi,int endj){
    //man hatten distance as heuristic function
    return abs(x-endi)+abs(y-endj);
}

int main()
{
    int n, m;
    cout << "Enter the number of rows and columns in the matrix: " << endl;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));

    int p;
    cout << "Enter the number of blocking states: " << endl;
    cin >> p;

    while (p--)
    {
        int i, j;
        cout << "Enter a blocked index in matrix (i, j): " << endl;
        cin >> i >> j;
        grid[i][j] = 1;
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> pq;

    int starti, startj;
    cout << "Enter the starting index in the matrix (i, j): " << endl;
    cin >> starti >> startj;

    int endi, endj;
    cout << "Enter the destination index in the matrix (i, j): " << endl;
    cin >> endi >> endj;

    if (grid[starti][startj] == 1 || grid[endi][endj] == 1)
    {
        cout << "Start or end cannot be a blocking state." << endl;
        return 0;
    }

    pq.push({0,{0, {starti, startj}}}); // manhatten distance,block distance,x,y 
    visited[starti][startj] = 1;

    int mdistance = 0;
    int distance=0;
    int flag = 0;

    int rows[] = {1, -1, 0, 0,1,1,-1,-1};
    int cols[] = {0, 0, -1, 1,-1,1,-1,1};

    while (!pq.empty())
    {
        int mdist = pq.top().first;
        int dist=pq.top().second.first;
        int x = pq.top().second.second.first;
        int y = pq.top().second.second.second;

        pq.pop();

        if (x == endi && y == endj)
        {
            flag = 1;
            mdistance=mdist;
            distance = dist;
            break;
        }

        for (int i = 0; i < 8; i++)
        {
            int nrow = rows[i] + x;
            int ncol = cols[i] + y;

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 0 && !visited[nrow][ncol])
            {
                visited[nrow][ncol] = 1;
                int mhdist=heuristic(nrow,ncol,endi,endj);
                pq.push({mhdist+mdist,{dist+1, {nrow, ncol}}});
                parent[nrow][ncol] = {x, y};
            }
        }
    }

    if (flag)
    {
        cout << "Distance to the destination is: " << distance << endl;
        cout<<"Manhatten distance is "<<mdistance<<endl;

        // Construct the shortest path
        vector<pair<int, int>> shortestPath;
        int currX = endi;
        int currY = endj;

        while (currX != starti || currY != startj)
        {
            shortestPath.push_back({currX, currY});
            pair<int, int> parentCoords = parent[currX][currY];
            currX = parentCoords.first;
            currY = parentCoords.second;
        }

        shortestPath.push_back({starti, startj});
            // Reverse the shortest path to print it in correct order
    reverse(shortestPath.begin(), shortestPath.end());

    // Print the shortest path
    cout << "Shortest path from start to end: ";
    for (auto coords : shortestPath)
    {
        cout << "(" << coords.first << ", " << coords.second << ") ";
    }
    cout << endl;
}
else
{
    cout << "Not able to reach the destination." << endl;
}

return 0;

}

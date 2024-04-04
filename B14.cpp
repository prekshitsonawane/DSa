#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0, 0};
int visited[50] = {0};

void dfs(int s, int n, string arr[])
{
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++)
    {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);
    }
}

void bfs(int s, int n, string arr[])
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int v;
    queue<int> bfsq;
    if (!visited[s])
    {
        cout << arr[s] << " ";
        bfsq.push(s);
        visited[s] = true;
        while (!bfsq.empty())
        {
            v = bfsq.front();
            for (int i = 0; i < n; i++)
            {
                if (adj_mat[v][i] && !visited[i])
                {
                    cout << arr[i] << " ";
                    visited[i] = true;
                    bfsq.push(i);
                }
            }
            bfsq.pop();
        }
    }
}

int main()
{
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city #" << i << " (Airport Code): ";
        cin >> cities[i];
    }
    
    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i << ": " << cities[i] << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "|\t" << cities[i] << "\t|";
    for (int i = 0; i < n; i++)
    {
        cout << "\n"
             << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }
    cout << "Enter Starting Vertex: ";
    cin >> u;
    cout << "DFS: ";
    dfs(u, n, cities);
    cout << endl;
    cout << "BFS: ";
    bfs(u, n, cities);
    return 0;
}

---------DSAL PRACTICAL NO-7-------------
 Enter no. of cities: 7
Enter city #0 (Airport Code): Nashik
Enter city #1 (Airport Code): Pune
Enter city #2 (Airport Code): Mumbai
Enter city #3 (Airport Code): Nagpur
Enter city #4 (Airport Code): Delhi
Enter city #5 (Airport Code): Goa
Enter city #6 (Airport Code): J.K

 Your cities are: 
city #0: Nashik
city #1: Pune
city #2: Mumbai
city #3: Nagpur
city #4: Delhi
city #5: Goa
city #6: J.K
Enter distance between Nashik and Pune : 80
Enter distance between Nashik and Mumbai : 200
Enter distance between Nashik and Nagpur : 0
Enter distance between Nashik and Delhi : 0
Enter distance between Nashik and Goa : 0
Enter distance between Nashik and J.K : 0
Enter distance between Pune and Mumbai : 0
Enter distance between Pune and Nagpur : 150
Enter distance between Pune and Delhi : 0
Enter distance between Pune and Goa : 0
Enter distance between Pune and J.K : 0
Enter distance between Mumbai and Nagpur : 0
Enter distance between Mumbai and Delhi : 0
Enter distance between Mumbai and Goa : 0
Enter distance between Mumbai and J.K : 0
Enter distance between Nagpur and Delhi : 0
Enter distance between Nagpur and Goa : 0
Enter distance between Nagpur and J.K : 0
Enter distance between Delhi and Goa : 0
Enter distance between Delhi and J.K : 100
Enter distance between Goa and J.K : 715

	Nashik		Pune		Mumbai		Nagpur		Delhi		Goa		J.K	
Nashik|	0	|	80	|	200	|	0	|	0	|	0	|	0	

Pune|	80	|	0	|	0	|	150	|	0	|	0	|	0	

Mumbai|	200	|	0	|	0	|	0	|	0	|	0	|	0	

Nagpur|	0	|	150	|	0	|	0	|	0	|	0	|	0	

Delhi|	0	|	0	|	0	|	0	|	0	|	0	|	100	

Goa|	0	|	0	|	0	|	0	|	0	|	0	|	715	

J.K|	0	|	0	|	0	|	0	|	100	|	715	|	0	
Enter Starting Vertex: 0
DFS: -> Nashik ->Pune ->Nagpur ->Mumbai ->
BFS:-> Nashik ->Pune ->Mumbai ->Nagpur ->

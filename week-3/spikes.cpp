#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> input_adj_mat(int n, int m, vector<vector<int>> &st)
{
    vector<vector<char>> res;
    for (int i = 0; i < n; i++)
    {
        vector<char> tempvec;
        for (int j = 0; j < m; j++)
        {
            char temp;
            cin >> temp;
            if (temp == '@')
            {
                vector<int> temp_start;
                temp_start.push_back(i);
                temp_start.push_back(j);
                st.push_back(temp_start);
            }
            tempvec.push_back(temp);
        }
        res.push_back(tempvec);
    }
    return res;
}

bool is_valid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

bool bfs(vector<vector<char>> arr, int n, int m, vector<int> st, int jumps)
{
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    queue<vector<int>> q;
    q.push(st);
    visited[st[0]][st[1]] = true; 
    while(!q.empty())
    {
        vector<int> v = q.front();
        q.pop();
        if (arr[v[0]][v[1]] == 'x')
        {
            return true;
        }
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int new_x = v[0] + dx[i];
            int new_y = v[1] + dy[i];
            if (is_valid(new_x, new_y, n, m) && !visited[new_x][new_y] && arr[new_x][new_y] != '#')
            {
                if (arr[new_x][new_y] == 'x')
                {
                    return true;
                }
                if (visited[new_x][new_y] == false)
                {
                    if (arr[new_x][new_y] == '.')
                    {
                        visited[new_x][new_y] = true;
                        vector<int> temp;
                        temp.push_back(new_x);
                        temp.push_back(new_y);
                        q.push(temp);
                    }
                    if (arr[new_x][new_y] == 's')
                    {
                        if (jumps > 0)
                        {
                            visited[new_x][new_y] = true;
                            vector<int> temp;
                            temp.push_back(new_x);
                            temp.push_back(new_y);
                            q.push(temp);
                            jumps--;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void print(vector<vector<char>> adj_mat, int n, int m)
{
    for (int j = 0; j < 2*m+1; j++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < m; j++)
            cout << adj_mat[i][j] << "|";
        cout << endl;
        for (int j = 0; j < 2*m+1; j++)
            cout << "-";
        cout << endl;
    }
}

int main()
{
    int n, m, jumps;
    vector<vector<int>> st;
    cin >> n >> m >> jumps;
    vector<vector<char>> adj_mat = input_adj_mat(n, m, st);
    for(auto it : st)
	{
		if (bfs(adj_mat, n, m, it , jumps/2) == true)
		{
			cout << "SUCCESS" << endl;
			return 0;
		}
 
	}
	cout << "IMPOSSIBLE" << endl;
    return 0;
}
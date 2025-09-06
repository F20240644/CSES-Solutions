#include <iostream>
#include <utility>
#include <queue>
#include <vector>

#define INF 1e9

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, 2, 1, -1, -2};

void bfs(std::vector<std::vector<int>> &grid, std::queue<std::pair<int, int>> &q)
{
    int n = grid.size();
    while (!q.empty())
    {
        auto p = q.front();
        int x = p.first, y = p.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            else
            {
                if (grid[nx][ny] > grid[x][y] + 1)
                {
                    q.push({nx, ny});
                    grid[nx][ny] = grid[x][y] + 1;
                }
            }
        }
    }
    return;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n, INF));
    std::queue<std::pair<int, int>> q;
    grid[0][0] = 0;
    q.push({0, 0});
    bfs(grid, q);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
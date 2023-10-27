#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<vector<int>> floyd_warshall(vector<vector<int>> paths)
{
    int size = paths.size();
    int max = 1000;
    vector<vector<int>> distance_matrix(size, vector<int>(size, max));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (paths[i][j] != 0)
            {
                distance_matrix[i][j] = paths[i][j];
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        distance_matrix[i][i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                if (distance_matrix[j][k] > distance_matrix[j][i] + distance_matrix[i][k])
                    distance_matrix[j][k] = distance_matrix[j][i] + distance_matrix[i][k];
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (distance_matrix[i][j] == max)
            {
                distance_matrix[i][j] = -1;
            }
        }
    }
    return distance_matrix;
}
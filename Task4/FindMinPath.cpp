#include <iostream>
#include "FindMinPath.h"

std::vector<int> get_row(std::string row) {
    std::stringstream row_s;
    row_s << row;
    std::vector<int> result;
    std::string point;
    while (std::getline(row_s, point, ' ')) {
        try {
            result.push_back(std::stoi(point));
        }
        catch (std::invalid_argument) {
            exit(-1);
        }
    }
    return result;
}


std::pair<std::vector<int>, std::vector<int>> get_path(vertice *v, int n, int j_start, int j_finish) {

    int i = n - 1;
    int j = j_finish;
    std::vector<int> path_X;
    std::vector<int> path_Y;
    while (i != 0 || j != j_start) {
        path_X.push_back(i);
        path_Y.push_back(j);
        switch (v[i * n + j].previous) {
            case up:
                i -= 1;
                break;
            case own_right:
                j += 1;
                break;
            case own_left:
                j -= 1;
                break;
        }
    }
    path_X.push_back(i);
    path_Y.push_back(j);
    std::pair<std::vector<int>, std::vector<int>> results;
    results.first=path_X;
    results.second=path_Y;

    return results;
}

std::pair<int,int> FindMinimumNeightbor(vertice *p, int n, int k) {
    int min_weight = std::numeric_limits<int>::max();
    std::pair<int,int> min_indexes;
    min_indexes.first = -1;  //-1 to detect if min not found
    min_indexes.second = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; ++j) {
            if (!(p[i*n+j].visited) && (p[i*n+j].path_weight < min_weight)) {
                min_weight = p[i*n+j].path_weight;
                min_indexes.first = i;
                min_indexes.second = j;
            }
        }
    }

    return min_indexes;
}

void findMinimumPath(int **arr, std::vector<int> &path, int x_i, int x_f, int rows, int cols) {
    vertice p[rows][cols];
    path.clear();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            p[i][j].weight = arr[i][j];
            p[i][j].visited = false;
            p[i][j].path_weight = std::numeric_limits<int>::max();
            p[i][j].previous = none;
        }
    }
    p[0][x_i].path_weight = 0;

    while (true) {
        std::pair<int, int> min_ind = FindMinimumNeightbor(&p[0][0], rows, cols);
        int i_min = min_ind.first;
        int j_min = min_ind.second;

        if (i_min != -1) {
            if ((i_min != rows - 1) && (!p[i_min + 1][j_min].visited) &&
                (p[i_min + 1][j_min].path_weight > p[i_min][j_min].path_weight + p[i_min][j_min].weight)) {
                p[i_min + 1][j_min].path_weight =
                        p[i_min][j_min].path_weight + p[i_min][j_min].weight;
                p[i_min + 1][j_min].previous = up;
            }

            if ((j_min != cols - 1)
                && (!p[i_min][j_min + 1].visited)
                && (p[i_min][j_min + 1].path_weight >
                    p[i_min][j_min].path_weight + p[i_min][j_min].weight)) {

                p[i_min][j_min + 1].path_weight =
                        p[i_min][j_min].path_weight + p[i_min][j_min].weight;
                p[i_min][j_min + 1].previous = own_left;
            }

            if ((j_min != 0)
                && (!p[i_min][j_min - 1].visited)
                && (p[i_min][j_min - 1].path_weight >
                    p[i_min][j_min].path_weight + p[i_min][j_min].weight)) {

                p[i_min][j_min - 1].path_weight =
                        p[i_min][j_min].path_weight + p[i_min][j_min].weight;
                p[i_min][j_min - 1].previous = own_right;
            }
            p[i_min][j_min].visited = true;
        } else {
            break;
        }
    }

    std::pair<std::vector<int>, std::vector<int>> path_back = get_path(&p[0][0], rows, x_i, x_f);
    for (int l = path_back.second.size() - 1; l >= 0; --l) {
        path_back.first[l] = rows - 1 - path_back.first[l];
        path.push_back(path_back.second[l]);
    }
}
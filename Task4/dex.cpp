#include "dex.h"
#include <math.h>

vertex::vertex() {
    path_weight = 0;
    weight = pow(10,10);
    visited = false;
}

FindMinimumPath::FindMinimumPath(int _size, int _i1, int _j1, int _i2, int _j2) {
    size = _size;
    i_start = _i1;
    j_start = _j1;
    i_end = _i2;
    j_end = _j2;
    for (int i = 0; i < size; i++){
        connection_matrix[i] = new vertex [size];
    }
}

vector<vertex> FindMinimumPath::solve() {
    connection_matrix[i_start][j_start].weight = 0;

}

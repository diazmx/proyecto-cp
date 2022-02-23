/*
 * Created by: Daniel Díaz
 * Institution CINVESTAV Guadalajara
 * Date: 23-02-22
 * To compile:
 *      gcc -o louvain louvain.c
 *
 * Louvain algorithm implementation using matrix based on:
 * ---------------------------------
 * Blondel, V. D., Guillaume, J. L., Lambiotte, R., & Lefebvre, E. (2008).
 * Fast unfolding of communities in large networks. Journal of statistical
 * mechanics: theory and experiment, 2008(10), P10008.
 * doi:10.1088/1742-5468/2008/10/P10008.
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Read Adjacency Matrix from a file
int readAdjacencyMatrix(const char *filename_, int size_, int (*matrix_)[size_]);

int main(int argc, char const *argv[])
{
    printf("START! \n");

    int size = 4;
    int matrix[size][size];

    readAdjacencyMatrix("matrix.txt", size, matrix);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            printf("%-3d ", matrix[i][j]);
        puts("");
    }

    printf("END! \n");
    return 0;
}

int readAdjacencyMatrix(const char *filename_, int size_, int (*matrix_)[size_])
{
    FILE *pf;
    pf = fopen(filename_, "r");
    if (pf == NULL)
        return 0;

    for (int i = 0; i < size_; ++i)
    {
        for (int j = 0; j < size_; ++j)
            fscanf(pf, "%d", matrix_[i] + j);
    }

    fclose(pf);
    return 1;
}

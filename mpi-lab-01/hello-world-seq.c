/*
 * A template for the 2016 MPI lab at the University of Warsaw.
 * Copyright (C) 2016, Konrad Iwanicki
 * Further modifications by Krzysztof Rzadca 2018
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI_Init(&argc,&argv);

    int numProcesses, myRank;
    MPI_Comm_size(MPI_COMM_WORLD, &numProcesses);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
    printf("Hello world from %d!\n", myRank);
    if (myRank == 0) {
        printf("Total number of processes = %d\n", numProcesses);
    }

    MPI_Finalize();

    return 0;
}

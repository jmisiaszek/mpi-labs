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

    if (myRank == 0) {
        int buf[2];
        for (int i = 1; i < numProcesses; i++) {
            MPI_Recv(
                buf,
                2,
                MPI_INT,
                MPI_ANY_SOURCE,
                MPI_ANY_TAG,
                MPI_COMM_WORLD,
                MPI_STATUS_IGNORE
            );
            printf("Process %d sent %d\n", buf[0], buf[1]);
        }
    }
    else {
        srand(time(NULL) + myRank);

        int rnum = (rand() % 11);
        int buf[2] = {myRank, rnum};
        MPI_Send(
            buf,
            2,
            MPI_INT,
            0,
            0,
            MPI_COMM_WORLD
        );
    }

    MPI_Finalize();

    return 0;
}

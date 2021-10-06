/*
    Alex Kleb
    Testing MPI Startup
    With python scripts
*/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    if (argc != 2){
        printf("Expected a flag to determine if MPI_Init should be called.\n");
        exit(1);
    } //if

    int try;
    try = atoi(argv[1]);

    if (try){
        printf("Calling MPI_Init()\n");
        MPI_Init(&argc, &argv);
    } //if
    else printf("Not Calling MPI_Init()\n");

    int id, p;
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    printf("Hello from proc %d out of %d\n", id, p);

    if (try){
        printf("Calling MPI_Finalize()\n");
        MPI_Finalize();
    } // if
    else MPI_Finalize();

    return 0;

} //main

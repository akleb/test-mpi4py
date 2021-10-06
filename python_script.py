#! /usr/bin/env python
import subprocess
from mpi4py import MPI

print("Trying with MPI_Init()")
print(subprocess.run("mpirun -np 2 ./main 1", shell=True))
MPI.COMM_WORLD.Spawn("./main", args=["1"], maxprocs=2)

print("Trying without MPI_Init()")
print(subprocess.run("mpirun -np 2 ./main 0", shell=True))

#!/bin/bash
#PBS -l select=2:ncpus=8:mem=2gb
#PBS -l walltime=0:05:00
#PBS -q short_cpuQ


module load mpich-3.2
mpicc -g -Wall -fopenmp -o hybrid_parallel hybrid_parallel.c -std=c99 -lm 
mpirun.actual -n 10 ./hybrid_parallel


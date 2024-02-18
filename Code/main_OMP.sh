#!/bin/bash
#PBS -l select=2:ncpus=8:mem=2gb
#PBS -l walltime=1:00:00
#PBS -q short_cpuQ


gcc -g -Wall -fopenmp -o OMP_parallel OMP_parallel.c -std=c99 -lm
./OMP_parallel 
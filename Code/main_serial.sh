#!/bin/bash
#PBS -l select=1:ncpus=1:mem=2gb
#PBS -l walltime=1:00:00
#PBS -q short_cpuQ


gcc -g -Wall -o serial serial.c -std=c99 -lm
./serial
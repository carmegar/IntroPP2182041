#!/bin/bash

#SBATCH -p normal
#SBATCH --ntasks=4
#SBATCH --output=output_postmansort.txt
#SBATCH --error=error_%j.txt
#SBATCH --mail-user=carmegar12@gmail.com
#SBATCH --cpus-per-task=4
#SBATCH -w guane10

gcc -fopenmp omp_postman.cpp -o omp_postman
./omp_postman
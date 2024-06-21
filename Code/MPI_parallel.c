#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

#define ROWS 100000000
#define COLS 4
#define K 9

double dataset[ROWS][COLS];
int cluster[ROWS];
double centroids[K][COLS];

void salvaTempisticheCSV(const char *nomeFile, int numeroDati, double ioTime, double kmeansTime, double totTime, double avgIterTime) {
    FILE *file = fopen(nomeFile, "a");
    if (file == NULL) {
        printf("Impossible to open the file %s.\n", nomeFile);
        return;
    }
    fprintf(file, "%d, %.6lf, %.6lf, %.6lf, %.6lf \n", numeroDati, ioTime, kmeansTime, totTime, avgIterTime);
    fclose(file);
}

void eliminaContenutoCSV(const char *nomeFile) {

    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        printf("Impossibile aprire il file %s.\n", nomeFile);
        return;
    }

    char primaRiga[1024];
    if (fgets(primaRiga, sizeof(primaRiga), file) == NULL) {
        printf("Errore nella lettura della prima riga.\n");
        fclose(file);
        return;
    }
    fclose(file);

    file = fopen(nomeFile, "w");
    if (file == NULL) {
        printf("Impossibile aprire il file %s in modalità di sovrascrittura.\n", nomeFile);
        return;
    }

    fprintf(file, "%s", primaRiga);
    fclose(file);
}

void write_centroids (int num_perc) {
    if (num_perc == 1) {
        FILE *fi = fopen("centroids_10.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 2) {
        FILE *fi = fopen("centroids_20.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 3) {
        FILE *fi = fopen("centroids_30.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 4) {
        FILE *fi = fopen("centroids_40.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 5) {
        FILE *fi = fopen("centroids_50.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 6) {
        FILE *fi = fopen("centroids_60.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 7) {
        FILE *fi = fopen("centroids_70.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 8) {
        FILE *fi = fopen("centroids_80.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 9) {
        FILE *fi = fopen("centroids_90.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    }
    if (num_perc == 10) {
        FILE *fi = fopen("centroids_100.csv", "w");
        if (fi == NULL) {
            printf("Failed to open the file for writing.");
        }
        for(int i = 0; i<K; i++){
            for(int j = 0; j<COLS; j++){
                fprintf(fi," %f, ", centroids[i][j]);
            }
            fprintf(fi,"\n");
        }
        fclose(fi); 
    } 
}

void read_dataset(float percentage) {

    int partial_nr_ROWS = (int)(ROWS * percentage);

    FILE* file = fopen("generated_data_k_9_100M.csv","r");
    
    char buffer[130];
    int row = 0;
    while (fgets(buffer, 130, file)) {
        
        // get all the values in a row
        char *token = strtok(buffer, ",");
        int col = 0;
        while (token) {
            
            // Just printing each integer here but handle as needed
            float n = atof(token);
            
            dataset[row][col] = n;
            token = strtok(NULL, ",");
            col++;          
        }
        if (row == partial_nr_ROWS) {
            break;
        }
        row++;
    }
    fclose(file);
}

double euclidean_distance(int a, int b) {
    double sum = 0;
    for (int i = 0; i < COLS; i++) {
        sum += pow(dataset[a][i] - centroids[b][i], 2);
    }
    return sqrt(sum);
}

void kmeans(int rank, int size, double *sum_iter_kmeans_time) {
    
    double t1, t2, t_per_iter;

    // Initialize centroids randomly
    if (rank == 0) {
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < COLS; j++) {
                centroids[i][j] = dataset[rand() % ROWS][j];
            }
        }
    }

    // Broadcast initial centroids to all processes
    MPI_Bcast(centroids, K*COLS, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    int iter = 10;
    int tt = 0;

    t1 = MPI_Wtime();

    while (tt<iter) {
        // Assign points to closest centroid
        int start = rank * ROWS / size;
        int end = (rank + 1) * ROWS / size;

        for (int i = start; i < end; i++) {
            double min_distance = DBL_MAX;
            int min_index = 0;

            for (int j = 0; j < K; j++) {
                double distance = euclidean_distance(i, j);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_index = j;
                }
            }

            if (cluster[i] != min_index) {
                cluster[i] = min_index;
            }
        }
        
        MPI_Barrier(MPI_COMM_WORLD);

        double local_sum[K][COLS] = {{0}};
        int local_count[K] = {0};

        for (int i = start; i < end; i++){
            for(int j = 0; j < COLS; j++){
                local_sum[cluster[i]][j] += dataset[i][j];
            }
            local_count[cluster[i]]++;
        }

        MPI_Barrier(MPI_COMM_WORLD);

        double global_sum[K][COLS]={{0}};
        int global_count[K]={0};

        MPI_Allreduce(  &local_sum,
                        &global_sum,
                        K*COLS,
                        MPI_DOUBLE,
                        MPI_SUM,
                        MPI_COMM_WORLD);

        
        MPI_Allreduce(  &local_count,
                        &global_count,
                        K,
                        MPI_INT,
                        MPI_SUM,
                        MPI_COMM_WORLD);


        for (int i = 0; i < K; i++) {
            for (int j = 0; j < COLS; j++) {
                if (global_count[i] != 0) {
                    centroids[i][j] = global_sum[i][j] / global_count[i];
                }
            }
        } 
        tt++;
    }
    t2 = (MPI_Wtime()-t1);
    t_per_iter = t2 / iter;
    
    MPI_Allreduce(&t_per_iter, sum_iter_kmeans_time, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
}

int main(int argc, char **argv) {
    double time1, time2, time3;
    double reading_time, kmean_time, total_time;
    double max_reading, max_kmeans, max_total;

    double sum_iter_kmeans_time;
    double avg_iter_kmeans_time;

    int rank, size;
    
    const char *nomeFile = "Time Results MPI.csv";
    eliminaContenutoCSV(nomeFile);

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    for (int i = 1; i < 11; i++){ 
        float x = 0.10*i;  
        int partial_nr_ROWS = (int)(ROWS * x);

        time1 = MPI_Wtime();

        read_dataset(x);

        time2 = MPI_Wtime();

        kmeans(rank, size, &sum_iter_kmeans_time);
        
        time3 = MPI_Wtime();

        write_centroids(i);

        reading_time = time2 - time1;
        kmean_time = time3 - time2;
        total_time = time3 - time1;

        // Using MPI_Reduce in order to calculate il max time for each phase
        MPI_Reduce( &reading_time,
                    &max_reading,
                    1,
                    MPI_DOUBLE,
                    MPI_MAX,
                    0,
                    MPI_COMM_WORLD);
        MPI_Reduce( &kmean_time,
                    &max_kmeans,
                    1,
                    MPI_DOUBLE,
                    MPI_MAX,
                    0,
                    MPI_COMM_WORLD);
        MPI_Reduce( &total_time,
                    &max_total,
                    1,
                    MPI_DOUBLE,
                    MPI_MAX,
                    0,
                    MPI_COMM_WORLD);

        if (rank==0){
            avg_iter_kmeans_time = (sum_iter_kmeans_time / size);

            printf("\n---------- PERCENTAGE OF DATABASE: %f ----------\n", x);
            printf("\nI/O time (s): %f", max_reading);
            printf("\nK-means algorithm time (s): %f", max_kmeans);
            printf("\nTotal time (s): %f", max_total);
            printf("\nAverage iteration time in k-means (s)\n: %f", avg_iter_kmeans_time);
            salvaTempisticheCSV(nomeFile, partial_nr_ROWS, max_reading, max_kmeans, max_total, sum_iter_kmeans_time);
        }
        
        MPI_Barrier(MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}

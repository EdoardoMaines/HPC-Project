#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

#define ROWS 100000000
#define COLS 4
#define K 6

double dataset[ROWS][COLS];
int cluster[ROWS];
double centroids[K][COLS];

void salvaTempisticheCSV(const char *nomeFile, int numeroDati, double ioTime, double kmeansTime, double totTime, double avgIterTime) {
    FILE *file = fopen(nomeFile, "a");
    if (file == NULL) {
        printf("Impossible to open the file %s.\n", nomeFile);
        return;
    }
    //fprintf(file, "#Data,I/O Time,Kmeans Time,Total Time\n");
    fprintf(file, "%d, %.6lf, %.6lf, %.6lf, %.6lf \n", numeroDati, ioTime, kmeansTime, totTime, avgIterTime);
    fclose(file);
}

void eliminaContenutoCSV(const char *nomeFile) {

    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        printf("Impossible to open the file %s.\n", nomeFile);
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
    //char file_name[30];
    if (num_perc == 1) {
        //strcpy(file_name, "centroids_10.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 2) {
        //strcpy(file_name, "centroids_20.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 3) {
        //strcpy(file_name, "centroids_30.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 4) {
        //strcpy(file_name, "centroids_40.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 5) {
        //strcpy(file_name, "centroids_50.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 6) {
        //strcpy(file_name, "centroids_60.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 7) {
        //strcpy(file_name, "centroids_70.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 8) {
        //strcpy(file_name, "centroids_80.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 9) {
        //strcpy(file_name, "centroids_90.csv");
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
        // Close the file
        fclose(fi); 
    }
    if (num_perc == 10) {
        //strcpy(file_name, "centroids_100.csv");
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
        // Close the file
        fclose(fi); 
    } 
}

void read_dataset(float percentage) {

    int partial_nr_ROWS = (int)(ROWS * percentage);

    FILE* file = fopen("generated_data_k_6_100M.csv","r");
    
    char buffer[130];
    int row = 0;
    while (fgets(buffer, 130, file)) {
        
        // get all the values in a row
        char *token = strtok(buffer, ",");
        int col = 0;
        while (token) {
            
            // Just printing each integer here but handle as needed
            float n = atof(token);
            // printf("%f\n", n);
            
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

void kmeans(double *sum_iter_kmeans_time, int num_perc) {

    // Initialize centroids randomly
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < COLS; j++) {
            centroids[i][j] = dataset[rand() % ROWS][j];
        }
    }
    
    //Iterations
    int iter = 10;
    int tt = 0;

    // All timers
    clock_t time;

    // Private copy of the count array for each thread
    int count_private[K] = {0}; 
    double sum_private[K][COLS] = {{0}};

    // Recalculate centroids
    int count[K] = {0};
    double sum[K][COLS] = {{0}};
        
    while (tt<iter) {
        
        // Start the timer in order to calculate how a thread takes to compute an iteration of the algorithm
        time = clock();
        // Assign points to closest centroid
        
        for (int i = 0; i < ROWS; i++) {
            double min_distance = DBL_MAX;
            int min_index = 0;

            for (int j = 0; j < K; j++) {
                //double distance = euclidean_distance(dataset[i], centroids[j]);
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
        
        for (int i = 0; i < ROWS; i++) {
            count_private[cluster[i]]++;
            for (int j = 0; j < COLS; j++) {
                sum_private[cluster[i]][j] += dataset[i][j];
            }
        }

        for (int i = 0; i < K; i++) {
            count[i] += count_private[i];
            for (int j = 0; j < COLS; j++) {
                sum[i][j] += sum_private[i][j];
            }
        }
        
        for (int i = 0; i < K; i++) {
            if (count[i] != 0) {
                for (int j = 0; j < COLS; j++) {
                    centroids[i][j] = sum[i][j] / count[i];
                }
            }
        }
        tt++;
        time = (clock() - time) / iter;
        *sum_iter_kmeans_time += time;

    }
    

    // // Write the final centroids to a file
    FILE *fi = fopen("centroids.csv", "w");
    if (fi == NULL) {
        printf("Failed to open the file for writing.");
    }
    // Write the list elements to the file
    for(int i = 0; i<K; i++){
        for(int j = 0; j<COLS; j++){
            fprintf(fi," %f, ", centroids[i][j]);
        }
        fprintf(fi,"\n");
    }
    // Close the file
    fclose(fi);
    
}

int main(int argc, char **argv) {
    clock_t t1, t2, t3;
    clock_t reading_time, kmean_time, total_time;

    double sum_iter_kmeans_time;
    double avg_iter_kmeans_time;

    const char *nomeFile = "Time Results OMP.csv";
    eliminaContenutoCSV(nomeFile);
    
    for (int i = 10; i < 11; i++){
        float x = 0.10*i;
        int partial_nr_ROWS = (int)(ROWS * x);

        t1 = clock();

        read_dataset(x);

        t2 = clock();
        
        kmeans(&sum_iter_kmeans_time, i);

        t3 = clock();

        write_centroids(i);

        reading_time = t2 - t1;
        kmean_time = t3 - t2;
        total_time = t3 - t1;
        
        avg_iter_kmeans_time = sum_iter_kmeans_time;

        printf("\n---------- PERCENTAGE OF DATABASE: %f ----------\n", x);
        printf("\nThe I/O PHASE took %f seconds", (double)reading_time/CLOCKS_PER_SEC);
        printf("\nThe K-MEANS ALGORITHM took %f seconds", (double)kmean_time/CLOCKS_PER_SEC);
        printf("\nThe COMPLETE ALGORITHM took %f seconds\n", (double)total_time/CLOCKS_PER_SEC);
        salvaTempisticheCSV(nomeFile, partial_nr_ROWS, reading_time, kmean_time, total_time, avg_iter_kmeans_time);   
    }
    return 0;
}

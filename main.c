#include <stdio.h>    // io operations
#include <stdlib.h>   // memory allocation
#include <omp.h>      // OpenMP, parallel programming

// write_one: write 1.0 to each element of the array
void write_one(double *v, long len);

// read_sum: read the sum of the array
double read_sum(double *v, long len);

/*
   * main: main function
*/
int main()
{
    // 1 billion doubles
    long N = 1000 * 1000 * 1000;

    // allocate memory
    double *v = malloc(N * sizeof(double));

    // start timer
    double t1 = omp_get_wtime();

    // start write
    printf("Write\n");
    write_one(v, N);

    // record time
    double t2 = omp_get_wtime();

    // start read
    printf("Read\n");
    double sum = read_sum(v, N);

    // stop timer
    double t3 = omp_get_wtime();

    // print results
    printf("Sum = %f\n", sum);
    printf("Bandwidth write = %f MB/s\n", N * sizeof(double) / 1e6 / (t2 - t1));
    printf("Bandwidth read = %f MB/s\n", N * sizeof(double) / 1e6 / (t3 - t2));
    free(v);
    return 0;
}

/*
    * write_one: write 1.0 to each element of the array
    * @v: array
    * @len: length of the array
*/
void write_one(double *v, long len)
{
    for (long i = 0; i < len; i++) {
        v[i] = 1.0;
    }
}

/*
    * read_sum: read the sum of the array
    * @v: array
    * @len: length of the array
    * @return: sum of the array
*/
double read_sum(double *v, long len)
{
    double sum = 0.0;

    for (long i = 0; i < len; i++) {
        sum += v[i];
    }
    return sum;
}
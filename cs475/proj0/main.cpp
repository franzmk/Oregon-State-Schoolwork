//To compile: g++ -o proj main.cpp -lm -fopenmp

#include <omp.h>
#include <stdio.h>
#include <math.h>


#define SIZE       	16000	// you decide
#define NUMTRIES        20	// you decide

float A[SIZE];
float B[SIZE];
float C[SIZE];

int main() {
#ifndef _OPENMP
        fprintf( stderr, "OpenMP is not supported here -- sorry.\n" );
        return 1;
#endif
        int NUMT = 1;
        double oneMegaMults = 0.;
        double fourMegaMults = 0.;
        double speedup = 0.;
	double totalTime = 0.;

        for(int u = 0; u < 2; u++) {
                // inialize the arrays:
                for(int i = 0; i < SIZE; i++) {
                        A[ i ] = 1.;
                        B[ i ] = 2.;
                }

                omp_set_num_threads(NUMT);
                fprintf(stderr, "Using %d threads\n", NUMT);

                double maxMegaMults = 0.;
                double avgMegaMults = 0.;

                for(int t = 0; t < NUMTRIES; t++) {
                        double time0 = omp_get_wtime( );

                        #pragma omp parallel for
                        for(int i = 0; i < SIZE; i++) {
                                C[i] = A[i] * B[i];
                        }

                        double time1 = omp_get_wtime( );
                        double megaMults = (double)SIZE/(time1-time0)/1000000.;
                        if(megaMults > maxMegaMults)
                                maxMegaMults = megaMults;
                        avgMegaMults += megaMults;

			
                        totalTime += ((time1-time0)/1000000.);

                }

                if(NUMT == 1) {
                        oneMegaMults = maxMegaMults;
                } else if(NUMT == 4) {
                        fourMegaMults = maxMegaMults;
                }

                printf("Peak Performance = %8.2lf MegaMults/Sec\n", maxMegaMults);
                printf("Average Performance = %8.2lf MegaMults/Sec\n", avgMegaMults/NUMTRIES);
		printf("Average Time = %8.2lf\n", totalTime/NUMTRIES);
                printf("\n");

                // note: %lf stands for "long float", which is how printf prints a "double"
                //        %d stands for "decimal integer", not "double"
                NUMT = 4;
        }

        speedup = fourMegaMults / oneMegaMults;
        printf("Speedup = %8.2lf\n", speedup);

        float Fp = (4./3.)*( 1. - (1./speedup));
        printf("Parallel Fraction = %8.2f\n", Fp);

        return 0;
}

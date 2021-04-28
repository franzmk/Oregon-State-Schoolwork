//Max Franz
//To compile: g++ -o proj main.cpp -lm -fopenmp
//To run: ./proj <numThreads> <numNodes>

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define XMIN     -1.
#define XMAX      1.
#define YMIN     -1.
#define YMAX      1.

#define N	0.70

int NUMT;
int NUMNODES;

float Height( int, int );	// function prototype

int main( int argc, char *argv[ ] )
{
	if( argc >= 2 )
		NUMT = atoi( argv[1] );
	if( argc >= 3 )
		NUMNODES = atoi( argv[2] );

	omp_set_num_threads( NUMT );

	// the area of a single full-sized tile:
	// (not all tiles are full-sized, though)

	float fullTileArea = (  ( ( XMAX - XMIN )/(float)(NUMNODES-1) )  *
				( ( YMAX - YMIN )/(float)(NUMNODES-1) )  );

    double volume = 0.;
	// sum up the weighted heights into the variable "volume"
	// using an OpenMP for loop and a reduction:

    double time0 = omp_get_wtime( );

	#pragma omp parallel for default(none), shared(NUMNODES, fullTileArea), reduction(+:volume)
    for( int i = 0; i < NUMNODES*NUMNODES; i++ ) {
	    int iu = i % NUMNODES;
	    int iv = i / NUMNODES;
        float z;

	    if((iu == NUMNODES - 1 && iv == NUMNODES - 1) || (iu == 0 && iv == 0) || (iu == NUMNODES - 1 && iv == 0) || (iu == 0 && iv == NUMNODES - 1)) {
            z = 0.25 * Height(iu, iv) * fullTileArea;
        } else if((iu == 0 && (0 < iv && iv < NUMNODES - 1)) || ((0 < iu && iu < NUMNODES - 1) && iv == 0) || (iu == NUMNODES - 1 && (0 < iv && iv < NUMNODES - 1)) || ((0 < iu && iu < NUMNODES - 1) && iv == NUMNODES - 1)) {
            z = 0.5 * Height(iu, iv) * fullTileArea;
        } else {
            z = Height(iu, iv) * fullTileArea;
        }

        volume += z;
    }

    double time1 = omp_get_wtime( );
    double megaHeightsPerSecond = (double)(NUMNODES * NUMNODES) / ( time1 - time0 ) / 1000000.;
    fprintf(stdout, "%2d threads : %8d nodes ; volume = %6.6lf ; megaheights/sec = %6.6lf\n",
		NUMT, NUMNODES, volume*2.000000, megaHeightsPerSecond);

    return 0;
}

float Height( int iu, int iv )	// iu,iv = 0 .. NUMNODES-1
{
	float x = -1.  +  2.*(float)iu /(float)(NUMNODES-1);	// -1. to +1.
	float y = -1.  +  2.*(float)iv /(float)(NUMNODES-1);	// -1. to +1.

	float xn = pow( fabs(x), (double)N );
	float yn = pow( fabs(y), (double)N );
	float r = 1. - xn - yn;
	if( r <= 0. )
	        return 0.;
	float height = pow( r, 1./(float)N );
	return height;
}
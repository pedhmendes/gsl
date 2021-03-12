///////////////////////////
////GAUSS DISTRIBUITION////
////////PEDRO MENDES///////
///////////////////////////

// compile	-> gcc -Wall gauss_dist.c -lgsl -lgslcblas -lm
// run		-> ./a.out > serie.dsf
	
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<gsl/gsl_rng.h>
#include<gsl/gsl_randist.h>

#define 	TMAX		100 
#define 	dt		0.001

int main()
{
	double t;
	double n_gauss, sigma;
	unsigned long int seed;

	srand(time(NULL));
	seed = rand();

	gsl_rng *mt;
	mt = gsl_rng_alloc(gsl_rng_mt19937);
	gsl_rng_set(mt, seed);

	sigma = 1.0;
	t = 0.0;


	while(t < TMAX)
	{
		n_gauss = gsl_ran_gaussian(mt, sigma);
		printf("%lf\t%lf\n", t, n_gauss);
		t = t+dt;
	}

	gsl_rng_free(mt);

	return 0;
}

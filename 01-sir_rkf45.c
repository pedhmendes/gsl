////////////////////////
///////////SIR//////////
////////COM RKF45///////
///////PEDRO MENDES/////
////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_odeiv2.h>

#define N 2093000000
#define beta 0.312500
#define gamma 0.062500

int sir_func(double t, const double y[], double f[], void *params);

int main(void)
{
	const int dim = 3; //numero de edos
	const double e_abs = 1.e-8; //erro absoluto
	const double e_rel = 1.e-10; //erro relativo
	int status; //status da resolucao
	double y[dim]; //solucao
	double pop; //populacao total
	
	double t, tt, tmax; //tempos
	double dt; //dt inicial

	gsl_odeiv2_system edo_sys; //sistema de edos
	edo_sys.function = sir_func; //eqs a resolver
	edo_sys.dimension = dim; //numero de eqs a resolver
	edo_sys.params = NULL; //parametros p/ func, no caso nenhum

	t = 0.0; //t_0
	tmax = 150.0; //t_f
	dt = 0.001; 

	y[0] = N-1; // ci dos S
	y[1] = 1.0; // ci dos I
	y[2] = 0.0; //ci dos R

	gsl_odeiv2_driver * drv = gsl_odeiv2_driver_alloc_y_new(&edo_sys, gsl_odeiv2_step_rkf45, dt, e_abs, e_rel); //iniciar odeiv

	while(tt <= tmax)
	{
		status = gsl_odeiv2_driver_apply(drv, &t, tt, y); //calculando

		if(status != GSL_SUCCESS) //checando status
		{
			printf("Erro: status = %d\n", status);

			break;
		}

		pop = 0.0;
		pop = y[0]+y[1]+y[2]; //calculando pop

		printf("%lf %lf %lf %lf %lf\n", t, y[0]/N, y[1]/N, y[2]/N, pop/N); //print 

		tt = tt + dt; //atualiza o tempo
	}
	
	gsl_odeiv2_driver_free(drv); //limpa o odeiv

	return 0;
}

int sir_func(double t, const double y[], double f[], void *params)
{
	f[0] = -(beta*y[0]*y[1])/N; //dS/dt
	f[1] = (beta*y[0]*y[1])/N - gamma*y[1]; //dI/dt
	f[2] = gamma*y[1]; //dR/dt

	return GSL_SUCCESS;
}

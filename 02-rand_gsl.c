//////////////////////
//////////RNG/////////
/////PEDRO MENDES/////
//////////////////////

#include<stdio.h>
#include<time.h>
#include<gsl/gsl_rng.h>

int main()
{
	int t; //necessario pra iteracao
	int rand_int_1, rand_int_2, max_rand_int; //variaveis inteiras pro gerador
	double rand_double;//variavel double do gerador

	max_rand_int = 10000; //maximo valor int a gerar

	unsigned long int seed=0; //semente inicial, se for usar com semente alatoria apaga o '=0' e descomenta as duas linha abaixo
//	srand(time(NULL)); //deixar o rand rand
//	seed = rand(); //semente aleatorio

	gsl_rng *rr; //declara do gerador
	rr = gsl_rng_alloc(gsl_rng_mt19937); //escolhe o gerador e aloca a memoria, nesse caso uso o Mersenne Twister Generator
	gsl_rng_set(rr,seed); //inicializando o gerador

	printf("\nMersenne Twister RNG\n seed = %ld\n",seed); //estetica
	printf("  t int1 int2 double\n"); //estetica

	for(t=0; t<10; t++) 
	{ 
		rand_int_1 = gsl_rng_uniform_int(rr, max_rand_int); //numero aleatorio INTEIRO de 0 a max_rand_int - 1
			
		rand_int_2 = gsl_rng_uniform_int(rr,4); //numero aleatorio INTEIRO de zero a 4-1 {0,1,2,3}

		rand_double = gsl_rng_uniform(rr); //esse gerador gera numeros de tamanho DOUBLE entre 0 e 1 [0:1)

		printf("  %d %d %d %lf\n", t, rand_int_1, rand_int_2, rand_double); //printar pra ver os numeros gerados, cunho educacional
	}			

	gsl_rng_free(rr); //limpa a memoria alocada

	return 0;
}

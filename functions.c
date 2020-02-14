#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"
#include "mpi.h"

void global_sum(double*result, int rank, int size, double my_value){
	int i;
	int partner;//rank of partner
	int p = 1;//0001
	int phase = log(size)/log(2);
	my_value = rank;
	double p_value = partner;
MPI_Status status;

	for(i = 0; i<phase; i++){
	partner = rank ^ p;
	p = p*2;
	printf("Phase %d - P %d sendrecv with P %d val: %f\n",
			i, rank, partner,my_value);

	MPI_Sendrecv(&my_value,1,MPI_DOUBLE,partner,0,&p_value,1,MPI_DOUBLE,partner,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	my_value+=p_value;
	p_value += my_value;
	
}
	*result = my_value;
}

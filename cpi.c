#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"
#include "mpi.h"


int main(int argc, char *argv[])
{
    int rank, size,partner;
	int namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	double sum;
	double value;

	
	
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processor_name, &namelen);
	
	
	
	if(size & (size -1)!= 0){
	printf("invalid size");
		MPI_Finalize();
}
	else
{
	global_sum(&sum, rank, size, value);
	/**for(i = 0; i<phase; i++){
	partner = rank ^ p;
	p = p*2;
	printf("Phase %d - P %d sendrecv with P %d val: %f\n",
			i, rank, partner,my_value);

	MPI_Sendrecv(&my_value,1,MPI_DOUBLE,partner,0,&p_value,1,MPI_DOUBLE,partner,MPI_ANY_TAG,MPI_COMM_WORLD,&status);
	my_value+=p_value;
	p_value += my_value;}
 	*/

	printf("FINAL IN MAIN: Process: %d has Sum: %f\n", rank, sum);
	
}

    MPI_Finalize();
    return 0;
}

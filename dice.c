#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float Variance(int N,int* counter){
    /*
       Simulates N throws of a uniform fair dice.
       
       Input:
       -- N: integer, number of throws
       -- *counter: pointer to an integer value, assigned as a table

       Output:
       -- Variance calculated over all throws
    */

    int value;
    float expectation = 0, expectation_squared=0;
    for(int i=0;i<6;i++){

        counter[i]=0;
    } //initializing the counters to zero

    for(int i=0;i<N;i++){
            value = rand()%6; //throw
            counter[value]++;
            expectation += value+1;
            expectation_squared+=(value+1)*(value+1);

    }

    return expectation_squared/N - (expectation/N)*(expectation/N);


}


int main(){

int counter[6];
srand(time(NULL));
float variance;
int N;
float ksi;
float L = 17.5/6;       //convergence rate
int i;
float av;

    do{
	    printf("Dice throwing: N = number of dice rolls\n");
	    i = 0;
	    N = 100;
	    do{
		 variance=Variance(N,counter);
		 printf("\nVariance at N=%d = %f\nConvergence rate: %.20f",N,variance,fabs(variance - L)/L);
		 i++;
                 N = N*10;
	    }while(i<4);

            av = 0;
            for(int i=0;i<6;i++){

		av+=counter[i];
	    }
            av = av/6;

	    ksi = 0;
	    for(int i=0;i<6;i++){

		ksi+=fabs((counter[i]-av)*(counter[i]-av));
	    }
            ksi = sqrt(ksi/5);
	    printf("\nUniformity test result: %f\n",ksi);
    }while(getchar()==10);


return 0;
}

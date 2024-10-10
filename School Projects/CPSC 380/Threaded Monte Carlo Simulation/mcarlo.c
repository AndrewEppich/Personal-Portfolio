#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void *calc_monteCarlo(void *arg);
void *calc_result(void *arg);
double random_double();
// variables declared globally so they can be used in mutliple methods
double hit_count;
double mcResult;
double num_args;

int main(int argc, char **argv)
{

    int monteCarlo;
    // variables for thread ID
    pthread_t mc_tid;
    pthread_t result_tid;
    //converts the argv to a number
    num_args = atoi(argv[1]);

    
    if (argc > 2)
    {
        printf("Too many arguements entered \n");
    }
    else
    {
        // creates the thread to find the number of hits in the circle
        monteCarlo = pthread_create(&mc_tid, NULL, calc_monteCarlo, NULL);

        if (monteCarlo != 0)
        {
            perror("Error createing result thread \n");
            return -1;
        }
        // joins the thread after completion before creating the thread to calculate pi so the amount of hits is found before
        pthread_join(mc_tid, NULL);

        int result;
        pthread_t rand_tid;
        // creates the thread for the method that calculates the results
        result = pthread_create(&result_tid, NULL, calc_result, NULL);

        if (result != 0)
        {
            perror("Error creating random number thread thread \n");
            return -1;
        }

        pthread_join(result_tid, NULL);
        // prints the results
        printf("The result is %f \n", mcResult);
    }
}
// creates a random double between 1 and -1
double random_double()
{
    return (random() / ((double)RAND_MAX + 1));
}

//calculates the number of points that are located within the radius of the circle then exits the thread
void *calc_monteCarlo(void *arg)
{

    for (int i = 0; i < num_args; i++)
    {
        double x = random_double() * 2.0 - 1.0;
        double y = random_double() * 2.0 - 1.0;
        if (sqrt(x * x + y * y) < 1.0)
        {
            ++hit_count;
        }
    }
    if (hit_count == 0)
    {
        printf("Number of arguements is zero, Either no points or too many points %f \n", num_args);
    }
    pthread_exit(0);
}
// caclulates the result with the formula given then exits the thread
void *calc_result(void *arg)
{
    mcResult = (4.00 * (hit_count / num_args));
    if (mcResult == 0)
    {
        printf("No result returned, Either no points or too many points \n");
    }
    pthread_exit(0);
}
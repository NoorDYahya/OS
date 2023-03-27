//
// Created by noor dar yahya on 28/03/2023.
//
#include "osm.h"
#include <iostream>
#include <sys/time.h>

#define SECOND_TO_NANO  1000000000
#define MICRO_TO_NANO  1000
#define ITER 1000

/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */

double osm_operation_time(unsigned int iterations) {
    struct timeval start , end;

    int sum = 0;

    if (iterations == 0) {
        return -1;
    }
    if(gettimeofday(&start, NULL) == -1 ){
        return -1;
    }
    long time;
    //unrolling loop
    for (int i = 0; i < iterations; i++){

        sum+i;
        sum+i;
        sum+i;
        sum+i;
        sum+i;
        sum+i;
        sum+i;
        sum+i;
        sum+i;
        sum+i;


        if(gettimeofday(&end, NULL) == -1 ){
            return -1;
        }
        time+= (end.tv_sec * SECOND_TO_NANO + end.tv_usec*MICRO_TO_NANO) -
               (start.tv_sec * SECOND_TO_NANO + start.tv_usec*MICRO_TO_NANO);
        time/=10;

    }



    return (double) time / iterations;



}

void empty_function() {
}

/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations) {
    struct timeval start , end;

    int sum = 0;

    if (iterations == 0) {
        return -1;
    }
    if(gettimeofday(&start, NULL) == -1 ){
        return -1;
    }
    long time;
    //unrolling loop
    for (int i = 0; i < iterations; i++){

        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();
        empty_function();


        if(gettimeofday(&end, NULL) == -1 ){
            return -1;
        }
        time+= (end.tv_sec * SECOND_TO_NANO + end.tv_usec*MICRO_TO_NANO) -
               (start.tv_sec * SECOND_TO_NANO + start.tv_usec*MICRO_TO_NANO);
        time/=12;

    }
    
    return (double) time / iterations;

}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations)
{
    struct timeval start , end;

    int sum = 0;

    if (iterations == 0) {
        return -1;
    }
    if(gettimeofday(&start, NULL) == -1 ){
        return -1;
    }
    long time = 0;
    //unrolling loop
    for (int i = 0; i < iterations; i++){

        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;
        OSM_NULLSYSCALL;

        if(gettimeofday(&end, NULL) == -1 ){
            return -1;
        }
        time+= (end.tv_sec * SECOND_TO_NANO + end.tv_usec*MICRO_TO_NANO) -
               (start.tv_sec * SECOND_TO_NANO + start.tv_usec*MICRO_TO_NANO);
        time/=12;

    }



    return (double) time / iterations;
}
int main(){
    double add_time = osm_operation_time(ITER);
    std::cout << "Time measurement function for a simple arithmetic operation"
                 " is: "<< add_time << std::endl;
    double function_time = osm_function_time(ITER);
    std::cout << "Time measurement function for an empty function call is: "
              << function_time << std::endl;
    double trap_time = osm_syscall_time(ITER);
    std::cout << "Time measurement function for an empty trap into the "
                 "operating system is: "
              << trap_time << std::endl;
    return 0;
}





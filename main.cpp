#include <omp.h>
#include <stdio.h>
#include "population.h"



int main() {
    #pragma omp parallel
    printf("Hello, world! This is thread %d of %d\n", omp_get_thread_num(), omp_get_num_threads());
    Population testpop;
    testpop.setup_example();
    testpop.run();
}


/**
 * @file prob_set_3.3.c
 * @brief Solution for Problem 3.3: Geometric random variable sampling and factorial computation
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/*
 * @brief Generates a random double in the range [0, 1) and samples a geometric random variable based on a given probability p.
 * The function `rand_double` generates a random double using the standard `rand()` function and normalizes it to the range [0, 1).
 * @return A random double in the range [0, 1).
 *
 */
double rand_double(void)
{
    /**generate random number in [0 ,1) */
    double ret = (double)rand();
    return ret / (RAND_MAX + 1);
}
/**
 * @brief Samples a geometric random variable based on a given probability p.
 * The function `sample_geometric_rv` uses a loop to generate random doubles and counts
 * the number of trials until a random double is less than the specified probability p.
 * @param p The probability threshold for the geometric random variable.
 * @return The number of trials needed to get a random double less than p.
 *
 */
int sample_geometric_rv(double p)
{
    double q;
    int n = 0;
    bool start = true;
    while (start)
    {
        q = rand_double();
        n++;
        if (q < p)
            start = false;
    }
    return n;
}

/**
 * @brief Computes the factorial of a given integer n using an iterative approach.
 * @param n The integer for which to compute the factorial.
 * @return The factorial of n.
 */
int factorial_v(int n)
{
    int i = 1;
    int ret = 1;
    while (i <= n)
    {
        ret *= i;
        ++i;
    }
    return ret;
}

int main(void)
{
    int result_1 = factorial_v(4);
    printf("Answer for factorial function is %d \n", result_1);
    int sample_geometric_result = sample_geometric_rv(0.2);
    printf("Answer for the Sample Geometric function is %d \n", sample_geometric_result);
    return EXIT_SUCCESS;
}

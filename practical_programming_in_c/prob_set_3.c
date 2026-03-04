/***
 * @file prob_set_3.c
 * @brief Solution for Problem 3.1: Fibonacci sequence and register variables.
 *
 * This file implements a performance test to compare the execution time of
 * calculating the Fibonacci sequence using standard variables versus variables
 * declared with the 'register' keyword. It includes a profiler to measure
 * CPU time.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NMAX 25
static unsigned int results_buffer[NMAX];

/**
 * @brief Computes the Fibonacci sequence up to NMAX terms and stores results in a buffer.
 * This function uses standard unsigned integers for the Fibonacci calculation.
 * The results are stored in a global buffer for later retrieval.
 */
void fibonacci()
{
	/* here are the variables to set as registers */
	unsigned int a = 0;
	unsigned int b = 1;
	unsigned int c;
	int n;

	results_buffer[0] = a;
	results_buffer[1] = b;
	for (n = 2; n < NMAX; n++)
	{
		c = a + b;
		results_buffer[n] = c; /* store code in results buffer */
		a = b;
		b = c;
	}
}

/***
 * @brief Computes the Fibonacci sequence up to NMAX terms using register variables for optimization.
 * This function is similar to the standard Fibonacci calculation but uses the 'register' keyword
 * to suggest that the variables should be stored in CPU registers for faster access.
 *
 */
void fibonacci_register()
{
	/* here are the variables to set as registers */
	register unsigned int a = 0;
	register unsigned int b = 1;
	register unsigned int c;
	int n;
	// register int n;

	results_buffer[0] = a;
	results_buffer[1] = b;
	for (n = 2; n < NMAX; n++)
	{
		c = a + b;
		results_buffer[n] = c; /* store code in results buffer */
		a = b;
		b = c;
	}
}

/**
 * @brief Profiles the execution time of a given Fibonacci function.
 * This function takes a pointer to a Fibonacci function, executes it a specified number of times,
 * and measures the average execution time in milliseconds. It uses the clock() function to measure CPU time.
 * The results are printed to the console for analysis.
 * @param fibonacci_func A pointer to the Fibonacci function to be profiled.
 * @return Returns 0 upon successful completion of profiling.
 *
 */
int func_profiler(void (*fibonacci_func)(void))
{
	int n, ntests = 10000000;
	clock_t tstart, tend;
	double avg_time;

	/* do profiling */
	tstart = clock();

	for (n = 0; n < ntests; n++)
		fibonacci_func();

	tend = clock();
	/* end profiling */

	/* compute average execution time */
	avg_time = ((double)(tend - tstart)) / CLOCKS_PER_SEC / ntests;

	/* print avg execution time in milliseconds */
	printf("Avg. execution time: %g msec\n", avg_time * 1000);
	return 0;
}

/***
 * My observations for Problem Set 3.1:
 * 1. Without using the 'register' keyword, the average execution time for the standard Fibonacci function was approximately 6.43 milliseconds.
 * 2. When using the 'register' keyword for the Fibonacci function, the average execution time was sometimes slightly reduced to around 6.3 milliseconds. 
 * And sometimes it was slightly increased to around 6.5 -6.8 milliseconds. 
 * The results were inconsistent across multiple runs, indicating that the 'register' keyword does not guarantee a performance improvement 
 * and may depend on the compiler's optimization decisions and the specific architecture of the CPU.
 */

int main(void)
{
	// Profile the standard Fibonacci function
	func_profiler(fibonacci);

	// Profile the Fibonacci function that uses register variables
	func_profiler(fibonacci_register);

	return EXIT_SUCCESS;
}
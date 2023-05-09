// Linux sample program to measure elapsed time
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	struct timespec tp1,tp2 ;
	int i ;
	long t_diff ;

	// clock_gettime has many options, CLOCK_MONOTONIC seems to be safest
	clock_gettime(CLOCK_MONOTONIC_RAW, &tp1) ;
	for (i=0; i<5000; i++) usleep(1000) ;  // wait 1ms*5000=5s
	clock_gettime(CLOCK_MONOTONIC_RAW, &tp2) ;

	printf("%lu, %lu\n",tp1.tv_sec, tp1.tv_nsec) ;
	printf("%lu, %lu\n",tp2.tv_sec, tp2.tv_nsec) ;

	t_diff = ((tp2.tv_sec-tp1.tv_sec)*(1000*1000*1000) + (tp2.tv_nsec-tp1.tv_nsec)) / 1000 ;
	printf("%lu usec passed\n",t_diff) ;
	return 0 ;
}

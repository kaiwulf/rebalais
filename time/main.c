#include <time.h>
#include <stdio.h>
#include <unistd.h>

#define LF11 .11
#define TWENTY_MIL 20000000

int main()
{

  struct timespec bf_time, af_time;
  /* get beginning clock time */
  clock_gettime(CLOCK_REALTIME, &bf_time);
  double bft = (double) bf_time.tv_nsec*10e-11;
  double new_bft = bf_time.tv_sec + bft;
  printf("the time in double is %LF11f\n", new_bft);

  /* print the seconds and ns independently */
  printf("%lld is the seconds\n", bf_time.tv_sec);
  printf("%.11ld are the nanoseconds\n", bf_time.tv_nsec);
  printf("%lld.%.11ld seconds elapsed\n\n", bf_time.tv_sec, bf_time.tv_nsec);

  struct timespec sleepy;
  sleepy.tv_sec = 0;
  sleepy.tv_nsec = TWENTY_MIL;
  nanosleep(&sleepy, NULL);
  sleep(5);

  /* get the second clock time */
  clock_gettime(CLOCK_REALTIME, &af_time);
  double new_aft = af_time.tv_sec + (double) af_time.tv_nsec*10e-11;
  printf("the time in double is %.11f\n", new_aft);

  /* print the seconds and ns independently */
  printf("%11d is the seconds\n", af_time.tv_sec);
  printf("%.11ld are the nanoseconds\n", bf_time.tv_nsec);
  printf("%lld.%.11ld seconds elasped\n\n", (long long) af_time.tv_sec, af_time.tv_nsec);

  double elapsed = new_aft - new_bft;
  printf("%.11f time elapsed\n", elapsed);
  return 0;
}

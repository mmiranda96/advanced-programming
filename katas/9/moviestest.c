#include <stdio.h>
#include "minunit.h"
#include "movies.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testHappyPathTrue() {
  int flightLength = 180;
  int movieLengths[5] = {100, 40, 200, 80, 95};
  int movieCount = 5;
  muAssert("error, movies 0 and 4 match", checkMovies(flightLength, movieLengths, movieCount));
  return 0;
}

static char *testHappyPathFalse()
{
  int flightLength = 180;
  int movieLengths[5] = {30, 40, 200, 80, 95};
  int movieCount = 5;
  muAssert("error, no movies match", !checkMovies(flightLength, movieLengths, movieCount));
  return 0;
}

static char *testAllEqualTrue()
{
  int flightLength = 200;
  int movieLengths[5] = {100, 100, 100, 100, 100};
  int movieCount = 5;
  muAssert("error, movies 0 and 1 match", checkMovies(flightLength, movieLengths, movieCount));
  return 0;
}

static char *testAllEqualFalse()
{
  int flightLength = 200;
  int movieLengths[5] = {90, 90, 90, 90, 90};
  int movieCount = 5;
  muAssert("error, no movies match", !checkMovies(flightLength, movieLengths, movieCount));
  return 0;
}

static char *testOnlyComplementItself()
{
  int flightLength = 180;
  int movieLengths[5] = {90, 100, 110, 120, 130};
  int movieCount = 5;
  muAssert("error, no movies match", !checkMovies(flightLength, movieLengths, movieCount));
  return 0;
}

static char *testTwoMatches()
{
  int flightLength = 120;
  int movieLengths[5] = {70, 60, 60, 50, 100};
  int movieCount = 5;
  muAssert("error, movies 0 and 3 match", checkMovies(flightLength, movieLengths, movieCount));
  return 0;
}

static char * allTests() {
  muRunTest(testHappyPathTrue);
  muRunTest(testHappyPathFalse);
  muRunTest(testAllEqualTrue);
  muRunTest(testAllEqualFalse);
  muRunTest(testOnlyComplementItself);
  muRunTest(testTwoMatches);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}

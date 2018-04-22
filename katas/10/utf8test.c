#include <stdio.h>
#include "minunit.h"
#include "utf8.h"

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

static char * testHappyPathOne()
{
  unsigned char code[1] = {127};
  int len = 1;
  muAssert("error, [127] is valid", isValid(code, len));
  return 0;
}

static char * testHappyPathTwo()
{
  unsigned char code[2] = {193, 130};
  int len = 2;
  muAssert("error, [193, 130] is valid", isValid(code, len));
  return 0;
}

static char * testHappyPathThree()
{
  unsigned char code[3] = {226, 130, 187};
  int len = 3;
  muAssert("error, [226, 130, 187] is valid", isValid(code, len));
  return 0;
}

static char * testHappyPathFour()
{
  unsigned char code[4] = {241, 140, 141, 142};
  int len = 4;
  muAssert("error, [241, 140, 141, 142] is valid", isValid(code, len));
  return 0;
}

static char * testHappyPathLongChain()
{
  unsigned char code[3] = {197, 130, 1};
  int len = 3;
  muAssert("error, [197, 130, 1] is valid", isValid(code, len));
  return 0;
}

static char * testHappyPathLongerChain()
{
  unsigned char code[10] = {1, 193, 130, 225, 131, 132, 241, 150, 152, 151};
  int len = 10;
  muAssert("error, [1, 193, 130, 225, 131, 132, 241, 150, 152, 151] is valid", isValid(code, len));
  return 0;
}

static char * testFirstBitOne()
{
  unsigned char code[1] = {129};
  int len = 1;
  muAssert("error, [129] is not valid", !isValid(code, len));
  return 0;
}

static char * testOneAndMoreChars()
{
  unsigned char code[2] = {89, 150};
  int len = 2;
  muAssert("error, [89, 150] is not valid", !isValid(code, len));
  return 0;
}

static char * testTwoAndMoreChars()
{
  unsigned char code[3] = {216, 150, 151};
  int len = 3;
  muAssert("error, [216, 150] is not valid", !isValid(code, len));
  return 0;
}

static char * testThreeAndMoreChars()
{
  unsigned char code[4] = {236, 189, 190, 191};
  int len = 4;
  muAssert("error, [236, 189, 190, 191] is not valid", !isValid(code, len));
  return 0;
}

static char * testFollowingCharsBadMasks()
{
  unsigned char code[3] = {228, 150, 15};
  int len = 3;
  muAssert("error, [228, 150, 15] is not valid", !isValid(code, len));
  return 0;
}

static char * testMissingFollowingCharsEnd()
{
  unsigned char code[2] = {235, 140};
  int len = 2;
  muAssert("error, [235, 140] is not valid", !isValid(code, len));
  return 0;
}

static char * testMissingFollowingCharsIntermediate()
{
  unsigned char code[3] = {235, 140, 4};
  int len = 3;
  muAssert("error, [235, 140, 4] is not valid", !isValid(code, len));
  return 0;
}

static char * testMissingFollowingCharsIntermediateTwo()
{
  unsigned char code[5] = {235, 140, 4, 194, 167};
  int len = 5;
  muAssert("error, [235, 140, 4, 194, 167] is not valid", !isValid(code, len));
  return 0;
}



static char * allTests()
{
  muRunTest(testHappyPathOne);
  muRunTest(testHappyPathTwo);
  muRunTest(testHappyPathThree);
  muRunTest(testHappyPathFour);
  muRunTest(testHappyPathLongChain);
  muRunTest(testHappyPathLongerChain);
  
  muRunTest(testFirstBitOne);
  muRunTest(testOneAndMoreChars);
  muRunTest(testTwoAndMoreChars);
  muRunTest(testThreeAndMoreChars);
  muRunTest(testFollowingCharsBadMasks);
  muRunTest(testMissingFollowingCharsEnd);
  muRunTest(testMissingFollowingCharsIntermediate);
  muRunTest(testMissingFollowingCharsIntermediateTwo);
  return 0;
}

int main(int argc, char **argv)
{
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

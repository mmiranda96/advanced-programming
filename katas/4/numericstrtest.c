#include <stdio.h>
#include "minunit.h"
#include "numericstr.h"

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

static char * testInteger() {
  muAssert("error, 123 is a number", isNumeric("123"));
  return 0;
}

static char * testDecimal() {
  muAssert("error, 12.3 is a number", isNumeric("12.3"));
  return 0;
}

static char * testDecimalWithoutDecimals() {
  muAssert("error, 12. is a number", isNumeric("12."));
  return 0;
}

static char * testDecimalWithoutInteger() {
  muAssert("error, .12 is a number", isNumeric(".12"));
  return 0;
}

static char * testIntegerExponential() {
  muAssert("error, 12e34 is a number", isNumeric("12e34"));
  return 0;
}

static char * testDecimalExponential() {
  muAssert("error, 12.34e56 is a number", isNumeric("12.34e56"));
  return 0;
}

static char *testDecimalExponentialWithoutInteger() {
  muAssert("error, .12e34 is a number", isNumeric(".12e34"));
  return 0;
}

static char *testIntegerCommas() {
  muAssert("error, 1,234 is a number", isNumeric("1,234"));
  return 0;
}

static char *testIntegerMultipleCommas() {
  muAssert("error, 1,234,567,890 is a number", isNumeric("1,234,567,890"));
  return 0;
}

static char *testIntegerCommasExponent() {
  muAssert("error, 12,345e6 is a number", isNumeric("12,345e6"));
  return 0;
}

static char *testDecimalCommasExponent() {
  muAssert("error, 12,345.67e8 is a number", isNumeric("12,345.67e8"));
  return 0;
}

static char *testPrecedingSpaces() {
  muAssert("error, \"   123\" is a number", isNumeric("   123"));
  return 0;
}

static char *testSuccedingSpaces() {
  muAssert("error, \"123   \" is a number", isNumeric("123   "));
  return 0;
}

static char *emptyString() {
  muAssert("error, [empty string] is not a number", !isNumeric(""));
  return 0;
}

static char *testOnlySpaces() {
  muAssert("error, \"     \" is not a number", !isNumeric("     "));
  return 0;
}

static char *testMiddleSpaces() {
  muAssert("error, \"12 34\" is not a number", !isNumeric("12 34"));
  return 0;
}

static char *invalidChar() {
  muAssert("error, 12^3 is not a number", !isNumeric("12^3"));
  return 0;
}

static char *multipleDots() {
  muAssert("error, 12.345.67 is not a number", !isNumeric("12.345.67"));
  return 0;
}

static char *multipleExponential() {
  muAssert("error, 12e345e67 is not a number", !isNumeric("12e345e67"));
  return 0;
}

static char *exponentialWithoutInteger() {
  muAssert("error, e12 is not a number", !isNumeric("e12"));
  return 0;
}

static char *exponentialWithoutExponent() {
  muAssert("error, 12e is not a number", !isNumeric("12e"));
  return 0;
}

static char *invalidCommasConfiguration() {
  muAssert("error, 1,23,456 is not a number", !isNumeric("1,23,456"));
  return 0;
}

static char *decimalExponent() {
  muAssert("error, 12e3.456 is not a number", !isNumeric("12e3.456"));
  return 0;
}

static char *exponentWithCommas() {
  muAssert("error, 12e3,456 is not a number", !isNumeric("12e3,456"));
  return 0;
}

static char * allTests() {
  // Happy paths
  muRunTest(testInteger);
  muRunTest(testDecimal);
  muRunTest(testDecimalWithoutDecimals);
  muRunTest(testDecimalWithoutInteger);
  muRunTest(testIntegerExponential);
  muRunTest(testDecimalExponential);
  muRunTest(testDecimalExponentialWithoutInteger);
  muRunTest(testIntegerCommas);
  muRunTest(testIntegerMultipleCommas);
  muRunTest(testIntegerCommasExponent);
  muRunTest(testDecimalCommasExponent);
  muRunTest(testPrecedingSpaces);
  muRunTest(testSuccedingSpaces);

  // Failures
  muRunTest(emptyString);
  muRunTest(testOnlySpaces);
  muRunTest(testMiddleSpaces);
  muRunTest(invalidChar);
  muRunTest(multipleDots);
  muRunTest(multipleExponential);
  muRunTest(exponentialWithoutInteger);
  muRunTest(exponentialWithoutExponent);
  muRunTest(invalidCommasConfiguration);
  muRunTest(decimalExponent);
  muRunTest(exponentWithCommas);

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

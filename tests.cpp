#define BOOST_TEST_MODULE funcs_tests

#include "version.h"
#include "funcs.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(funcs_tests)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
  BOOST_CHECK(version() > 0);
}

BOOST_AUTO_TEST_CASE(test_factorial)
{
  BOOST_CHECK_EQUAL(factorial(0), 1);
  BOOST_CHECK_EQUAL(factorial(1), 1);
  BOOST_CHECK_EQUAL(factorial(2), 2);
  BOOST_CHECK_EQUAL(factorial(3), 6);
  BOOST_CHECK_EQUAL(factorial(4), 24);
  BOOST_CHECK_EQUAL(factorial(5), 120);
  BOOST_CHECK_EQUAL(factorial(6), 720);
  BOOST_CHECK_EQUAL(factorial(7), 5040);
  BOOST_CHECK_EQUAL(factorial(8), 40320);
  BOOST_CHECK_EQUAL(factorial(9), 362880);
  BOOST_CHECK_EQUAL(factorial(10), 3628800);
  BOOST_CHECK_EQUAL(factorial(11), 39916800);
  BOOST_CHECK_EQUAL(factorial(12), 479001600);
  BOOST_CHECK_EQUAL(factorial(13), 6227020800);
  BOOST_CHECK_EQUAL(factorial(14), 87178291200);
  BOOST_CHECK_EQUAL(factorial(15), 1307674368000);
}

BOOST_AUTO_TEST_SUITE_END()

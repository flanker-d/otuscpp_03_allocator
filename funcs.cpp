#include "funcs.h"

int version()
{
  return PROJECT_VERSION_PATCH;
}

std::int64_t factorial(std::int64_t n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

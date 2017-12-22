#include "custom_allocator.h"
#include "funcs.h"
#include <map>

using compare_type = std::common_type<int, std::int64_t>::type;
using custom_map = std::map<int, std::int64_t, std::less<compare_type>, custom_allocator<std::pair<int, std::int64_t>>>;

int main(int argc, char **argv)
{
  custom_map ma;

  for (int i = 0; i < 10; i++)
  {
    ma.insert(std::make_pair(i, factorial(i)));
  }

  for(const auto& it : ma)
  {
    std::cout<< it.first << " " << it.second << std::endl;
  }
  return 0;
}

#include "custom_allocator.h"
#include "funcs.h"
#include <map>
#include <vector>

using compare_type = std::common_type<int, std::int64_t>::type;
using custom_map = std::map<int, std::int64_t, std::less<compare_type>, custom_allocator<std::pair<int, std::int64_t>>>;

int main(int argc, char **argv)
{
  //  std::vector<int, custom_allocator<int>> v;
  //  v.reserve(5);
  //  for (int i = 0; i < 5; i++)
  //  {
  //    v.emplace_back(i);
  //  }

  //  for(const auto& it : v)
  //  {
  //    std::cout << it << std::endl;
  //  }

  custom_map m;

  for (int i = 0; i < 10; i++)
  {
    m.insert(std::make_pair(i, factorial(i)));
  }


  for(const auto& it : m)
  {
    std::cout<< it.first << " " << it.second << std::endl;
  }

  std::cout << std::endl;
  m.insert(std::make_pair(10, factorial(10)));
  for(const auto& it : m)
  {
    std::cout<< it.first << " " << it.second << std::endl;
  }
  return 0;
}

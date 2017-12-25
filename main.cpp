#include "custom_allocator.h"
#include "funcs.h"
#include <map>
#include "custom_container.h"

using compare_type = std::common_type<int, std::int64_t>::type;
using custom_map = std::map<int, std::int64_t, std::less<compare_type>, custom_allocator<std::pair<int, std::int64_t>>>;

int main(int argc, char **argv)
{
  // map
  std::map<int, std::int64_t> m;
  for (int i = 0; i < 10; i++)
  {
    m.insert(std::make_pair(i, factorial(i)));
  }

  //custom map
  custom_map cm;
  for (int i = 0; i < 10; i++)
  {
    cm.insert(std::make_pair(i, factorial(i)));
  }
  //cm.insert(std::make_pair(10, factorial(10)));

  for(const auto& it : cm)
  {
    std::cout<< it.first << " " << it.second << std::endl;
  }


  custom_container<int> c;
  for(int i = 0; i < 10; i++)
    c.push_back(i);

  custom_container<int, custom_allocator<element<int>>> cc;
  for(int i = 0; i < 10; i++)
    cc.push_back(i);

  for(const auto& it : cc)
  {
    std::cout << it.data << std::endl;
  }

  return 0;
}

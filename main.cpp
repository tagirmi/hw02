#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "filter.h"
#include "split.h"

namespace {

void print(const ip_pool_t& ip_pool)
{
  for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip) {
    for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part) {
      if (ip_part != ip->cbegin()) {
        std::cout << ".";
      }
      std::cout << static_cast<int>(*ip_part);
    }
    std::cout << std::endl;
  }
}

auto to_uint8(int value)
{
  assert(value >= 0 && value < 256);
  return static_cast<uint8_t>(value);
}

auto to_uint8(const std::string& str)
{
  return to_uint8(std::stoi(str));
}

ip_t to_ip(const std::vector<std::string>& strings)
{
  assert(strings.size() == 4);

  return {to_uint8(strings[0]),
        to_uint8(strings[1]),
        to_uint8(strings[2]),
        to_uint8(strings[3])};
}

}

int main(int argc, char const *argv[])
{
  try
  {
    ip_pool_t ip_pool;

    for(std::string line; std::getline(std::cin, line);) {
      std::vector<std::string> v = split(line, '\t');
      ip_pool.emplace_back(to_ip(split(v.at(0), '.')));
    }

    reverse_lexicographically_sort(ip_pool);
    print(ip_pool);

    print(filter(ip_pool, 1));

    print(filter(ip_pool, 46, 70));

    print(filter_any(ip_pool, 46));
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

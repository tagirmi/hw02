#include "filter.h"

#include <algorithm>

namespace {

template<typename P>
ip_pool_t filter(const ip_pool_t& ip_pool, P pred)
{
  ip_pool_t result(ip_pool.size());

  auto end = std::copy_if(ip_pool.cbegin(), ip_pool.cend(), result.begin(), pred);
  result.resize(std::distance(result.begin(), end));

  return result;
}

}

void reverse_lexicographically_sort(ip_pool_t& ip_pool)
{
  std::sort(ip_pool.begin(), ip_pool.end(), [] (const auto& a, const auto& b) {
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
  });
  std::reverse(ip_pool.begin(), ip_pool.end());
}

ip_pool_t filter(const ip_pool_t& ip_pool, int firstByte)
{
  return filter(ip_pool, [=] (const ip_t& ip) {
    return ip[0] == firstByte;
  });
}

ip_pool_t filter(const ip_pool_t& ip_pool, int firstByte, int secondByte)
{
  return filter(ip_pool, [=] (const ip_t& ip) {
    return ip[0] == firstByte && ip[1] == secondByte;
  });
}

ip_pool_t filter_any(const ip_pool_t& ip_pool, int anyByte)
{
  return filter(ip_pool, [=] (const ip_t& ip) {
    return std::any_of(ip.cbegin(), ip.cend(), [=] (const auto& byte) {
      return byte == anyByte;
    });
  });
}

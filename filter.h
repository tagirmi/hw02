#pragma once

#include <array>
#include <vector>
#include <string>

using ip_t = std::array<uint8_t, 4>;
using ip_pool_t = std::vector<ip_t>;

void reverse_lexicographically_sort(ip_pool_t&);

ip_pool_t filter(const ip_pool_t&, int);
ip_pool_t filter(const ip_pool_t&, int, int);
ip_pool_t filter_any(const ip_pool_t&, int);

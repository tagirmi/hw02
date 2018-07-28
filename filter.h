#pragma once

#include <string>
#include <vector>

using ip_pool_t = std::vector<std::vector<std::string> >;

void reverse_lexicographically_sort(ip_pool_t&);

ip_pool_t filter(const ip_pool_t&, int);
ip_pool_t filter(const ip_pool_t&, int, int);
ip_pool_t filter_any(const ip_pool_t&, int);

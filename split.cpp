#include "split.h"

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string& string, char delimiter)
{
  std::vector<std::string> result;

  std::string::size_type start = 0;
  std::string::size_type stop = string.find_first_of(delimiter);
  while(stop != std::string::npos) {
    result.push_back(string.substr(start, stop - start));

    start = stop + 1;
    stop = string.find_first_of(delimiter, start);
  }

  result.push_back(string.substr(start));

  return result;
}

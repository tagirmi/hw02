#include "split.h"

#include <sstream>

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string& string, char delimiter)
{
  std::vector<std::string> result;
  std::istringstream iss{string};
  std::string line;

  while (std::getline(iss, line, delimiter))
      result.emplace_back(line);
  if (line.empty())
      result.emplace_back(line);

  return result;
}

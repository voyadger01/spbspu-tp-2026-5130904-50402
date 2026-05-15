#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "utils.hpp"

int main()
{
  using T = karpovich::DataStruct;
  std::vector< T > data;
  using iit_t = std::istream_iterator< T >;
  std::copy(iit_t{std::cin}, iit_t{}, std::back_inserter(data));
  std::sort(data.begin(), data.end());
  using oit_t = std::ostream_iterator< T >;
  std::copy(data.begin(), data.end(), oit_t{std::cout, "\n"});
}

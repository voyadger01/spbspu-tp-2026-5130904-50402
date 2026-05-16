#ifndef DELIMITER_HPP
#define DELIMITER_HPP

#include <iostream>
namespace karpovich
{
  struct DelimIO
  {
    char exp;
  };
  std::istream &operator>>(std::istream &in, DelimIO &&dest);
}

#endif

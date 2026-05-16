#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iostream>
#include <vector>
namespace karpovich
{
  struct Point
  {
    int x, y;
  };
  struct Polygon
  {
    std::vector< Point > points;
  };

  std::istream &operator>>(std::istream &in, Point &point);
  std::istream &operator>>(std::istream &in, Polygon &polygon);
}

#endif
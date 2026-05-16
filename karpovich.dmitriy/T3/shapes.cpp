#include "shapes.hpp"
#include <algorithm>
#include <istream>
#include <iterator>
#include <vector>
#include "../common/delimiter.hpp"
#include "../common/ioguard.hpp"

std::istream &karpovich::operator>>(std::istream &in, Point &point)
{
  std::istream::sentry sentry(in);
  if (!sentry) {
    return in;
  }
  Point pt{0, 0};
  in >> DelimIO{'('} >> pt.x >> DelimIO{';'} >> pt.y >> DelimIO{')'};
  if (in) {
    point = pt;
  }
  return in;
}
std::istream &karpovich::operator>>(std::istream &in, Polygon &polygon)
{
  std::istream::sentry sentry(in);
  if (!sentry) {
    return in;
  }
  IOguard GOAAAAAAAAAAAAAAAAAL(in);
  size_t count = 0;
  if (!(in >> count) || count < 3) {
    in.setstate(std::ios::failbit);
    return in;
  }
  std::vector< Point > points;
  std::copy_n(std::istream_iterator< Point >(in), count, points.begin());
  if (in) {
    polygon.points = std::move(points);
  }
  return in;
}

#include "commands.hpp"
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>

namespace
{

  double getArea(const karpovich::Polygon &p)
  {
    return karpovich::calculateArea(p);
  }

  bool isEven(const karpovich::Polygon &p)
  {
    return p.points.size() % 2 == 0;
  }

  bool isOdd(const karpovich::Polygon &p)
  {
    return p.points.size() % 2 != 0;
  }

  bool hasVertexCount(const karpovich::Polygon &p, size_t n)
  {
    return p.points.size() == n;
  }

  bool isDigitChar(char c)
  {
    return std::isdigit(c);
  }

  bool isNumber(const std::string &s)
  {
    return !s.empty() && std::all_of(s.begin(), s.end(), isDigitChar);
  }

  bool areaLess(const karpovich::Polygon &a, const karpovich::Polygon &b)
  {
    return karpovich::calculateArea(a) < karpovich::calculateArea(b);
  }

  bool vertexLess(const karpovich::Polygon &a, const karpovich::Polygon &b)
  {
    return a.points.size() < b.points.size();
  }

  template < class Pred >
  void printFilteredSum(std::ostream &out, const std::vector< karpovich::Polygon > &polygons, Pred pred)
  {
    std::vector< karpovich::Polygon > filtered;
    std::copy_if(polygons.begin(), polygons.end(), std::back_inserter(filtered), pred);
    std::vector< double > areas;
    areas.reserve(filtered.size());
    std::transform(filtered.begin(), filtered.end(), std::back_inserter(areas), getArea);
    out << std::accumulate(areas.begin(), areas.end(), 0.0, std::plus< double >()) << "\n";
  }

  bool isSpaceChar(char c)
  {
    return std::isspace(c);
  }
}

void karpovich::area(std::istream &in, std::ostream &out, const std::vector< Polygon > &polygons)
{
  std::string param;
  if (!(in >> param)) {
    throw std::invalid_argument("");
  }

  out << std::fixed << std::setprecision(1);

  if (param == "MEAN") {
    if (polygons.empty()) {
      throw std::invalid_argument("");
    }
    std::vector< double > areas;
    areas.reserve(polygons.size());
    std::transform(polygons.begin(), polygons.end(), std::back_inserter(areas), getArea);
    double sum = std::accumulate(areas.begin(), areas.end(), 0.0, std::plus< double >());
    out << sum / polygons.size() << "\n";
  } else if (param == "EVEN") {
    printFilteredSum(out, polygons, isEven);
  } else if (param == "ODD") {
    printFilteredSum(out, polygons, isOdd);
  } else if (isNumber(param)) {
    size_t n = std::stoul(param);
    if (n < 3) {
      throw std::invalid_argument("");
    }
    printFilteredSum(out, polygons, std::bind(hasVertexCount, std::placeholders::_1, n));
  } else {
    throw std::invalid_argument("");
  }
}

void karpovich::max(std::istream &in, std::ostream &out, const std::vector< Polygon > &polygons)
{
  std::string param;
  if (!(in >> param)) {
    throw std::invalid_argument("");
  }
  if (polygons.empty()) {
    throw std::invalid_argument("");
  }

  if (param == "AREA") {
    auto it = std::max_element(polygons.begin(), polygons.end(), areaLess);
    out << std::fixed << std::setprecision(1) << karpovich::calculateArea(*it) << "\n";
  } else if (param == "VERTEXES") {
    auto it = std::max_element(polygons.begin(), polygons.end(), vertexLess);
    out << it->points.size() << "\n";
  } else {
    throw std::invalid_argument("");
  }
}

void karpovich::min(std::istream &in, std::ostream &out, const std::vector< Polygon > &polygons)
{
  std::string param;
  if (!(in >> param)) {
    throw std::invalid_argument("");
  }
  if (polygons.empty()) {
    throw std::invalid_argument("");
  }

  if (param == "AREA") {
    auto it = std::min_element(polygons.begin(), polygons.end(), areaLess);
    out << std::fixed << std::setprecision(1) << karpovich::calculateArea(*it) << "\n";
  } else if (param == "VERTEXES") {
    auto it = std::min_element(polygons.begin(), polygons.end(), vertexLess);
    out << it->points.size() << "\n";
  } else {
    throw std::invalid_argument("");
  }
}

void karpovich::count(std::istream &in, std::ostream &out, const std::vector< Polygon > &polygons)
{
  std::string param;
  if (!(in >> param)) {
    throw std::invalid_argument("");
  }

  if (param == "EVEN") {
    out << std::count_if(polygons.begin(), polygons.end(), isEven) << "\n";
  } else if (param == "ODD") {
    out << std::count_if(polygons.begin(), polygons.end(), isOdd) << "\n";
  } else if (isNumber(param)) {
    size_t n = std::stoul(param);
    if (n < 3) {
      throw std::invalid_argument("");
    }
    out << std::count_if(polygons.begin(), polygons.end(), std::bind(hasVertexCount, std::placeholders::_1, n)) << "\n";
  } else {
    throw std::invalid_argument("");
  }
}

void karpovich::rightshapes(std::istream &, std::ostream &out, const std::vector< Polygon > &polygons)
{
  out << std::count_if(polygons.begin(), polygons.end(), &karpovich::hasRightAngle) << "\n";
}

void karpovich::same(std::istream &in, std::ostream &out, const std::vector< Polygon > &polygons)
{
  Polygon target;
  if (!(in >> target)) {
    throw std::invalid_argument("");
  }
  std::string rest;
  std::getline(in, rest);
  if (!std::all_of(rest.begin(), rest.end(), isSpaceChar)) {
    throw std::invalid_argument("");
  }
  auto func = std::bind(&karpovich::isSame, std::placeholders::_1, std::cref(target));
  out << std::count_if(polygons.begin(), polygons.end(), func) << "\n";
}

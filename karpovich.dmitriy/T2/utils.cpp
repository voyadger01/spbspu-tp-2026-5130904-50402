#include "utils.hpp"

karpovich::IOguard::IOguard(std::basic_ios< char > &s):
  s_(s),
  width_(s.width()),
  precision_(s.precision()),
  fmt_(s.flags()),
  fill_(s.fill())
{}

std::istream &karpovich::operator>>(std::istream &in, DelimIO &&dest)
{
  return in;
}
std::istream &karpovich::operator>>(std::istream &in, LabelIO &&dest)
{
  return in;
}
std::istream &karpovich::operator>>(std::istream &in, BinIO &&dest)
{
  return in;
}
std::istream &karpovich::operator>>(std::istream &in, OctIO &&dest)
{
  return in;
}
std::istream &karpovich::operator>>(std::istream &in, StringIO &&dest)
{
  return in;
}

std::istream &karpovich::operator>>(std::istream &in, DataStruct &dest)
{
  return in;
}
std::ostream &karpovich::operator<<(std::ostream &out, const DataStruct &dest)
{
  return out;
}

bool karpovich::operator<(const DataStruct &lhs, const DataStruct &rhs)
{
  return false;
}

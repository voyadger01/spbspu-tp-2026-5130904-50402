#include "utils.hpp"
#include <iostream>

karpovich::IOguard::IOguard(std::basic_ios< char > &s):
  s_(s),
  width_(s.width()),
  precision_(s.precision()),
  fmt_(s.flags()),
  fill_(s.fill())
{}

karpovich::IOguard::~IOguard()
{
  s_.width(width_);
  s_.precision(precision_);
  s_.flags(fmt_);
  s_.fill(fill_);
}

std::istream &karpovich::operator>>(std::istream &in, DelimIO &&dest)
{
  std::istream::sentry sentry(in);
  if (!sentry) {
    return in;
  }
  char c = '\0';
  in >> c;
  if (in && c != dest.exp) {
    in.setstate(std::ios::failbit);
  }
  return in;
}

std::istream &karpovich::operator>>(std::istream &in, LabelIO &&dest)
{
  std::istream::sentry sentry(in);
  if (!sentry) {
    return in;
  }
  std::string label = "";
  in >> label;
  if (in && label != dest.exp) {
    in.setstate(std::ios::failbit);
  }
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
  if (lhs.key1 != rhs.key1) {
    return lhs.key1 < rhs.key1;
  }
  if (lhs.key2 != rhs.key2) {
    return lhs.key2 < rhs.key2;
  }
  return lhs.key3.length() < rhs.key3.length();
}

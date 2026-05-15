#include "utils.hpp"
#include <iomanip>
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
  std::istream::sentry sentry(in);
  if (!sentry) {
    return in;
  }

  IOguard guard(in);
  in >> DelimIO{'0'} >> std::oct >> dest.ref;
  return in;
}

std::istream &karpovich::operator>>(std::istream &in, StringIO &&dest)
{
  std::istream::sentry sentry(in);
  if (!sentry) {
    return in;
  }

  return in >> std::quoted(dest.ref);
}

std::istream &karpovich::operator>>(std::istream &in, DataStruct &dest)
{
  std::istream::sentry sentry(in);
  if (!sentry) {
    return in;
  }

  DataStruct temp;
  bool got1 = false;
  bool got2 = false;
  bool got3 = false;

  in >> DelimIO{'('};
  if (!in) {
    return in;
  }

  while ((!got1 || !got2 || !got3) && in) {
    std::string label;
    in >> label;

    if (label == ":key1" && !got1) {
      in >> BinIO{temp.key1};
      if (in) {
        got1 = true;
      }
    } else if (label == ":key2" && !got2) {
      in >> OctIO{temp.key2};
      if (in) {
        got2 = true;
      }
    } else if (label == ":key3" && !got3) {
      in >> StringIO{temp.key3};
      if (in) {
        got3 = true;
      }
    } else {
      in.setstate(std::ios::failbit);
    }
  }
  in >> DelimIO{':'} >> DelimIO{')'};
  if (in && got1 && got2 && got3) {
    dest = temp;
  } else {
    in.setstate(std::ios::failbit);
  }

  return in;
}

std::ostream &karpovich::operator<<(std::ostream &out, const DataStruct &src)
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

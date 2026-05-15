#ifndef UTILS_HPP
#define UTILS_HPP

#include <ios>
#include <string>
namespace karpovich
{
  struct DataStruct
  {
    unsigned long long key1;
    unsigned long long key2;
    std::string key3;
  };
  struct BinIO
  {
    unsigned long long &ref;
  };
  struct OctIO
  {
    unsigned long long &ref;
  };
  struct StringIO
  {
    std::string &ref;
  };
  struct DelimIO
  {
    char exp;
  };
  struct LabelIO
  {
    std::string exp;
  };
  class IOguard
  {
  public:
    explicit IOguard(std::basic_ios< char > &s);
    ~IOguard();

  private:
    std::basic_ios< char > &s_;
    std::streamsize width_;
    std::streamsize precision_;
    std::basic_ios< char >::fmtflags fmt_;
    char fill_;
  };
  std::istream &operator>>(std::istream &in, DelimIO &&dest);
  std::istream &operator>>(std::istream &in, LabelIO &&dest);
  std::istream &operator>>(std::istream &in, BinIO &&dest);
  std::istream &operator>>(std::istream &in, OctIO &&dest);
  std::istream &operator>>(std::istream &in, StringIO &&dest);

  std::istream &operator>>(std::istream &in, DataStruct &dest);
  std::ostream &operator<<(std::ostream &out, const DataStruct &src);

  bool operator<(const DataStruct &lhs, const DataStruct &rhs);
}

#endif

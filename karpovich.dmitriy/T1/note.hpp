#ifndef NOTE_HPP
#define NOTE_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
namespace karpovich
{
  class Note
  {
    using linksMap = std::unordered_map< std::string, std::weak_ptr< Note > >;

  public:
    Note(std::string name);

    void addLine(std::string line);
    void addLink(std::shared_ptr< Note > tolink);
    void haltLink(const std::string &targetName);
    void show(std::ostream &out) const;
    void mindLinks(std::ostream &out) const;
    void refresh();
    size_t countExpired() const;
    const std::string &getName() const;

  private:
    std::string name_;
    std::vector< std::string > lines_;
    linksMap links_;
    ;
  };
}
#endif

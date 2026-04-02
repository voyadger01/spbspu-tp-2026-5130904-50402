#include "note.hpp"
#include <cstddef>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

karpovich::Note::Note(std::string name):
  name_(name)
{}

void karpovich::Note::addLine(std::string line)
{
  lines_.push_back(line);
}

void karpovich::Note::addLink(std::shared_ptr< Note > tolink)
{
  if (links_.find(tolink->getName()) != links_.end()) {
    throw std::logic_error("Link already exists");
  }
  links_[tolink->getName()] = tolink;
}

void karpovich::Note::haltLink(const std::string &targetName)
{
  if (links_.find(targetName) == links_.end()) {
    throw std::logic_error("Link not found");
  }
  links_.erase(targetName);
}

void karpovich::Note::show(std::ostream &out) const
{
  for (std::size_t i = 0; i < lines_.size(); ++i) {
    out << lines_[i] << '\n';
  }
}

void karpovich::Note::mindLinks(std::ostream &out) const
{
  for (linksMap::const_iterator it = links_.begin(); it != links_.end(); ++it) {
    if (!it->second.expired()) {
      out << it->first << '\n';
    }
  }
}

void karpovich::Note::refresh()
{
  std::vector< std::string > toRemove;
  for (linksMap::const_iterator it = links_.begin(); it != links_.end(); ++it) {
    if (it->second.expired()) {
      toRemove.push_back(it->first);
    }
  }
  for (std::size_t i = 0; i < toRemove.size(); ++i) {
    links_.erase(toRemove[i]);
  }
}

size_t karpovich::Note::countExpired() const
{
  size_t count = 0;
  for (linksMap::const_iterator it = links_.begin(); it != links_.end(); ++it) {
    if (it->second.expired()) {
      ++count;
    }
  }
  return count;
}

const std::string &karpovich::Note::getName() const
{
  return name_;
}

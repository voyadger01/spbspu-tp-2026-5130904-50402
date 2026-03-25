#include "note.hpp"
#include <cstddef>
#include <memory>
#include <vector>

karpovich::Note::Note(std::string name):
  name_(name)
{}
void karpovich::Note::addLine(std::string line)
{
  lines_.push_back(line);
}
void karpovich::Note::addLink(std::shared_ptr< Note > tolink)
{
  for (std::size_t i = 0; i < links_.size(); ++i) {
    std::shared_ptr< Note > locked = links_[i].lock();
    if (locked && locked == tolink) {
      return;
    }
  }
  links_.push_back(tolink);
}
void karpovich::Note::haltLink(const std::string &targetName)
{
  for (std::vector< std::weak_ptr< Note > >::iterator it = links_.begin(); it != links_.end();) {
    std::shared_ptr< Note > sp = it->lock();
    if (sp && sp->getName() == targetName) {
      it = links_.erase(it);
    } else {
      ++it;
    }
  }
}
void karpovich::Note::show(std::ostream &out) const
{
  for (size_t i = 0; i < lines_.size(); i++) {
    out << lines_[i] << '\n';
  }
}
void karpovich::Note::mindLinks(std::ostream &out) const
{
  for (std::size_t i = 0; i < links_.size(); ++i) {
    std::shared_ptr< Note > locked = links_[i].lock();
    if (!locked) {
      continue;
    }
    out << locked->getName() << '\n';
  }
}
void karpovich::Note::refresh()
{
  for (std::vector< std::weak_ptr< Note > >::iterator it = links_.begin(); it != links_.end();) {
    std::shared_ptr< Note > sp = it->lock();
    if (!sp) {
      it = links_.erase(it);
    } else {
      ++it;
    }
  }
}
size_t karpovich::Note::countExpired() const
{
  size_t count = 0;
  for (std::vector< std::weak_ptr< Note > >::const_iterator it = links_.begin(); it != links_.end(); it++) {
    std::shared_ptr< Note > sp = it->lock();
    if (!sp) {
      count++;
    }
  }
  return count;
}
const std::string &karpovich::Note::getName() const
{
  return name_;
}

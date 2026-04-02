#include "note.hpp"
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
  for (size_t i = 0; i < links_.size(); ++i) {
    if (links_[i].first == tolink->getName()) {
      throw std::logic_error("Link already exists");
    }
  }
  links_.emplace_back(tolink->getName(), std::weak_ptr< Note >(tolink));
}

void karpovich::Note::haltLink(const std::string &targetName)
{
  for (size_t i = 0; i < links_.size(); ++i) {
    if (links_[i].first == targetName) {
      links_.erase(links_.begin() + i);
      return;
    }
  }
  throw std::logic_error("Link not found");
}

void karpovich::Note::show(std::ostream &out) const
{
  if (!lines_.size()) {
    out << '\n';
  }
  for (size_t i = 0; i < lines_.size(); ++i) {
    out << lines_[i] << '\n';
  }
}

void karpovich::Note::mindLinks(std::ostream &out) const
{
  bool printed = false;
  for (size_t i = 0; i < links_.size(); ++i) {
    if (!links_[i].second.expired()) {
      out << links_[i].first << '\n';
      printed = true;
    }
  }
  if (!printed) {
    out << '\n';
  }
}

void karpovich::Note::refresh()
{
  size_t write_idx = 0;
  for (size_t read_idx = 0; read_idx < links_.size(); ++read_idx) {
    if (!links_[read_idx].second.expired()) {
      if (write_idx != read_idx) {
        links_[write_idx] = links_[read_idx];
      }
      ++write_idx;
    }
  }
  links_.resize(write_idx);
}

size_t karpovich::Note::countExpired() const
{
  size_t count = 0;
  for (size_t i = 0; i < links_.size(); ++i) {
    if (links_[i].second.expired()) {
      ++count;
    }
  }
  return count;
}

const std::string &karpovich::Note::getName() const
{
  return name_;
}

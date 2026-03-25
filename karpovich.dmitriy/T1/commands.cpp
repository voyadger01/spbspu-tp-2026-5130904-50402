#include "commands.hpp"
#include <stdexcept>

void karpovich::cmdNote(NoteMap &notes, const std::string &name)
{
  if (name.empty()) {
    throw std::logic_error("Empty name");
  }
  notes[name] = std::make_shared< Note >(name);
}
void karpovich::cmdLine(NoteMap &notes, const std::string &name, const std::string &text)
{
  NoteMap::iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->addLine(text);
}
void karpovich::cmdShow(const NoteMap &notes, const std::string &name, std::ostream &out)
{
  NoteMap::const_iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->show(out);
}
void karpovich::cmdDrop(NoteMap &notes, const std::string &name)
{
  NoteMap::iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  notes.erase(it);
}
void karpovich::cmdLink(NoteMap &notes, const std::string &from_name, const std::string &to_name)
{
  NoteMap::iterator it_from = notes.find(from_name);
  NoteMap::iterator it_to = notes.find(to_name);
  if (it_from == notes.end() || it_to == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it_from->second->addLink(it_to->second);
}
void karpovich::cmdHalt(NoteMap &notes, const std::string &from_name, const std::string &to_name)
{
  NoteMap::iterator it_from = notes.find(from_name);
  if (it_from == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it_from->second->haltLink(to_name);
}
void karpovich::cmdMind(const NoteMap &notes, const std::string &name, std::ostream &out)
{
  NoteMap::const_iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->mindLinks(out);
}
void karpovich::cmdExpired(const NoteMap &notes, const std::string &name, std::ostream &out)
{
  NoteMap::const_iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  out << it->second->countExpired() << '\n';
}
void karpovich::cmdRefresh(NoteMap &notes, const std::string &name)
{
  NoteMap::iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->refresh();
}

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
void karpovich::cmdShow(const NoteMap &notes, const std::string &name)
{}
void karpovich::cmdDrop(NoteMap &notes, const std::string &name)
{}
void karpovich::cmdLink(NoteMap &notes, const std::string &from_name, const std::string &to_name)
{}
void karpovich::cmdHalt(NoteMap &notes, const std::string &from_name, const std::string &to_name)
{}
void karpovich::cmdMind(const NoteMap &notes, const std::string &name)
{}
void karpovich::cmdExpired(const NoteMap &notes, const std::string &name)
{}
void karpovich::cmdRefresh(NoteMap &notes, const std::string &name)
{}

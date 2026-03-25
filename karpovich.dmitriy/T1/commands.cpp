#include "commands.hpp"
#include <stdexcept>

void karpovich::cmd_note(NoteMap &notes, const std::string &name)
{
  if (name.empty()) {
    throw std::logic_error("Empty name");
  }
  notes[name] = std::make_shared< Note >(name);
}
void karpovich::cmd_line(NoteMap &notes, const std::string &name, const std::string &text)
{
  NoteMap::iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->addLine(text);
}
void karpovich::cmd_show(const NoteMap &notes, const std::string &name)
{}
void karpovich::cmd_drop(NoteMap &notes, const std::string &name)
{}
void karpovich::cmd_link(NoteMap &notes, const std::string &from_name, const std::string &to_name)
{}
void karpovich::cmd_halt(NoteMap &notes, const std::string &from_name, const std::string &to_name)
{}
void karpovich::cmd_mind(const NoteMap &notes, const std::string &name)
{}
void karpovich::cmd_expired(const NoteMap &notes, const std::string &name)
{}
void karpovich::cmd_refresh(NoteMap &notes, const std::string &name)
{}

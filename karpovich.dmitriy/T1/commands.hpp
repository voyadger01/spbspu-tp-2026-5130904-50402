#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include "note.hpp"

namespace karpovich
{
  using NoteMap = std::unordered_map<std::string, std::shared_ptr<Note>>;

  bool cmd_note(NoteMap& notes, const std::string& name);
  bool cmd_line(NoteMap& notes, const std::string& name, const std::string& text);
  bool cmd_show(const NoteMap& notes, const std::string& name);
  bool cmd_drop(NoteMap& notes, const std::string& name);
  bool cmd_link(NoteMap& notes, const std::string& from_name, const std::string& to_name);
  bool cmd_halt(NoteMap& notes, const std::string& from_name, const std::string& to_name);
  bool cmd_mind(const NoteMap& notes, const std::string& name);
  bool cmd_expired(const NoteMap& notes, const std::string& name);
  bool cmd_refresh(NoteMap& notes, const std::string& name);
}

#endif

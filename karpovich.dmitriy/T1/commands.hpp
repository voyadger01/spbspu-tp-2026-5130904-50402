#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include "note.hpp"

namespace karpovich
{
  using NoteMap = std::unordered_map< std::string, std::shared_ptr< Note > >;

  void cmdNote(NoteMap &notes, const std::string &name);
  void cmdLine(NoteMap &notes, const std::string &name, const std::string &text);
  void cmdShow(const NoteMap &notes, const std::string &name, std::ostream &out);
  void cmdDrop(NoteMap &notes, const std::string &name);
  void cmdLink(NoteMap &notes, const std::string &from_name, const std::string &to_name);
  void cmdHalt(NoteMap &notes, const std::string &from_name, const std::string &to_name);
  void cmdMind(const NoteMap &notes, const std::string &name, std::ostream &out);
  void cmdExpired(const NoteMap &notes, const std::string &name, std::ostream &out);
  void cmdRefresh(NoteMap &notes, const std::string &name);
}

#endif

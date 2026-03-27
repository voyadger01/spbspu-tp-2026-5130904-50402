#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <istream>
#include <ostream>
#include "note.hpp"

namespace karpovich
{
  using NoteMap = std::unordered_map< std::string, std::shared_ptr< Note > >;

  void cmdNote(std::istream &, std::ostream &, NoteMap &);
  void cmdLine(std::istream &, std::ostream &, NoteMap &);
  void cmdShow(std::istream &, std::ostream &, NoteMap &);
  void cmdDrop(std::istream &, std::ostream &, NoteMap &);
  void cmdLink(std::istream &, std::ostream &, NoteMap &);
  void cmdHalt(std::istream &, std::ostream &, NoteMap &);
  void cmdMind(std::istream &, std::ostream &, NoteMap &);
  void cmdExpired(std::istream &, std::ostream &, NoteMap &);
  void cmdRefresh(std::istream &, std::ostream &, NoteMap &);
}

#endif

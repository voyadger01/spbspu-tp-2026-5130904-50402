#ifndef WRAP_HPP
#define WRAP_HPP

#include "commands.hpp"
#include <istream>
#include <ostream>

namespace karpovich
{
  void wrapNote(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapLine(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapShow(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapDrop(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapLink(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapHalt(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapMind(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapExpired(std::istream &in, std::ostream &out, NoteMap &notes);
  void wrapRefresh(std::istream &in, std::ostream &out, NoteMap &notes);
}

#endif
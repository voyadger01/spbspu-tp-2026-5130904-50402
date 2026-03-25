#include "wrap.hpp"
#include <stdexcept>
#include <iomanip>
#include <string>

using namespace karpovich;

void karpovich::wrapNote(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  cmdNote(notes, name);
  (void)out;
}
void karpovich::wrapLine(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name, text;
  if (!(in >> name >> std::quoted(text))) {
    throw std::logic_error("Missing args");
  }
  cmdLine(notes, name, text);
  (void)out;
}
void karpovich::wrapShow(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  cmdShow(notes, name, out);
}
void karpovich::wrapDrop(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  cmdDrop(notes, name);
  (void)out;
}
void karpovich::wrapLink(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string from, to;
  if (!(in >> from >> to)) {
    throw std::logic_error("Missing args");
  }
  cmdLink(notes, from, to);
  (void)out;
}
void karpovich::wrapHalt(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string from, to;
  if (!(in >> from >> to)) {
    throw std::logic_error("Missing args");
  }
  cmdHalt(notes, from, to);
  (void)out;
}
void karpovich::wrapMind(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  cmdMind(notes, name, out);
}
void karpovich::wrapExpired(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  cmdExpired(notes, name, out);
}
void karpovich::wrapRefresh(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  cmdRefresh(notes, name);
  (void)out;
}

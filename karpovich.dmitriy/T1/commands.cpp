#include "commands.hpp"
#include <stdexcept>
#include <iomanip>
#include <string>

void karpovich::cmdNote(std::istream &in, std::ostream &, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  if (name.empty()) {
    throw std::logic_error("Empty name");
  }
  if (notes.find(name) != notes.end()) {
    throw std::logic_error("Note already exists");
  }
  notes[name] = std::make_shared< Note >(name);
}

void karpovich::cmdLine(std::istream &in, std::ostream &, NoteMap &notes)
{
  std::string name, text;
  if (!(in >> name >> std::quoted(text))) {
    throw std::logic_error("Missing args");
  }
  NoteMap::iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->addLine(text);
}

void karpovich::cmdShow(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  NoteMap::const_iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->show(out);
}

void karpovich::cmdDrop(std::istream &in, std::ostream &, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  NoteMap::iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  notes.erase(it);
}

void karpovich::cmdLink(std::istream &in, std::ostream &, NoteMap &notes)
{
  std::string from_name, to_name;
  if (!(in >> from_name >> to_name)) {
    throw std::logic_error("Missing args");
  }
  NoteMap::iterator it_from = notes.find(from_name);
  NoteMap::iterator it_to = notes.find(to_name);
  if (it_from == notes.end() || it_to == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it_from->second->addLink(it_to->second);
}

void karpovich::cmdHalt(std::istream &in, std::ostream &, NoteMap &notes)
{
  std::string from_name, to_name;
  if (!(in >> from_name >> to_name)) {
    throw std::logic_error("Missing args");
  }
  NoteMap::iterator it_from = notes.find(from_name);
  NoteMap::iterator it_to = notes.find(to_name);
  if (it_from == notes.end() || it_to == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it_from->second->haltLink(to_name);
}

void karpovich::cmdMind(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  NoteMap::const_iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->mindLinks(out);
}

void karpovich::cmdExpired(std::istream &in, std::ostream &out, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  NoteMap::const_iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  out << it->second->countExpired() << '\n';
}

void karpovich::cmdRefresh(std::istream &in, std::ostream &, NoteMap &notes)
{
  std::string name;
  if (!(in >> name)) {
    throw std::logic_error("Missing name");
  }
  NoteMap::iterator it = notes.find(name);
  if (it == notes.end()) {
    throw std::logic_error("Note not found");
  }
  it->second->refresh();
}

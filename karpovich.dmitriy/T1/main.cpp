#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
#include <stdexcept>
#include "commands.hpp"

int main()
{
  karpovich::NoteMap notes;
  using cmd_t = void (*)(std::istream &, std::ostream &, karpovich::NoteMap &);
  std::unordered_map< std::string, cmd_t > cmds;
  cmds["note"] = karpovich::cmdNote;
  cmds["line"] = karpovich::cmdLine;
  cmds["show"] = karpovich::cmdShow;
  cmds["drop"] = karpovich::cmdDrop;
  cmds["link"] = karpovich::cmdLink;
  cmds["halt"] = karpovich::cmdHalt;
  cmds["mind"] = karpovich::cmdMind;
  cmds["expired"] = karpovich::cmdExpired;
  cmds["refresh"] = karpovich::cmdRefresh;
  std::string cmd;
  while (std::cin >> cmd) {
    try {
      cmds.at(cmd)(std::cin, std::cout, notes);
    } catch (const std::out_of_range &) {
      std::cout << "<INVALID COMMAND>\n";
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    } catch (const std::logic_error &) {
      std::cout << "<INVALID COMMAND>\n";
      std::cin.ignore(std::numeric_limits< std::streamsize >::max(), '\n');
    }
  }
}

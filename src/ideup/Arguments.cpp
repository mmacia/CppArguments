#include "Arguments.hpp"

using namespace std;

namespace ideup {
////////////////////////////////////////////////////////////////////////////////

Arguments::Arguments()
{
}

Arguments::~Arguments()
{
  if (options_.empty()) {
    return;
  }

  for (auto i = options_.begin(); i != options_.end(); ++i) {
    auto option = i->second;
    delete option;
  }

  options_.clear();
}


Option& Arguments::add(const string& long_name, const char short_name)
{
  Option* option = new Option(long_name, short_name);
  options_[long_name] = option;

  return *option;
}


bool Arguments::evaluate(int argc, char* argv[])
{
  // parse program arguments
  vector<string> args(argv + 1, argv + argc);

  bool is_valid = true;
  errors_.clear();

  for (auto i = options_.begin(); i != options_.end(); ++i) { // configured options
    auto option = i->second;
    bool found = false;

    for (auto j = args.begin(); j != args.end(); ++j) { // given arguments
      string arg_name  = *j;

      stringstream aux;
      aux << "-" << option->shortName();

      string opt_short = aux.str();
      string opt_long  = "--" + option->longName();

      if ((option->hasShortName() && arg_name == opt_short) || (arg_name == opt_long)) {
        if (!option->isFlag()) {
          option->value(*++j);
        }

        found = true;
      }
    }

    if (!found && option->required()) {
      stringstream ss;
      ss << "Option \"" << option->longName() << "\" is required!" << endl;
      errors_ = ss.str();

      is_valid = false;
      break;
    }
  }

  return is_valid;
}


string Arguments::getHelpMessage()
{
  stringstream ss;
  bool has_required_options = false;

  ss << "Usage: \n\n";

  for (auto it = options_.begin(); it != options_.end(); ++it) {
    if (it->second->required()) {
      ss << " [*] ";
      has_required_options = true;
    }
    else {
      ss << "     ";
    }

    ss << "--" << it->first;

    if (it->second->shortName() != '\0') {
      ss << " | -" << it->second->shortName();
    } else {
      ss << "\t";
    }

    ss << "\t" <<  it->second->description() << "\n";
  }

  if (has_required_options) {
    ss << "\n (*) required options.";
  }

  return ss.str();
}


Option& Arguments::get(const string& option_name)
{
  auto found = options_.find(option_name);

  if (found != options_.end()) {
    return *found->second;
  }

  stringstream ss;
  ss << "Option " << option_name << " does not exists!";

  throw string(ss.str());
}


////////////////////////////////////////////////////////////////////////////////
}

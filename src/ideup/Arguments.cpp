#include "Arguments.hpp"

using namespace std;

namespace ideup {
////////////////////////////////////////////////////////////////////////////////

Arguments::Arguments()
{
}

Arguments::~Arguments()
{
}


Arguments& Arguments::add(Option& option)
{
  option_item_t item(option.longName(), shared_ptr<Option>(&option));
  options_.insert(item);

  return *this;
}


bool Arguments::evaluate(int argc, char* argv[])
{
  // parse program arguments
  vector<string> args(argv + 1, argv + argc);

  int last_index = 1;
  bool is_valid = true;
  errors_.clear();

  for (auto i = options_.begin(); i != options_.end(); ++i) { // configured options
    auto option = i->second;
    bool found = false;

    for (auto j = args.begin(); j != args.end(); ++j) { // given arguments
      string arg_name  = *j;
      string arg_value = *++j;

      stringstream ss;
      ss << "-" << option->shortName();

      string opt_short = ss.str();
      string opt_long  = "--" + option->longName();

      if (option->hasShortName() && (arg_name == opt_short || arg_name == opt_long)) {
        option->value(arg_value); // update option value
        last_index += 2;
      }
      else if (!option->hasShortName() && arg_name == opt_long) {
        option->value(arg_value); // update option value
        last_index += 2;
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


shared_ptr<Option> Arguments::get(const string& option_name)
{
  auto found = options_.find(option_name);

  if (found != options_.end()) {
    return found->second; // move the ownership of smart pointer
  }

  stringstream ss;
  ss << "Option " << option_name << " does not exists!";

  throw string(ss.str());
}


////////////////////////////////////////////////////////////////////////////////
}

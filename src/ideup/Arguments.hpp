#ifndef __IDEUP_ARGUMENTS_HPP__
#define __IDEUP_ARGUMENTS_HPP__

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <memory>
#include <sstream>

namespace ideup {
//////////////////////////////////////////////////////////////////////////////

using namespace std;

class Option
{
  public:
    Option(const string& long_name, const char short_name = '\0') :
      long_name_(long_name),
      short_name_(short_name),
      required_(false),
      flag_(false) {};
    ~Option() {};

    Option& required(bool value) { required_ = value; return *this; };
    Option& description(const string& value) { description_ = value; return *this; };
    Option& value(const string& value) { value_ = value; return *this; };
    Option& flag(bool value) { flag_ = value; return *this; };
	Option& found(bool value) { found_ = value; return *this; };

    string description() const { return description_; };
    string longName() const { return long_name_; };
    char shortName() const { return short_name_; };
    bool required() const { return required_; };
    string value() const { return value_; };
    bool hasShortName() const { return short_name_ != '\0'; }
    bool isFlag() const { return flag_; };
	bool isFound() const { return found_; }

  protected:
  private:
    string long_name_;
    char   short_name_;
    bool   required_;
    string description_;
    string value_;
	bool   found_;
    bool   flag_;
};


class Arguments
{
  public:
    Arguments();
    ~Arguments();

    bool evaluate(int argc, char* argv[]);
    Option& add(const string& long_name, const char short_name = '\0');
    string getErrorMessage() { return errors_; };
    string getHelpMessage();
    Option& get(const string& option_name);
	std::string defaultParameter();

  private:
    map<string, Option*> options_;
	string default_parameter_;
    string errors_;
};

//////////////////////////////////////////////////////////////////////////////
}

#endif //__IDEUP_ARGUMENTS_HPP__

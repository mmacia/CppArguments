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
      required_(false) {};
    ~Option() {};

    Option& required(bool value) { required_ = value; return *this; };
    Option& description(const string& value) { description_ = value; return *this; };
    Option& value(const string& value) { value_ = value; return *this; };

    string description() const { return description_; };
    string longName() const { return long_name_; };
    char shortName() const { return short_name_; };
    bool required() const { return required_; };
    string value() const { return value_; };
    bool hasShortName() const { return short_name_ != '\0'; }

  protected:
  private:
    string long_name_;
    char   short_name_;
    bool   required_;
    string description_;
    string value_;
};


typedef pair< string,shared_ptr<Option> > option_item_t;


class Arguments
{
  public:
    Arguments();
    ~Arguments();

    bool evaluate(int argc, char* argv[]);
    Arguments& add(Option& option);
    string getErrorMessage() { return errors_; };
    string getHelpMessage();
    shared_ptr<Option> get(const string& option_name);

  protected:
  private:
    map< string,shared_ptr<Option> > options_;
    string errors_;
};

//////////////////////////////////////////////////////////////////////////////
}

#endif //__IDEUP_ARGUMENTS_HPP__

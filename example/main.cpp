#include "../src/ideup/Arguments.hpp"

using namespace std;
using namespace ideup;

int main(int argc, char* argv[])
{
  Arguments args;

  args.add((new Option("help", 'h'))->required(true).description("Shows this help message."))
      .add((new Option("config", 'c'))->description("Path to config file"))
      .add((new Option("output"))->description("Output directory").value("/tmp"));

  cout << args.getHelpMessage() << endl;

  try {
    cout << "output value: " << args.get("output")->value() << endl;
    cout << "output value: " << args.get("nonexists")->value() << endl;
  }
  catch(string& e) {
    cerr << e << endl;
  }

  if (!args.evaluate(argc, argv)) {
    cout << args.getErrorMessage() << endl;
    exit(1);
  }
  cout << "output value: " << args.get("output")->value() << endl;

  return 0;
}

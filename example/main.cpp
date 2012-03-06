#include "../src/ideup/Arguments.hpp"

using namespace std;
using namespace ideup;

int main(int argc, char* argv[])
{
  Arguments args;

  args.add("help", 'h').required(true).description("Shows this help message.").flag(true);
  args.add("config", 'c').description("Path to config file");
  args.add("output").description("Output directory").value("/tmp");


  cout << args.getHelpMessage() << endl;

  try {
    cout << "output value: " << args.get("output").value() << endl;
    cout << "output value: " << args.get("nonexists").value() << endl;
  }
  catch(string& e) {
    cerr << e << endl;
  }

  if (!args.evaluate(argc, argv)) {
    cout << args.getErrorMessage() << endl;
    return 1;
  }
  cout << "output value: " << args.get("output").value() << endl;

  return 0;
}

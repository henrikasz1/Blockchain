#include "functions.h"

void readFile (std::string fileName, std::string &data)
{
  std::ifstream in (fileName);
  std::stringstream a;
  a << in.rdbuf();
  data = a.str();
}

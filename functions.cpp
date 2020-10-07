#include "functions.h"

void readFile (std::string fileName, std::string &data)//reading file into one string
{
  std::ifstream in (fileName);
  std::stringstream a;
  a << in.rdbuf();
  data = a.str();
  in.close();
}
//-----
void to_bin(std::string &input, std::vector<int> &bin)//converting text into binary system
{
    std::string binary;
    for(char a : input)
    {
      binary = std::bitset<8>(int(a)).to_string();
      for (char b : binary)
      {
        bin.push_back(int(b) - 48);
      }
    }
}
//-----
std::string mixing_bin (std::vector<int> &bin)//mixing values so that the output would be irrecoverable
{
  for(size_t i = 0; i != bin.size() - 4; ++i)
  {
    if (i % 2 == 0)
    {
      bin[i] = bin[i + 4] ^= bin[i]; //using XOR logic operator
      bin[i +4] = bin[bin.size() - 1] ^= bin[i];
    }
    else
    {
      bin[i + 2] = bin[i] ^= bin[i + 2]; //using XOR logic operator
      bin[i] >> 3;
    }
  }
  for (size_t i = 0; i != bin.size() - 15; ++i)
  {
    bin[i] = bin[i + 10] ^= bin[i + 15];
    bin[i + 1] = bin[bin.size() - 1] ^= bin[i];
  }

  //need to work more with logic operator to make avalanche effect
  int x = 0;
  while(bin.size() != 80)
  {
    bin[x] = bin[x] ^= bin[bin.size()-x];
    if (x >= 160)
    {
      x = 0;
    }
    x++;
    bin.pop_back();
  }
  //need to mix values more (avalanche effect)
  std::stringstream ss;

  std::copy(bin.begin(), bin.end(), std::ostream_iterator<int>(ss, ""));//https://stackoverflow.com/questions/2518979/how-to-transform-a-vectorint-into-a-string/2519011

  return ss.str();
}
//-----
void padding (std::vector<int> &bin)
{
  if (bin.size() % 80 != 0)
  {
    unsigned int a = (bin.size() / 80) + 1;
    std::vector<int> pad;//((a * 80) - bin.size(), 1);
    for (size_t i = 0; i !=(a * 80) - bin.size(); ++i)
    {
      if (bin.size() % 2 == 0 && i % 3 == 0)
        {
          pad.push_back(0);
        }
      else
        {
          pad.push_back(1);
        }
    }
    bin.insert(bin.end(), pad.begin(), pad.end());
  }
}
//-----
std::string to_hex(std::string &value)//converting binary to hexadecimal
{
  std::string result = "";
  for (size_t i = 0; i != value.length(); i += 4)
  {
    std::bitset<4> binary(value.substr(i, 4));
    std::stringstream hash;
    hash << std::hex << binary.to_ulong();
    result += hash.str();
  }
  return result;
}

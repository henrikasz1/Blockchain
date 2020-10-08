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
    }
  }
  for(int i = 0; i < bin.size() / 2; i++) {
        bin[i] = bin[i] ^= bin[bin.size() / 2 + i];
        bin[bin.size() - i - 1] = bin[i] ^= bin[bin.size() - i - 1];
        bin[bin.size() / 2  - i] = bin[i] ^= bin[bin.size() / 2 + 1];
    }

  int x = 0;
  while(bin.size() != 256)//altering vector size to 256
  {
    if (x >= 256)
    {
      x = 0;
    }
    x++;
    bin.pop_back();
  }

  std::stringstream ss;
  std::copy(bin.begin(), bin.end(), std::ostream_iterator<int>(ss, ""));//https://stackoverflow.com/questions/2518979/how-to-transform-a-vectorint-into-a-string/2519011

  return ss.str();
}
//-----
void padding (std::vector<int> &bin)
{
  if (bin.size() < 256)
  {
    std::string size = std::bitset<8>(bin.size()).to_string();
    std::vector<int> binsz;
    for (size_t i = 0; i != size.length(); ++i)
    {
      binsz.push_back(int(size[i]) - 48);
    }
    unsigned int a = 0;
    std::vector<int> pad;
    for (size_t i = 0; i != 256 - bin.size(); i += 8)
    {
      if (a < bin.size())
      {
        for (size_t j = 0; j != binsz.size(); ++j)
        {
          pad.push_back(binsz[j] ^= bin[a]);
          a++;
        }
      }
      else
      {
        for (size_t j = 0; j != binsz.size(); ++j)
        {
          pad.push_back(binsz[j]);
        }
        a = 0;
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

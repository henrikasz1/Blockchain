#include "functions.h"

int main(int argc, char *argv[]){

  //time calculating sttuff
  //random_device rd;
  //mt19937 mt(rd());
  //uniform_int_distribution<int> dist(1,10);
  system("cls");
  char choice; //pasirenka input'o tipa
  std::string input;
  std::vector<int> bin;

  std::cout << "Pasirinkite kaip iterpti teksta: \n Ivesti ranka - Spauskite 1 \n Nuskaityti is pasirinkto failo - Iveskite bet kokia kita reiksme\n";
  std::cin >> choice;
  if (choice == '1')
  {
    std::cout << "Insert text \n";
    std::cin >> input;
  }
  else
  {
    if (argc > 1)
    {
      for (size_t i=0; i<argc; i++)
      {
        readFile(argv[i], input);
      }
    }
    else
    {
      std::cout << "The name of the file has not been detected :( \n";
    }
  }
  if (input == "")//forcing to give an output even though the text file is empty
  {
      std::string efl = "This is an empty file";
      to_bin(efl, bin);
  }
  else
  {
      to_bin(input, bin);
  }
  padding(bin);
  std::string value = mixing_bin(bin);
  std::cout << std::endl << to_hex(value) << std::endl;
}

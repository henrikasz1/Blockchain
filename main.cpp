#include "functions.h"

int main(int argc, char *argv[]){

  //time calculating sttuff
  //random_device rd;
  //mt19937 mt(rd());
  //uniform_int_distribution<int> dist(1,10);
  system("cls");
  char choice; //pasirenka input'o tipa
  std::string input;

  std::cout << "Pasirinkite kaip iterpti teksta: \n Ivesti ranka - Spauskite 1 \n Nuskaityti is pasirinkto teksto - Iveskite bet kokia kita reiksme\n";
  std::cin >> choice;
  if (choice == '1')
  {
    std::cout << "Iveskite teksta \n";
    std::cin >> input;
  }
  else
  {
    if (argc > 1)
    {
      for (int i=0; i<argc; i++)
      {
        readFile(argv[i], input);
      }
      std::cout << input << std::endl;
    }
    else
    {
      std::cout << "Neivestas failo pavadinimas :( \n";
    }
  }
  return 0;
}

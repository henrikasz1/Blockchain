#include "functions.h"

int main(int argc, char *argv[]){

  std::random_device rd;             //time calculating stuff
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist(1,10);

  system("cls");
  char choice; //pasirenka input'o tipa
  std::string input;
  //std::vector<int> bin;

  std::cout << "Choose how you want to insert input: \n Insert by hand - press 1 \n Read from chosen file - press 2\n Test collision resistance - press 3\n Test percentage of difference - press any other key\n";
  std::cin >> choice;
  if (choice == '1')
  {
    std::cout << "Insert text \n";
    std::cin >> input;
    auto start = std::chrono::steady_clock::now();
    std::string output = combine_hash_function(input);
    auto finish = std::chrono::steady_clock::now();
    std::cout << output << std::endl;
    std::cout << "Time consumed: " << std::chrono::duration <double, std::milli>(finish - start).count() << "ms" << std::endl;
  }
  else if(choice == '2')
  {
    if (argc > 1)
    {
      for (size_t i=0; i<argc; i++)
      {
        readFile(argv[i], input);
      }
      auto start = std::chrono::steady_clock::now();
      std::string output = combine_hash_function(input);
      auto finish = std::chrono::steady_clock::now();
      std::cout << output << std::endl;
      std::cout << "Time consumed: " << std::chrono::duration <double, std::milli>(finish - start).count() << "ms" << std::endl;
    }
    else
    {
      std::cout << "The name of the file has not been detected :( \n";
    }
  }
  else if(choice == '3')
  {
    test1(10);
    test1(100);
    test1(500);
    test1(1000);
  }
  else{
    test2();
  }
}

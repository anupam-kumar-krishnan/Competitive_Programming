#include <iostream>
#include <unistd.h>

using namespace std;



// programm should be run and compile on GNU/linux platform with g++ compiler
// cause unistd.h header is specific to GNU/linux platform

// function that will ask to enter yes or no depending what he want
char ask_option(){

  // declaring character for storing user choice
  char choice;

  // asking for input and saving it in choice
  std::cin >> choice;

  // loop that will keep asking for input unless it is a Y,y,N or n
  while (choice != 'n' && choice != 'y' && choice != 'Y' && choice != 'N') {
    std::cout << "wrong input entered try again" << '\n';
    // asking for inout and saving it in choice
    std::cin >> choice;
  }

  // returning choice for the function ask_option()
  return choice;

}

int main () {

  // declaring variable for storing user choice
  char choice ;

  // telling user what the programm is for
  cout << "Think of a quadrilateral from square, rectangle, kite, rhombus, trapezium and parallelogram and I will guess it... \n" ;
  cout << "press any key to continue " <<flush  ;

  // waiting for user to press any key (code specific to GNU/linux platform only)
  system("read -s -N 1");

  // loop that will output coundown and run in each loop after waiting 1 second
  for (int i = 1; i < 4; i++) {
    cout << i <<"," << flush;
    // sleep function specific to unistd.h header
    sleep(1);
  }

  // clearing the screen (linux specific command)
  system("clear");


  std::cout << "Q1. Are all sides equal? (Y or N)";
  // running function ask_option() and saving it in choice
  choice = ask_option();

  // if statment checking choice and running the suitable operation
  if (choice == 'Y' || choice == 'y' ) {

    cout << "Are all angles 90 degrees? (Y/y or N/n)";

    // running function ask_option() and saving it in choice
    choice = ask_option();

    // if statment checking choice and running the suitable operation
    if (choice== 'Y' || choice == 'y') {
      std::cout << "It is a  square" << '\n';
    } else {
      std::cout << "It is a  rhombus" << '\n';
    }

  } else  {

    cout << "Are all angles 90 degrees? (Y or N)";

    // running function ask_option() and saving it in choice
    choice = ask_option();

    // if statment checking choice and running the suitable operation
    if (choice== 'Y' || choice == 'y') {
      std::cout << "It is a  rectangle" << '\n';
    } else {

      cout << "Are opposite sides equal? (Y or N)";

      // running function ask_option() and saving it in choice
      choice = ask_option();

      // if statment checking choice and running the suitable operation
      if (choice== 'Y' || choice == 'y') {
        std::cout << "It is a  paralellogram" << '\n';
      } else {

        cout << "Are adjacent sides equal? (Y or N)";

        // running function ask_option() and saving it in choice
        choice = ask_option();

        // if statment checking choice and running the suitable operation
        if (choice== 'Y' || choice == 'y') {
          std::cout << "It is a  kite" << '\n';
        } else {
          std::cout << "It is a  trapezium" << '\n';
        }

      }

    }

  }


	return 0;
}

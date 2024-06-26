#include "TextEditor.h"
#include <iostream>

void showMenu() {
	std::cout << "\n Simple Text Editor\n";
	std::cout << "1. Add Text \n";
	std::cout << "2. Display Text\n";
	std::cout << "3. Save Text to File\n";
	std::cout << "4. Exit\n";
	std::cout << "Choose an option: ";
}

int main() {
	TextEditor& editor = TextEditor::getInstance();
	int choice;
	std::string input;

	do {
	  showMenu();
	  std::cin >> choice;
	  std::cin.ignore(); // To ignore the newline character after entering the choice
	
	  switch(choice) {
		  case 1:
			  std::cout << "Enter text to add: ";
			  std::getline(std::cin, input);
			  editor.addText(input);
			  break;
		 case 2:
			  editor.displayText();
			  break;
		 case 3:
			  std::cout << "Enter the filename to save text: ";
			  std::getline(std::cin, input);
			  editor.saveToFile(input);
			  break;
		case 4:
			  std::cout << "Exiting...\n";
			  break;
		default:
			  std::cout << "Invalid option! Try again. \n";
			  break;
	  }
	} while(choice != 4);

	return 0;
}

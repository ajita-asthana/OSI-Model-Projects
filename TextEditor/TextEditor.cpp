#include "TextEditor.h"
#include <iostream>
#include <fstream>

void TextEditor::addText(const std::string& newText) {
	text += newText;
}

void TextEditor::displayText() const {
	std::cout << "Current Text:\n" << text << std::endl;
}

void TextEditor::saveToFile(const std::string& fileName) {
	std::ofstream outFile(fileName);
	if(outFile) {
		outFile << text;
		outFile.close();
		std::cout << "Text saved to " << fileName << std::endl;
	} else {
		std::cout << "Failed to open file: " << fileName << std::endl;
	}
}

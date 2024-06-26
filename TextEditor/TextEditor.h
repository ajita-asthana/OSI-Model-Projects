#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <string>

class TextEditor {
private:
	std::string text;
	std::string filename;

	//Private constructor to enforce singleton
	TextEditor() {}

	//Delete copy constructor and assignment operator to prevent copies
	TextEditor(const TextEditor&) = delete;
	TextEditor& operator=(const TextEditor&) = delete;

public:
	//Method to get the singleton instance
	static TextEditor& getInstance() {
		static TextEditor instance;
		return instance;
	}

	//Methods to text operations
	void addText(const std::string& newText);
	void displayText() const;
	void saveToFile(const std::string& fileName);
};

#endif

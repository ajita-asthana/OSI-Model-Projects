#include <iostream>
#include <stack>
#include <string>

class TextEditor {
private:
	std::string currentText;
	std::stack<std::string> undoStack;
	std::stack<std::string> copyStack;

public:
	//Write Operation
	void write(const std::string& text) {
		undoStack.push(currentText);
		currentText += text;
	}

	//Copy Operation
	void copy() {
		copyStack.push(currentText);
	}

	//Paste Operation
	void paste() {
		if(!copyStack.empty()) {
			undoStack.push(currentText);
			currentText += copyStack.top();
		} else {
			std::cout << "Nothing to paste!" << std::endl;
		}
	}

	// Undo Operation
	void undo() {
		if(!undoStack.empty()) {
			currentText = undoStack.top();
			undoStack.pop();
		} else {
			std::cout << "Nothing to undo!" << std::endl;
		}
	}

	void showText() const {
		std::cout << "Current Text: " << currentText << std::endl;
	}
};

int main() {
	TextEditor editor;

	editor.write("Hello");
	editor.showText();

	editor.copy();
	editor.write(" World");
	editor.showText();

	editor.undo();
	editor.showText();

	editor.paste();
	editor.showText();

	return 0;
}

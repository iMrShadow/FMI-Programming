#include "book.h"
#include <fstream>


int main() {
	std::ifstream fin("my_books.bin", std::ios::in || std::ios::binary);

	while (fin.peek() != EOF) {
		// Прочетете обекта от `fin` и го отпечатайте на `stdout`.
		// ...
	}

	return 0;
}
#include "book.h"
#include <fstream>


int main() {
	std::ifstream fin("my_books.bin", std::ios::in || std::ios::binary);

	while (fin.peek() != EOF) {
		// Ïðî÷åòåòå îáåêòà îò `fin` è ãî îòïå÷àòàéòå íà `stdout`.
		// ...
	}

	return 0;
}

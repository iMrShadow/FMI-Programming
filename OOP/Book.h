#ifndef _OOP_BOOK_HPP_
#define _OOP_BOOK_HPP_

#include <iostream>
#include <cstring>
#include <fstream>

struct Book {
	int serialNumber;
	char* title;

	Book(const int serialNumber, const char* title) :
		serialNumber{ serialNumber } {
		const size_t len = strlen(title);
		this->title = new char[len + 1];
		strcpy(this->title, title);
	}

	// Êîíñòðóêòîð, êîéòî ïðî÷èòà (äåñåðèàëèçèðà) êíèãà îò âõîäåí ïîòîê
	Book(std::istream& in) {
		in.read((char*)&serialNumber, sizeof(int));
		size_t len;
		in.read((char*)&len, sizeof(len));
		this-> title = new char[len + 1];
		in.read((char*)title, len);
		title[len] = 0;
		// TODO: Èìïëåìåíòèðàéòå ìåòîäà
	}

	// TODO: Äîâúðøåòå êàíîíè÷íîòî ïðåäñòàâÿíå íà êëàñà `Book`

	// Ìåòîä, êîéòî çàïèñâà (ñåðèàëèçèðà) êíèãà íà èçõîäåí ïîòîê
	void save(std::ostream& out) const {
		f.write((char*)&serialNumber, sizeof(serialNumber));
		const size_t len = strlen(title);
		f.write((char*)&len, sizeof(len));
		f.write(title, len);
	}
};

#endif /* _OOP_BOOK_HPP_ */

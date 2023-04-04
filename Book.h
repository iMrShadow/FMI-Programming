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

	// �����������, ����� ������� (�������������) ����� �� ������ �����
	Book(std::istream& in) {
		in.read((char*)&serialNumber, sizeof(int));
		size_t len;
		in.read((char*)&len, sizeof(len));
		this-> title = new char[len + 1];
		in.read((char*)title, len);
		title[len] = 0;
		// TODO: ��������������� ������
	}

	// TODO: ��������� ����������� ����������� �� ����� `Book`

	// �����, ����� ������� (�����������) ����� �� ������� �����
	void save(std::ostream& out) const {
		f.write((char*)&serialNumber, sizeof(serialNumber));
		const size_t len = strlen(title);
		f.write((char*)&len, sizeof(len));
		f.write(title, len);
	}
};

#endif /* _OOP_BOOK_HPP_ */
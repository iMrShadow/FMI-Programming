#include <iostream>
#include <cassert>
#include <string>
#include <exception>


class Cypher
{
protected:
	static size_t indexOf(const char ch)
	{
		assert('A' <= ch <= 'Z');
		return ch - 'A';
	}

public:
	static const size_t alphabet_size = 'Z' - 'A' + 1;

	virtual char encrypt(char) = 0;
	virtual ~Cypher() {}
};

class CeaserCypher : public Cypher
{
private:
	size_t offset;

	static char enc(const char c, const size_t offset)
	{
		return 'A' + (indexOf(c) + offset) % alphabet_size;
	}

public:
	CeaserCypher(const size_t offset)
	{
		setOffSet(offset);
	}

	void setOffSet(const size_t offset)
	{
		this->offset = offset % alphabet_size;
	}

	size_t getOffSet() const { return offset; }
	char encrypt(const char ch) override { return enc(ch, offset); }
	char decrypt(const char ch) { return enc(ch, alphabet_size - offset); }
};

class PermutationCypher : public Cypher
{
public:
	char letters[alphabet_size];

	PermutationCypher(const char* letters)
	{

		if (strlen(letters) != alphabet_size)
		{
			throw std::invalid_argument("Letters must be 26 characters!");
		}

		for (size_t i = 0; i < alphabet_size; i++)
		{
			this->letters[i] = letters[i];
		}
	}

	char encrypt(const char c) override { return letters[indexOf(c)]; }
};


class Reflector : public PermutationCypher
{
private:
	static const char* getPerm(const std::string& config)
	{
		if (config == "UKW-A")
		{
			return "EJMZALYXVBWFCRQUONTSPIKHGD";
		}
		else if (config == "UKW-B")
		{
			return "YRUHQSLDPXNGOKMIEBFZCWVJAT";
		}
		else if (config == "UKW-C")
		{
			return "FVPJIAOYEDRZXWGCTKUQSBNMHL";
		}
		else
		{
			throw std::invalid_argument("Invalid Reflector config!");
		}
	}

public:
	Reflector(const std::string& config) : PermutationCypher(getPerm(config)) {}
};

class Plugboard : public PermutationCypher
{
public:
	Plugboard() : PermutationCypher("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {}

	void plug(const char a, const char b)
	{
		if (letters[indexOf(a)] != a)
		{
			throw std::invalid_argument("a is alread plugged in!");
		}
		if (letters[indexOf(b)] != b)
		{
			throw std::invalid_argument("b is alread plugged in!");
		}

		letters[indexOf(a)] = b;
		letters[indexOf(b)] = a;
	}
};

class Rotator : public Cypher
{
private:
	CeaserCypher ceaser;
	PermutationCypher perm;

	static const char* getPerm() {}
public:
	static const char* getPerm(const std::string& config)
	{
		if (config == "UKW-A")
		{
			return "EJMZALYXVBWFCRQUONTSPIKHGD";
		}
		else if (config == "UKW-B")
		{
			return "YRUHQSLDPXNGOKMIEBFZCWVJAT";
		}
		else if (config == "UKW-C")
		{
			return "FVPJIAOYEDRZXWGCTKUQSBNMHL";
		}
		else
		{
			throw std::invalid_argument("Invalid Reflector config!");
		}
	}

	char encrypt(const char c) override
	{
		char res = ceaser.encrypt(c);
		res = perm.encrypt(res);
		res = ceaser.decrypt(res);
		step();
		return res;
	}

	void step()
	{
		const size_t offset = ceaser.getOffSet();
		ceaser.setOffSet(offset + 1);
	}
};



int main()
{

	Reflector a("UKW-A");
	CeaserCypher s(3);
	for (char c : "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
	{
		std::cout << c << " -> " << a.encrypt(c) << std::endl;
	}


	return 0;
}
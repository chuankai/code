#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Something {
	int id;

	Something() {
		id = rand();
		cout << "Something "<< id << " allocated\n";
	}

	~Something() {
		cout << "Something " << id << " released\n";
	}
};

class Bar {
private:
	int length = 0;
	char* data = nullptr;
	Something* st = nullptr;

public:
	Bar(int len = 1): length {len} {
		cout << "Default constructor\n";

		data = new char[len];
		for (int i = 0; i < len; ++i)
			data[i] = 32; // ASCII of space
		
		st = new Something;
	}

	Bar(int len, char c): length {len} {
		data = new char[len];
		for (int i = 0; i < len; ++i)
			data[i] = c;

		st = new Something;
	}

	Bar(const Bar& b) {
		cout << "Copy Constructor\n";

		length = b.length;
		data = new char[length];
		for (int i = 0; i < length; ++i)
			data[i] = b.data[i];

		st = new Something;
	}

	Bar(Bar&& b) noexcept: length {b.length}, data {b.data}, st {b.st} {
		cout << "Move constructor\n";

		b.data = nullptr;
		b.st = nullptr;
	}

	Bar& operator=(const Bar& from) {
		cout << "Copy Assignment Initializer\n";

		if (&from == this)
			return  *this;

		this->length = from.length;
		delete[] this->data;
		this->data = new char[this->length];
		for (int i = 0; i < this->length; ++i)
			this->data[i] = from.data[i];

		delete st;
		st = new Something;
		return *this;
	}

	Bar& operator=(Bar&& from) noexcept {
		cout << "Move assignment\n";

		length = from.length;
		delete[] data;
		delete st;
		data = from.data;
		from.data = nullptr;
		st = from.st;
		from.st = nullptr;

		return *this;
	}

	~Bar() {
		delete[] data;
		data = nullptr;
		delete st;
		st = nullptr;
	}

	void print() {
		for (int i = 0; i < length; ++i)
			cout << data[i];

		cout << '\n';
	}

	void set(int pos, char c) {
		if (pos < length)
			data[pos] = c;
	}
};

Bar buildBar() {
	Bar b {6, '@'};
	return b;
}

void kswap(Bar& a, Bar& b) {
	Bar t = move(a);
	a = move(b);
	b = move(t);
}

int main() {
	Bar a = Bar {3, '*'};
	Bar b = Bar {6, '$'};

	a.print();
	b.print();

	kswap(a, b);
	a.print();
	b.print();

	return 0;
}

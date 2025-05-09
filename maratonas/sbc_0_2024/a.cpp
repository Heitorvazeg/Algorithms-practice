#include <iostream>

int main() {
	int diasSoma = 0 + 1 + 2 + 3;
	int soma;

	for (int i = 0; i < 3; i++) {
		int auxiliar;
		std::cin >> auxiliar;
		soma += auxiliar;
	}

	std::cout << diasSoma - soma << std::endl;

	return 0;
}

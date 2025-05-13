/*maps possuem chave valor; a chave é única e funciona como um id. O valor é associado a chave.
Cada dado pega uma "impressão digital" chamada hash. Esses hash trabalham como index na hash table.
O hash e calculado, se 2 valores forem  iguais, isso gera uma colisão, 2 valores no msm index.
Caso isso ocorra, o quadrado da hastable com dois valores se torna uma linkedList para suportar os valores.
Chaining. 
Trabalha como um array dinamico, tem a capacidade que expande quando necessário.*/

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> hashTable;

    hashTable[1] = "um";
    hashTable[2] = "dois";

    hashTable.insert({3, "tres"});

    std::cout <<  hashTable.at(2) << "\n";

    if (hashTable.count(3)) {
        std::cout << "Tres esta na tabela\n";
    }

    hashTable.erase(1);

    for (const auto& par : hashTable) {
        std::cout << par.first << " : " << par.second << std::endl;
    }
}
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>

// Função para formatar números com pontos como separador de milhar
std::string format_number(int n) {
    std::string num = std::to_string(n);
    int len = num.length();
    std::string formatted = "";

    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        formatted = num[i] + formatted;
        count++;

        if (count % 3 == 0 && i != 0) {
            formatted = "." + formatted;
        }
    }
    return formatted;
}

// Verifica se um número é primo testando apenas até sqrt(n)
bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2) return true; // 2 é primo
    if (n % 2 == 0) return false; // Elimina pares maiores que 2

    for (int i = 3; i <= sqrt(n); i += 2) {  // Testa apenas ímpares
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    clock_t start_time = clock(); // Marca o tempo inicial

    int num = 2;             // Começa de 2
    int total_primos = 0;    // Contador de primos encontrados
    int maior_primo = 2;     // Maior primo encontrado

    while (double(clock() - start_time) / CLOCKS_PER_SEC < 30) {
        if (is_prime(num)) {  
            total_primos++;  // Conta o primo
            maior_primo = num;  // Atualiza o maior primo
        }
        num++; // Passa para o próximo número
    }

    // Calcula o tempo total de execução
    double tempo_total = double(clock() - start_time) / CLOCKS_PER_SEC;

    // Exibe os resultados formatados
    std::cout << "Tempo total de execução: " << tempo_total << " segundos\n";
    std::cout << "Total de primos encontrados: " << format_number(total_primos) << "\n";
    std::cout << "Maior primo encontrado: " << format_number(maior_primo) << "\n";

    return 0;
}

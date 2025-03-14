#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

// Formata números com separação de milhar
string format_number(int n) {
    string num = to_string(n);
    int len = num.length();
    string formatted = "";

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

// Implementação do Crivo de Eratóstenes
void sieve_of_eratosthenes(vector<bool>& is_prime, int start, int end, vector<int>& primes) {
    fill(is_prime.begin() + start, is_prime.begin() + end + 1, true);

    int sqrt_end = sqrt(end);
    for (int prime : primes) {
        if (prime > sqrt_end) break;
        int multiple = max(prime * prime, ((start + prime - 1) / prime) * prime);
        for (int j = multiple; j <= end; j += prime) {
            is_prime[j] = false;
        }
    }

    for (int i = start; i <= end; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    auto start_time = chrono::high_resolution_clock::now(); // Marca o tempo inicial

    vector<int> primes = {2, 3, 5, 7}; // Lista inicial de primos
    int n = 10; // Intervalo inicial
    vector<bool> is_prime(2 * n + 1, false);

    while (true) {
        auto current_time = chrono::high_resolution_clock::now();
        double elapsed_time = chrono::duration<double>(current_time - start_time).count();

        if (elapsed_time >= 30.0) break; // Parar após 30 segundos exatos

        int start = n + 1;
        int end = n * 2;
        if (is_prime.size() < end + 1) {
            is_prime.resize(end + 1, false);
        }

        sieve_of_eratosthenes(is_prime, start, end, primes);
        n = end; // Expande o intervalo
    }

    auto end_time = chrono::high_resolution_clock::now();
    double tempo_total = chrono::duration<double>(end_time - start_time).count();

    // Exibe os resultados finais
    cout << "Tempo total de execução: " << tempo_total << " segundos\n";
    cout << "Total de primos encontrados: " << format_number(primes.size()) << "\n";
    cout << "Maior primo encontrado: " << format_number(primes.back()) << "\n";

    return 0;
}

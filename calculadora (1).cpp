#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

/**
 * @brief Classe Calculadora que realiza operações básicas.
 */
class Calculadora {
public:
    /**
     * @brief Soma dois números.
     * @param a Primeiro número.
     * @param b Segundo número.
     * @return Resultado da soma.
     */
    double soma(double a, double b) { return a + b; }

    /**
     * @brief Subtrai dois números.
     * @param a Primeiro número.
     * @param b Segundo número.
     * @return Resultado da subtração.
     */
    double subtracao(double a, double b) { return a - b; }

    /**
     * @brief Multiplica dois números.
     * @param a Primeiro número.
     * @param b Segundo número.
     * @return Resultado da multiplicação.
     */
    double multiplicacao(double a, double b) { return a * b; }

    /**
     * @brief Divide dois números, lançando exceção se b = 0.
     * @param a Primeiro número.
     * @param b Segundo número.
     * @return Resultado da divisão.
     */
    double divisao(double a, double b) {
        if (b == 0) throw runtime_error("Erro: Divisão por zero!");
        return a / b;
    }
};

/**
 * @brief Função para testar operações da calculadora.
 */
void testarCalculadora() {
    Calculadora calc;
    cout << "\n=== Testes Unitários ===\n";
    cout << "2 + 3 = " << calc.soma(2, 3) << " (Esperado: 5)\n";
    cout << "7 - 5 = " << calc.subtracao(7, 5) << " (Esperado: 2)\n";
    cout << "4 * 3 = " << calc.multiplicacao(4, 3) << " (Esperado: 12)\n";

    try {
        cout << "10 / 2 = " << calc.divisao(10, 2) << " (Esperado: 5)\n";
        cout << "10 / 0 = " << calc.divisao(10, 0) << "\n"; // Deve falhar
    } catch (const runtime_error &e) {
        cout << e.what() << "\n";
    }
}

/**
 * @brief Função para exibir menu colorido.
 */
void exibirMenu() {
    cout << "\033[1;36m"; // Cor ciano
    cout << "\n==== CALCULADORA EM C++ ====\n";
    cout << "\033[0m"; // Reset cor
    cout << "1. Soma\n";
    cout << "2. Subtração\n";
    cout << "3. Multiplicação\n";
    cout << "4. Divisão\n";
    cout << "0. Sair\n";
    cout << "Escolha uma opção: ";
}

int main() {
    Calculadora calc;
    int opcao;
    double a, b;

    testarCalculadora(); // Executa testes

    do {
        exibirMenu();
        cin >> opcao;

        if (opcao >= 1 && opcao <= 4) {
            cout << "Digite o primeiro número: ";
            cin >> a;
            cout << "Digite o segundo número: ";
            cin >> b;
        }

        try {
            switch (opcao) {
                case 1:
                    cout << "Resultado: " << calc.soma(a, b) << "\n";
                    break;
                case 2:
                    cout << "Resultado: " << calc.subtracao(a, b) << "\n";
                    break;
                case 3:
                    cout << "Resultado: " << calc.multiplicacao(a, b) << "\n";
                    break;
                case 4:
                    cout << "Resultado: " << calc.divisao(a, b) << "\n";
                    break;
                case 0:
                    cout << "Saindo...\n";
                    break;
                default:
                    cout << "Opção inválida!\n";
            }
        } catch (const runtime_error &e) {
            cout << e.what() << "\n";
        }
    } while (opcao != 0);

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

#define QTD_ALUNOS 5
#define QTD_NOTAS 3



// Função para calcular a média das 3 notas

float calcularMedia(float notas[]) {
	float soma = 0;
	for (int i = 0; i < QTD_NOTAS; i++) {
		soma += notas[i];
	}
	return soma / QTD_NOTAS;
}



int main() {
	string nomes[QTD_ALUNOS];
	float notas[QTD_ALUNOS][QTD_NOTAS];
	float medias[QTD_ALUNOS];
	string situacoes[QTD_ALUNOS];
	int MaiorMedia = 0;



	// Entrada de dados

	for (int i = 0; i < QTD_ALUNOS; i++) {
		cout << "Digite o primeiro nome do aluno " << i + 1 << ": ";
		cin >> nomes[i];


		for (int j = 0; j < QTD_NOTAS; j++) {
			cout << "Digite a nota " << j + 1 << " de " << nomes[i] << ": ";
			cin >> notas[i][j];
		}



		// Calcula a média atraves da funçãoo criada incialmente
		medias[i] = calcularMedia(notas[i]);


		// analisa a situação com uma condicional de >= a 7
		if (medias[i] >= 7.0) {
			situacoes[i] = "Aprovado";
		} else {
			situacoes[i] = "Reprovado";
		}


		// Verifica se tem a maior média e de quem é 
		if (medias[i] > medias[MaiorMedia]) {
			MaiorMedia = i;
		}
		cout << endl;
	}



	// Exibe a tabela com os resultados obtidos e escritos
	cout << "-------------------------------------------------------------\n";
	cout << "Nome\tNota1\tNota2\tNota3\tMedia\tSituacao\n";
	cout << "-------------------------------------------------------------\n";


	for (int i = 0; i < QTD_ALUNOS; i++) {
		cout << nomes[i] << "\t";
		for (int j = 0; j < QTD_NOTAS; j++) {
			cout << notas[i][j] << "\t";
		}
		cout << medias[i] << "\t" << situacoes[i] << endl;
	}

	cout << "-------------------------------------------------------------\n";
	cout << "Aluno com maior media: " << nomes[MaiorMedia]
	     << " (" << medias[MaiorMedia] << ")" << endl;

	return 0;

}

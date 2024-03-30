#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define pause do { while (getchar() != '\n'); } while (0)
char playerName[20];

int main(int argc, char const *argv[]) {
	setlocale(LC_ALL, "");
	printf("DIA 2 DE MARÇO - PRIMEIRO DIA DE AULA\n\n");
	pause;
	printf("Este é seu primeiro dia de aula como um calouro de SI na EACH, USP-Leste. Você mal pode esperar para rever aquela e-girl gatinha que você viu na semana de introdução. Era Isa o nome dela né?\n");
	pause;
	printf("Calma aí, peregrino, você ao menos se lembra de seu próprio nome?\n");
	pause;
	printf("Qual é seu nome?\ndigite seu nome: ");
	scanf("%s", playerName);
	pause;
	printf("Enfim, é melhor você se apressar, %s, a aula de cálculo 1 já vai começar e você ainda está na ponte que sai da CPTM\n", playerName);
	pause;
	printf("Você começa a correr...");
	pause;
	printf("e correr...");
	pause;
	printf("e correr.\n");
	pause;
	printf("Você finalmente chega no portão 3, mas... MALDIÇÃO! você esqueceu de pegar o seu cusp pra mostrar pro guarda. Desse jeito você não vai poder entrar\n");

	return 0;
}

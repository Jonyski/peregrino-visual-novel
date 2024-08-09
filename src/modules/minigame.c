#include "minigame.h"
#include "gamestate.h"
#include "stdlib.h"
#include "userinput.h"
#include <stdio.h>
#include <string.h>

void calc_game();
void ip_game();

void minigameManager() {
	currContext.currActivity = MINIGAME;
	switch (currContext.miniGameId) {
	case 0:
		calc_game();
		break;
	case 1:
		ip_game();
		break;
	default:
		printf("Unimplemented game id\n");
		break;
	}
	currContext.currActivity = CLASS;
}

void ip_game() {
	printf("Unimplemented\n");
	readInput();
}

void calc_game() {

	currContext.miniGameQuestionId = 0;
	printf("---PRIMEIRA QUESTÃO---\n\n");
	printf("Hoje a aula foi sobre o conceito de infinidade. Com os seus "
		   "conhecimentos de Pré-Cálculo, escolha a alternativa correta:\n");
	printf("Qual desses conjuntos numéricos é maior que todos os outros?\n");
	printf("1) Naturais\n"
		   "2) Reais\n"
		   "3) Racionais\n"
		   "4) Inteiros\n");
	printf("Digite o número correspondente a alternativa escolhida:\n");

	readInput();

	currContext.miniGameQuestionId++;

	printf("Resposta correta!\n");

	printf("---SEGUNDA QUESTÃO---\n\n");
	printf(" ");

	readInput();

	currContext.miniGameQuestionId++;
	printf("Resposta correta!\n");

	printf("---TERCEIRA QUESTÃO---\n\n");
	printf(" ");

	readInput();

	printf("Resposta correta!\n");
}

InputERR processCalcGameQ1(char *input);
InputERR processCalcGameQ2(char *input);
InputERR processCalcGameQ3(char *input);

InputERR processCalcGame(char *input, short int question_num) {
	switch (question_num) {
	case 0:
		return processCalcGameQ1(input);
		break;
	case 1:
		return processCalcGameQ2(input);
		break;
	default:
		return NO_ERR;
		break;
	}
}

InputERR processCalcGameQ1(char *input) {
	if (!strlen(input)) {
		return NULL_INPUT;
	} else if (strlen(input) > 1) {
		return TOO_LONG;
	}

	int input_as_num = atoi(input);
	if (input_as_num == 0) {
		return SHOULD_BE_INT;
	} else if (input_as_num != 2) {
		return WRONG_ANSWER;
	} else {
		return NO_ERR;
	}
}

// TODO: Unimplemented
InputERR processCalcGameQ2(char *input) { return NO_ERR; }

// TODO: Unimplemented
InputERR processCalcGameQ3(char *input) { return NO_ERR; }

// TODO: Unimplemented
InputERR processIpGame(char *input, short int question_num) { return NO_ERR; }

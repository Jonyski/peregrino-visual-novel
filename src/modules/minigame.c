#include "minigame.h"
#include "stdlib.h"
#include "userinput.h"
#include <stdio.h>
#include <string.h>

void calc_game1();

void minigameManager(short int minigame_id) {
  switch (minigame_id) {
    case 0:
      calc_game1();
      break;
    default: 
      printf("Unimplemented game id\n");
      break;
  }
}

void calc_game1() {
  printf("Hoje a aula foi sobre o conceito de infinidade. Com os seus "
         "conhecimentos de Pré-Cálculo, escolha a alternativa correta:\n");
  printf("Qual desses conjuntos numéricos é maior que todos os outros?\n");
  printf("1) Naturais\n"
         "2) Reais\n"
         "3) Racionais\n"
         "4) Inteiros\n");
  printf("Digite o número correspondente a alternativa escolhida:\n");

  readInput();

  printf("Resposta correta!\n");
}

InputERR processCalcGame(char *input) {
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

#include "minigame.h"
#include "gamestate.h"
#include "stdlib.h"
#include "IO.h"
#include <stdio.h>
#include <string.h>

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
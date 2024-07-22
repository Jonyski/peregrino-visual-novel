#include "commands.h"

void help() {
	puts("para dar um comando digite o nome dele por extenso ou sua abreviação e então aperte enter:");
	puts("");
	puts("help (h): obtenha informações sobre os comandos do jogo");
	puts("options (o): mude as opções do jogo");
	puts("inventory (i): veja seu inventário");
	puts("jupiter (j): veja sua grade horária no JupiterWeb");
	puts("save (s): salve o jogo");
	puts("quit (q): saia do jogo (;-;)");
}

void options() {
	// TO-DO: implement this function for real
	puts("OPÇÕES: ");
}

void exibitInventory() {
	// TO-DO: implement this function for real
	puts("INVENTÁRIO: ");
}

void jupiterWeb() {
	// TO-DO: implement this function for real
	puts("https://uspdigital.usp.br/jupiterweb/gradeHoraria");
}

void save() {
	// TO-DO: implement this function for real
	puts("salvando o jogo...");
	puts("...");
	puts("JOGO SALVO");
}

void quit() {
	// TO-DO: implement this function for real
	puts("see you next time!");
}
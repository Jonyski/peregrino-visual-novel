#include "commands.h"
#include "utils.h"

void readCommand() {
	printf("$ ");
	char command[32];
	cleanScan(command);
	processCommand(command);
}

int processCommand(char *cmd) {
	if(strlen(cmd) == 0) {
		return 0;
	}

	if(!strcmp(cmd, "help") || !strcmp(cmd, "h")) {
		help();
		return 1;
	} else if(!strcmp(cmd, "options") || !strcmp(cmd, "o")) {
		options();
		return 1;
	} else if(!strcmp(cmd, "save") || !strcmp(cmd, "s")) {
		save();
		return 1;
	} else if(!strcmp(cmd, "inventory") || !strcmp(cmd, "i")) {
		exibitInventory();
		return 1;
	} else if(!strcmp(cmd, "jupiter") || !strcmp(cmd, "j")) {
		jupiterWeb();
		return 1;
	} else if(!strcmp(cmd, "quit")) {
		quit();
		return 1;
	}

	return 0;
}

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
	pause;
}

void exibitInventory() {
	// TO-DO: implement this function for real
	puts("INVENTÁRIO: ");
	pause;
}

void jupiterWeb() {
	puts("https://uspdigital.usp.br/jupiterweb/gradeHoraria");

	FILE *file;
	char cronogram[256];
	
	#ifdef _WIN32
		file = fopen("./assets/SI-cronogram.txt", "r");
	#else
		file = fopen("./assets/SI-cronogram.txt", "r");
	#endif

	if(file == NULL){
		perror("Error opening file");
		exit(1);
	}

	while(fgets(cronogram, sizeof(cronogram), file) != NULL){
		printf("%s", cronogram);
	}
	
	fclose(file);
	pause;
}

void save() {
	// TO-DO: implement this function for real
	puts("salvando o jogo...");
	puts("...");
	puts("JOGO SALVO");
	pause;
}

void quit() {
	// TO-DO: implement this function for real
	puts("see you next time!");
	pause;
}
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

enum game_state {
	OVER,
	RUNNING

}

struct attack {
	char* name;
	int damage; // pv de 0-1000
	int energy_cost; //energie de 0-100
	int xp_reward; 
}

struct pokemon {
	int alive;
	char* name;
	int energy;
	int max_pv;
	int curr_pv;
	int max_xp;
	int curr_xp;
	int level;
	struct attack* attack_list;
}

struct player {
	char* name;
	struct pokemon pokemon_list;

}

struct game {
	int round_nb;
	enum game_state state;
	

}
struct pokemon salameche_init() {
	struct attack repos = { "REPOS" ; 0 ; -35 ; 0 };
	struct attack draco_griffe = { "DRACO-GRIFFE" ; 70 ; 15 ; 25 };
	struct attack deflagration = { "DEFLAGRATION" ; 120 ; 25 ; 30 };
	struct attack salameche_att_list[3] = { draco_griffe ; deflagration ; repos };
	struct pokemon salameche = { 1 ; "SALAMECHE"; 100 ; 1000 ; 1000 ; 1000 ; 0 ; 1 ; salameche_att_list };
	return salameche;
}
struct pokemon carapuce_init() {
	struct attack repos = { "REPOS" ; 0 ; -35 ; 0 };
	struct attack coup_de_boul = { "COUP D'BOUL" ; 70 ; 15 ; 25 };
	struct attack hydrocanon = { "HYDROCANON" ; 120 ; 25 ; 30 };
	struct attack carapuce_att_list[3] = { coup_de_boul ; hydrocanon ; repos };
	struct pokemon carapuce = { 1 ; "CARAPUCE" ; 100 ; 1000 ; 1000 ; 1000 ; 0 ; 1 carapuce_att_list };
	return carapuce;
}

int choose_pokemon(struct player gamer) {
	printf("Choisi ton pokemon zincou : \n  1:Salameche | 2:Carapuce \n Entre 1 ou 2 pour selectionner\n");
	if(char rep = getc(stdin)){
		if(rep == '1'){
			gamer.pokemon_list = salameche_init();
			return 0;
		}
		if(rep == '2') {
			gamer.pokemon_list = carapuce_init();
			return 0;
		}
		else {
			choose_pokemon(gamer);
			return 0;
		}
	}
	return 1;
}



int luncher() {
	struct game new_game = { 0 ; RUNNING };

	struct player player1;
	player1->name = gets(stdin);
	choose_pokemon(player1);

	struct player player2;
	player2->name = gets(stdin);
	choose_pokemon(player2);

	while(new_game.state == RUNNING){
		++new_game.round_nb;
		printf("======================Tour %d=====================\n" , new_game.round_nb);
		printf("======================\n Player 1 : %s \n Pokemon : %s PV : %d/%d Energie : %d/100 \n LVL : %d XP : %d/%d \n======================\n", player1->name, player1.pokemon_list->name, player1.pokemon_list.curr_pv, player1.pokemon_list.max_pv, player1.pokemon_list.energy, player1.pokemon_list.level, player1.pokemon_list.curr_xp, player1.pokemon_list.max_xp);
		printf("Liste d'attaques de ton pokemon :\n 	1:%s 	2:%s\n 		3:%s\n", player1.pokemon_list->attack_list[0], player1.pokemon_list->attack_list[1], player1.pokemon_list->attack_list[2]);
		printf("%s, ton pokemon attend un ordre.", player1->name); /*tour du player1 */
		if (char rep1 = getc(stdin)){
			if(rep1 == '1'){
				
			}
		}

			
	}	
}

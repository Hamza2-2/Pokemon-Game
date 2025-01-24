#include<iostream> // standard input output librarby 
#include<string>  // character array library
#include<iomanip> // used for setw functions
#include<fstream>
#include<Windows.h>
#include <mmsystem.h>
#include <thread>// used for file handling 
#include<cstdlib> // used to terminate program and rand and srand functions
#include<ctime>// used for giving random number generator algorithm a seed : time function
// libraries used 
using namespace std;
class player;
class pokemon // structure used 
{
private:
	string name;
	string type;
	string weak;
	int HP;
	string P_atk;
	int atkP;
	string E_atk;
	int atkE;

public:
	// Setters
	void setName(const string& n) { name = n; }
	void setType(const string& t) { type = t; }
	void setWeak(const string& w) { weak = w; }
	void setHP(int h) { HP = h; }
	void setP_atk(const string& p) { P_atk = p; }
	void setAtkP(int ap) { atkP = ap; }
	void setE_atk(const string& e) { E_atk = e; }
	void setAtkE(int ae) { atkE = ae; }

	// Getters
	string getName() const { return name; }
	string getType() const { return type; }
	string getWeak() const { return weak; }
	int getHP() const { return HP; }
	string getP_atk() const { return P_atk; }
	int getAtkP() const { return atkP; }
	string getE_atk() const { return E_atk; }
	int getAtkE() const { return atkE; }
	friend void initialize(pokemon poke[20]);
	friend void Load_data(pokemon a[20]);
	friend void PvAI(player p, player CPU, int index, int index2, int turn);
	friend void PvP(player p1, player p2, int index, int index2, int turn);

};
class player // structure of player
{
private:
	string name;
	pokemon P[2];

public:
	// Setters
	void setName(const string& n) { name = n; }
	void setPokemon(int index, const pokemon& p) { if (index >= 0 && index < 2) P[index] = p; }

	// Getters
	string getName() const { return name; }
	pokemon getPokemon(int index) const { return (index >= 0 && index < 2) ? P[index] : pokemon(); }
	friend void Load_data(pokemon a[20]);
	friend void save_data(player p1, player p2, int a, int b, int turn);
	friend void PvAI(player p, player CPU, int index, int index2, int turn);
	friend void selection(pokemon poke[20]);
	friend void PvP(player p1, player p2, int index, int index2, int turn);
};
// prototypes start here
void attack(pokemon, int&, string); // function that handles the attack command 
void initialize(pokemon[]); // called first to initialize pokemon data 
void Menu(pokemon[]); // Function where the game starts from
void display_Pokemon(); // Displays Pokemon Logo
void selection(pokemon[]);// Option To Select Pokemons from
void display_Pokemon_list(pokemon[]); // function that displays list of available pokemons
void PvP(player, player, int, int, int); //player versus player battle
void save_data(player, player, int, int, int); // function that stores data so that player can continue battle from where he left it 
int swap(int); // function to switch pokemon
void PvAI(player, player, int, int, int); // function for player vs CPU
void Load_data(pokemon[]); // reads data from file to conntinue game where left off
//prototypes  end here
void main()// main function
{
	system("cls");
	pokemon arr[20]; // array of type Pokemon
	initialize(arr); // calling function to initialize array 
	Menu(arr);
}

void initialize(pokemon poke[20]) // function called at start to load up data of pokemons
{
	// array called by reference by default so changes made here in array will 
	// take place in main and other functions as well
	// 4 fire type
	poke[0].name = "Charizard";
	poke[0].type = "Fire";
	poke[0].weak = "Water";
	poke[0].HP = 500;
	poke[0].P_atk = "Explosive Fire";
	poke[0].atkP = 60;
	poke[0].E_atk = "Star Blaze";
	poke[0].atkE = 80;

	poke[1].name = "Infernape";
	poke[1].type = "Fire";
	poke[1].weak = "Water";
	poke[1].HP = 450;
	poke[1].P_atk = "Flare Blitz";
	poke[1].atkP = 50;
	poke[1].E_atk = "Flare Up";
	poke[1].atkE = 60;

	poke[2].name = "Rapidash";
	poke[2].type = "Fire";
	poke[2].weak = "Water";
	poke[2].HP = 450;
	poke[2].P_atk = "Searing Flame";
	poke[2].atkP = 90;
	poke[2].E_atk = "Agility";
	poke[2].atkE = 80;

	poke[3].name = "Moltres";
	poke[3].type = "Fire";
	poke[3].weak = "Water";
	poke[3].HP = 500;
	poke[3].P_atk = "Assisting Heater";
	poke[3].atkP = 50;
	poke[3].E_atk = "Fire Wing";
	poke[3].atkE = 80;

	// 4 Water Type

	poke[4].name = "Squirtle";
	poke[4].type = "Water";
	poke[4].weak = "Electric";
	poke[4].HP = 450;
	poke[4].P_atk = "Bubble";
	poke[4].atkP = 30;
	poke[4].E_atk = "Water Gun";
	poke[4].atkE = 50;

	poke[5].name = "Empoleon";
	poke[5].type = "Water";
	poke[5].weak = "Electric";
	poke[5].HP = 460;
	poke[5].P_atk = "Hydropump";
	poke[5].atkP = 40;
	poke[5].E_atk = "Whirlpool";
	poke[5].atkE = 70;

	poke[6].name = "Panpour";
	poke[6].type = "Water";
	poke[6].weak = "Electric";
	poke[6].HP = 500;
	poke[6].P_atk = "Water Gun";
	poke[6].atkP = 40;
	poke[6].E_atk = "Bite";
	poke[6].atkE = 90;

	poke[7].name = "Articuno";
	poke[7].type = "Water";
	poke[7].weak = "Electric";
	poke[7].HP = 500;
	poke[7].P_atk = "Diamond Dust";
	poke[7].atkP = 50;
	poke[7].E_atk = "Blizzard";
	poke[7].atkE = 70;

	// 4 electric 

	poke[8].name = "Zapdos";
	poke[8].type = "Electric";
	poke[8].weak = "Rock";
	poke[8].HP = 530;
	poke[8].P_atk = "Drill Peck";
	poke[8].atkP = 60;
	poke[8].E_atk = "Raging Thunder";
	poke[8].atkE = 80;

	poke[9].name = "Pichu";
	poke[9].type = "Electric";
	poke[9].weak = "Rock";
	poke[9].HP = 450;
	poke[9].P_atk = "Mini Bolt";
	poke[9].atkP = 50;
	poke[9].E_atk = "Charge";
	poke[9].atkE = 40;

	poke[10].name = "Raichu";
	poke[10].type = "Electric";
	poke[10].weak = "Rock";
	poke[10].HP = 500;
	poke[10].P_atk = "Dynamic Spark";
	poke[10].atkP = 50;
	poke[10].E_atk = "Thunder";
	poke[10].atkE = 80;

	poke[11].name = "Pikachu";
	poke[11].type = "Electric";
	poke[11].weak = "Rock";
	poke[11].HP = 470;
	poke[11].P_atk = "Spark";
	poke[11].atkP = 40;
	poke[11].E_atk = "Electro Ball";
	poke[11].atkE = 70;

	// 4 Rock Type 

	poke[12].name = "Onix";
	poke[12].type = "Rock";
	poke[12].weak = "Grass";
	poke[12].HP = 510;
	poke[12].P_atk = "Rock Throw";
	poke[12].atkP = 50;
	poke[12].E_atk = "Ranging swing";
	poke[12].atkE = 80;

	poke[13].name = "Sudowoodo";
	poke[13].type = "Rock";
	poke[13].weak = "Grass";
	poke[13].HP = 470;
	poke[13].P_atk = "Joust";
	poke[13].atkP = 40;
	poke[13].E_atk = "Impoound";
	poke[13].atkE = 60;

	poke[14].name = "Rhydon";
	poke[14].type = "Rock";
	poke[14].weak = "Grass";
	poke[14].HP = 480;
	poke[14].P_atk = "Take down";
	poke[14].atkP = 80;
	poke[14].E_atk = "Horn Drill";
	poke[14].atkE = 90;

	poke[15].name = "Regirock";
	poke[15].type = "Rock";
	poke[15].weak = "Grass";
	poke[15].HP = 500;
	poke[15].P_atk = "Giga Impact";
	poke[15].atkP = 60;
	poke[15].E_atk = "Regi Gate";
	poke[15].atkE = 90;

	// 4 Grass type

	poke[16].name = "Bulbasaur";
	poke[16].type = "Grass";
	poke[16].weak = "Fire";
	poke[16].HP = 480;
	poke[16].P_atk = "Vine Whip";
	poke[16].atkP = 40;
	poke[16].E_atk = "Razor Leaf";
	poke[16].atkE = 50;

	poke[17].name = "Gloom";
	poke[17].type = "Grass";
	poke[17].weak = "Fire";
	poke[17].HP = 460;
	poke[17].P_atk = "Cling";
	poke[17].atkP = 60;
	poke[17].E_atk = "Double Razor Leaf";
	poke[17].atkE = 50;

	poke[18].name = "Torterra";
	poke[18].type = "Grass";
	poke[18].weak = "Fire";
	poke[18].HP = 500;
	poke[18].P_atk = "Giga Brain";
	poke[18].atkP = 50;
	poke[18].E_atk = "Earthquake";
	poke[18].atkE = 80;

	poke[19].name = "Celebi";
	poke[19].type = "Grass";
	poke[19].weak = "Fire";
	poke[19].HP = 500;
	poke[19].P_atk = "Sprouting";
	poke[19].atkP = 60;
	poke[19].E_atk = "Leaf Tornado";
	poke[19].atkE = 70;
	// end of function
}
void Menu(pokemon a[20])
{
	int choice = 0; // variable used to store option selected by the user
	do
	{
		display_Pokemon(); // calls function to display Pokemon logo
		cout << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\tSelect Game Options: " << endl;
		cout << "\t\t\t\t\t\t\t\t1. New Game" << endl;
		cout << "\t\t\t\t\t\t\t\t2. Continue Game" << endl;
		cout << "\t\t\t\t\t\t\t\t3. Play Music " << endl;
		cout << endl << "\t\t\t\t\t\t\t\tOption ==> ";
		cin >> choice;
		system("pause");
		system("cls");
		if (choice < 1 || choice>3)
		{
			display_Pokemon();
			cout << endl << endl;
			cout << "\n\t\t\t\t\t\t\t\tInvalid Option Selected: " << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (choice == 1)
		{
			ofstream fout("PoekmonGame.txt");
			fout << "Empty" << endl;
			fout.close();    // removes data in the save file if new game is selected
			selection(a);
		}
		else if (choice == 2)
		{
			Load_data(a);
		}
		else if (choice == 3)
		{
			playmusic();

		}
	} while (choice < 1 || choice>2);

}
void music1()
{
	PlaySound(TEXT("pokemon-theme-song-gotta-catch-em-all-for-orchestra.wav"), NULL, SND_FILENAME | SND_LOOP);

}
void music2()
{
	PlaySound(TEXT("Kai theme.wav"), NULL, SND_FILENAME | SND_LOOP);
}
void music3()
{
	PlaySound(TEXT("Oogway Ascends.wav"), NULL, SND_FILENAME | SND_LOOP);
}
void music4()
{
	PlaySound(TEXT("Rick_Astley_-_Never_Gonna_Give_You_Up.wav"), NULL, SND_FILENAME | SND_LOOP);
}
void music5()
{
	PlaySound(TEXT("Kung Fu Fightning.wav"), NULL, SND_FILENAME | SND_LOOP);
}
void music6()
{
	PlaySound(TEXT("In the jungle the mighty jungle.wav"), NULL, SND_FILENAME | SND_LOOP);
}
void playmusic()
{
	system("cls");
	int i;

	do
	{
		display_Pokemon();
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\tSelect Music: " << endl;
		cout << "\t\t\t\t\t\t\t\t\t1.pokemon gotta-catch-em-all" << endl;
		cout << "\t\t\t\t\t\t\t\t\t2.Kai Theme" << endl;
		cout << "\t\t\t\t\t\t\t\t\t3.Oogway Ascends" << endl;
		cout << "\t\t\t\t\t\t\t\t\t4.Rick Roll" << endl;
		cout << "\t\t\t\t\t\t\t\t\t5.Kung Fu Fightning" << endl;
		cout << "\t\t\t\t\t\t\t\t\t6.In the jungle the mighty jungle" << endl;
		cout << "\t\t\t\t\t\t\t\t\t7.Go Back" << endl;
		cout << "\t\t\t\t\t\t\t\t\tOption==> "; cin >> i;
		system("pause");
		system("cls");
		if (i < 1 || i>7)
		{
			cout << "\t\t\t\t\t\t\t\t\t\nInvalid Option Selected: " << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (i == 1)
		{
			std::thread musicThread(music1);
			system("cls");
			main();
		}
		else if (i == 2)
		{
			std::thread musicThread(music2);
			system("cls");
			main();
		}
		else if (i == 3)
		{
			std::thread musicThread(music3);
			system("cls");
			main();
		}
		else if (i == 4)
		{
			std::thread musicThread(music4);
			system("cls");
			main();
		}
		else if (i == 5)
		{
			std::thread musicThread(music5);
			system("cls");
			main();
		}
		else if (i == 6)
		{
			std::thread musicThread(music6);
			system("cls");
			main();
		}
		else if (i == 7)
		{
			system("cls");
			main();
		}

	} while (i < 1 || i>7);

}
void Load_data(pokemon a[20])  // reads data from file 
{
	player p1, p2;
	string temp; // variable used to store raw data before organising it
	int index, index2, turn;
	ifstream fin("PoekmonGame.txt");
	getline(fin, temp);
	if (temp == "Empty")
	{
		system("cls");
		display_Pokemon();
		cout << "\t\t\t\t\t\t\n\nNo Game found to continue." << endl;
		cout << "\t\t\t\t\t\tStarting a New Game: " << endl << endl;
		system("pause");
		fin.close();
		selection(a);
	}
	else
	{
		index = stoi(temp);
		getline(fin, temp);
		index2 = stoi(temp);
		getline(fin, temp);
		turn = stoi(temp);
		getline(fin, temp);
		p1.setName( temp);
		for (int i = 0; i < 2; i++)
		{
			getline(fin, temp);
			p1.P[i].setName(temp);
			getline(fin, temp);
			p1.P[i].setType( temp);
			getline(fin, temp);
			p1.P[i].weak = temp;
			getline(fin, temp);
			p1.P[i].HP = stoi(temp);
			getline(fin, temp);
			p1.P[i].P_atk = temp;
			getline(fin, temp);
			p1.P[i].atkP = stoi(temp);
			getline(fin, temp);
			p1.P[i].E_atk = temp;
			getline(fin, temp);
			p1.P[i].atkE = stoi(temp);
		}
		getline(fin, temp);
		p2.name = temp;
		for (int i = 0; i < 2; i++)
		{
			getline(fin, temp);
			p2.P[i].name = temp;
			getline(fin, temp);
			p2.P[i].type = temp;
			getline(fin, temp);
			p2.P[i].weak = temp;
			getline(fin, temp);
			p2.P[i].HP = stoi(temp);
			getline(fin, temp);
			p2.P[i].P_atk = temp;
			getline(fin, temp);
			p2.P[i].atkP = stoi(temp);
			getline(fin, temp);
			p2.P[i].E_atk = temp;
			getline(fin, temp);
			p2.P[i].atkE = stoi(temp);
		}
		fin.close();
	}
	ofstream fout("PoekmonGame.txt"); // empties the saved data once the data is loaded into the game
	fout << "\t\t\t\t\t\tEmpty" << endl;
	fout.close();
	if (p2.getName() == "CPU")
	{
		PvAI(p1, p2, index, index2, turn);
	}
	else
	{
		PvP(p1, p2, index, index2, turn);
	}
}
void display_Pokemon()
{
	system("color 6");
	cout << "\t\t\t\t\t		                          ,'\\" << endl;
	cout << "\t\t\t\t\t	    _.----.        ____         ,'  _\\   ___    ___     ____" << endl;
	cout << "\t\t\t\t\t	_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`." << endl;
	cout << "\t\t\t\t\t	\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |" << endl;
	cout << "\t\t\t\t\t	 \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |" << endl;
	cout << "\t\t\t\t\t	   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |" << endl;
	cout << "\t\t\t\t\t	    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |" << endl;
	cout << "\t\t\t\t\t	     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |" << endl;
	cout << "\t\t\t\t\t	      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |" << endl;
	cout << "\t\t\t\t\t	       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |" << endl;
	cout << "\t\t\t\t\t	        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |" << endl;
	cout << "\t\t\t\t\t	                                `'                            '-._|" << endl;
}
void selection(pokemon poke[20])
{
	player p1, p2;
	int pokemonselected;
	int choice = 0;// variable used to select option from user
	do
	{
		srand(static_cast<unsigned int>(time(0)));
		system("cls");
		display_Pokemon();
		cout << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t1. Player Vs Player" << endl;
		cout << "\t\t\t\t\t\t\t\t\t2. Player Vs CPU" << endl;
		cout << "\n\t\t\t\t\t\t\t\t\t Option ==> ";
		cin >> choice;
		if (choice < 1 || choice > 2)
		{
			cout << "\t\t\t\t\t\t\t\t\t\nInvalid Option Selected: " << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
		else if (choice == 1)
		{
			system("cls");
			display_Pokemon();
			cout << "\n\n\t\t\t\t\t\t\t\t\tPlayer 1 Enter Name: " << endl;
			cout << "\t\t\t\t\t\t\t\t\t";
			string playerName;
			getline(cin >> ws, playerName);
			p1.setName(playerName);
			cout << endl;
			cout << "\n\n\t\t\t\t\t\t\t\t\tPlayer 2 Enter Name: " << endl;
			cout << "\t\t\t\t\t\t\t\t\t";
			string playerName2;
			getline(cin >> ws, playerName2);
			p2.setName(playerName2); // Corrected this line
			cout << endl;
			system("pause");
			system("cls");
			display_Pokemon_list(poke);
			cout << "\t\t\t\t\t\t\t\t\t" << p1.getName() << " Select your Pokemons: " << endl;
			do
			{
				cout << "\t\t\t\t\t\t\t\t\tFirst Pokemon: ";
				cin >> pokemonselected;
				cout << endl;
				if (pokemonselected < 1 || pokemonselected > 20)
				{
					cout << "\t\t\t\t\t\t\t\t\tInvalid Option Selected try again! " << endl;
				}
			} while (pokemonselected < 1 || pokemonselected > 20);
			p1.P[0] = poke[pokemonselected - 1]; // saves data of first pokemon for player 1
			do
			{
				cout << "\t\t\t\t\t\t\t\t\tSecond Pokemon: ";
				cin >> pokemonselected;
				cout << endl;
				if (pokemonselected < 1 || pokemonselected > 20)
				{
					cout << "\t\t\t\t\t\tInvalid Option Selected try again! " << endl;
				}
			} while (pokemonselected < 1 || pokemonselected > 20);
			p1.P[1] = poke[pokemonselected - 1]; // saves data of second pokemon for player 1
			system("cls");
			display_Pokemon_list(poke);
			cout << "\t\t\t\t\t\t\t\t\t" << p2.getName() << " Select your Pokemons: " << endl;
			do
			{
				cout << "\t\t\t\t\t\t\t\t\tFirst Pokemon: ";
				cin >> pokemonselected;
				cout << endl;
				if (pokemonselected < 1 || pokemonselected > 20)
				{
					cout << "\t\t\t\t\t\t\t\t\tInvalid Option Selected try again! " << endl;
				}
			} while (pokemonselected < 1 || pokemonselected > 20);
			p2.P[0] = poke[pokemonselected - 1]; // saves data of first pokemon for player 2
			do
			{
				cout << "\t\t\t\t\t\t\t\t\tSecond Pokemon: ";
				cin >> pokemonselected;
				cout << endl;
				if (pokemonselected < 1 || pokemonselected > 20)
				{
					cout << "\t\t\t\t\t\t\t\t\tInvalid Option Selected try again! " << endl;
				}
			} while (pokemonselected < 1 || pokemonselected > 20);
			p2.P[1] = poke[pokemonselected - 1]; // saves data of second pokemon for player 2
			system("cls");
			display_Pokemon();
			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\t" << p1.getName() << " is Heads and " << p2.getName() << " is Tails. " << endl; // head and tails 
			int turn = (rand() % 2) + 1;
			if (turn == 1)
			{
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\tIt is Heads." << endl;
				cout << "\t\t\t\t\t\t\t\t\t" << p1.getName() << " won the toss and gets first turn." << endl;
			}
			else
			{
				cout << endl;
				cout << "\t\t\t\t\t\t\t\t\tIt is Tails." << endl;
				cout << "\t\t\t\t\t\t\t\t\t" << p2.getName() << " won the toss and gets first turn." << endl;
			}
			cout << endl;
			system("pause");
			system("cls");
			PvP(p1, p2, 0, 0, turn);
		}
		else if (choice == 2)
		{
			system("cls");
			display_Pokemon();
			cout << "\n\n\t\t\t\t\t\t\t\t\tPlayer 1 Enter Name: " << endl;
			cout << "\t\t\t\t\t\t\t\t\t";
			string playerName;
			getline(cin >> ws, playerName);
			p1.setName(playerName);
			cout << endl;
			p2.setName("CPU");
			system("pause");
			system("cls");
			display_Pokemon_list(poke);
			cout << "\t\t\t\t\t\t\t\t" << p1.getName() << " select your Pokemons: " << endl;
			do
			{
				cout << "\t\t\t\t\t\t\t\tFirst Pokemon: " << endl;
				cout << "\t\t\t\t\t\t\t\t"; cin >> pokemonselected;
				if (pokemonselected < 1 || pokemonselected > 20)
				{
					cout << "\t\t\t\t\t\t\t\tInvalid Option Selected try again! " << endl;
				}
			} while (pokemonselected < 1 || pokemonselected > 20);
			p1.P[0] = poke[pokemonselected - 1]; // saves data of first pokemon for player 1
			do
			{
				cout << "\t\t\t\t\t\t\t\tSecond Pokemon: " << endl;
				cout << "\t\t\t\t\t\t\t\t"; cin >> pokemonselected;
				if (pokemonselected < 1 || pokemonselected > 20)
				{
					cout << "\t\t\t\t\t\t\t\tInvalid Option Selected try again! " << endl;
				}
			} while (pokemonselected < 1 || pokemonselected > 20);
			p1.P[1] = poke[pokemonselected - 1]; // saves data of second pokemon for player 1
			system("cls");
			// CPU selects Pokemons based on weakness of players pokemon
			display_Pokemon_list(poke);
			for (int i = 0; i < 20; i = i + 4)
			{
				if (p1.P[0].getWeak() == poke[i].getType()) // finds weakness of players pokemon and selects that pokemon
				{
					int x = rand() % 4;
					p2.P[0] = poke[i + x]; // from the element that is stronger it decides randomly to pick one of those pokemons
					break;
				}
			}

			for (int i = 0; i < 20; i = i + 4)
			{
				if (p1.P[1].getWeak() == poke[i].getType()) // finds weakness of players pokemon and selects that pokemon
				{
					int x = rand() % 4;
					p2.P[1] = poke[i + x]; // from the element that is stronger it decides randomly to pick one of those pokemons
					break;
				}
			}
			cout << "\t\t\t\t\t\t\t\tCPU choose " << p2.P[0].getName() << " and " << p2.P[1].getName() << endl;
			cout << endl;
			system("pause");
			system("cls");
			PvAI(p1, p2, 0, 0, 1); // calls function for Player versus AI 
		}
	} while (choice < 1 || choice > 2);
}
void display_Pokemon_list(pokemon a[20]) // just display the list of the pokemons
{
	display_Pokemon();
	for (int i = 0; i < 17; i++)
	{
		if (i == 0)
		{
			cout << "\n\t\t\t\t\t\t\t\tFire Type:\t\t\tWater Type:" << endl;

		}
		else if (i == 8)
		{
			cout << "\n\t\t\t\t\t\t\t\tElectric Type:\t\t\tRock Type:" << endl;
		}
		else if (i == 16)
		{
			cout << "\n\t\t\t\t\t\t\t\tGrass Type:" << endl;
		}
		if (i == 0)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << "\t\t\t\t\t\t\t\t" << j + 1 << ". " << a[j].getName() << "\t\t\t" << j + 5 << ". " << a[j + 4].getName() << endl;
			}
		}
		else if (i == 8)
		{
			for (int j = 8; j < 12; j++)
			{
				cout << "\t\t\t\t\t\t\t\t" << j + 1 << ". " << a[j].getName() << "\t\t\t" << j + 5 << ". " << a[j + 4].getName() << endl;
			}
		}
		else if (i == 16)
		{
			for (int j = 15; i < 20; i++)
			{
				cout << "\t\t\t\t\t\t\t\t" << i + 1 << ". " << a[i].getName() << endl;
			}
		}
	}

	cout << endl << endl << endl;
}
void PvP(player p1, player p2, int index, int index2, int turn)
{
	int choice; // variable to select options from player and a variable to store who wins
	bool win1 = false; // boolean variable to decide when the game ends and Player 1 has won
	bool win2 = false; // boolean variable to decide when the game ends and Player 2 has won
	do
	{
		system("cls");
		display_Pokemon();
		cout << endl << endl;
		cout << "\t\t\t\t\t\t\t" << setw(15) << p1.getName() << ": " << setw(25) << p2.getName() << ": " << endl;
		cout << "\t\t\t\t\t\t\t" << setw(15) << p1.P[index].getName() << setw(25) << p2.P[index2].getName() << endl;
		cout << "\t\t\t\t\t\t\t" << setw(15) << p1.P[index].getHP() << setw(25) << p2.P[index2].getHP() << endl;
		cout << endl << endl << endl;
		// player 1 options
		if (turn % 2 == 1)
		{
			cout << "\t\t\t\t\t\t\t\t" << p1.getName() << "'s Turn: \n";
			cout << "\t\t\t\t\t\t\t\t1. Attack\n";
			cout << "\t\t\t\t\t\t\t\t2. Switch\n";
			cout << "\t\t\t\t\t\t\t\t3. Save and Quite" << endl;
			do
			{
				cout << "\t\t\t\t\t\t\t\tChoice ==> ";
				cin >> choice;
				if (choice < 1 || choice>3)
				{
					cout << "\n\t\t\t\t\t\t\t\tInvalid Option Selected: " << endl;
				}
				else if (choice == 1)
				{
					int newHP = p2.P[index2].getHP();
					attack(p1.P[index], newHP, p2.P[index2].getWeak()); // calls function that carries out the attack
					p2.P[index2].setHP(newHP); // calls function that carries out the attack
					if (p2.P[index2].getHP() <= 0)
					{
						index2 = swap(index2);
						if (p2.P[index2].getHP() <= 0) // checks if the second pokemon is dead too or not
						{
							win1 = true;
						}
					}
				}
				else if (choice == 2)
				{
					index = swap(index); // switch monsters if player chooses to 
					if (p1.P[index].getHP() <= 0) // if pokemon is already dead then shifts to attack automatically and switches back to pokemon that is alive
					{
						cout << "\t\t\t\t\t\t\t\t" << p1.P[index].getName() << " has been defeated." << endl;
						cout << "\t\t\t\t\t\t\t\tSwitching to Attack. " << endl;
						index = swap(index);
						int newHP = p2.P[index2].getHP();
						attack(p1.P[index], newHP, p2.P[index2].getType());
						p2.P[index2].setHP(newHP);
						if (p2.P[index2].getHP() <= 0)
						{
							index2 = swap(index2);
							if (p2.P[index2].getHP() <= 0) // checks if the second pokemon is dead too or not
							{
								win1 = true;
							}
						}
					}
				}
				else if (choice == 3)
				{
					save_data(p1, p2, index, index2, turn);// function that inputs data onto a file 
				}
			} while (choice < 1 || choice>3);
			turn++;
		}
		// player 2 options 
		else if (turn % 2 == 0)
		{
			cout << "\t\t\t\t\t\t\t\t" << p2.getName()<< "'s Turn: \n";
			cout << "\t\t\t\t\t\t\t\t1. Attack\n";
			cout << "\t\t\t\t\t\t\t\t2. Switch\n";
			cout << "\t\t\t\t\t\t\t\t3. Save and Quite" << endl;
			do
			{
				cout << "\t\t\t\t\t\t\t\tChoice ==> ";
				cin >> choice;
				if (choice < 1 || choice>3)
				{
					cout << "\n\t\t\t\t\t\t\t\tInvalid Option Selected: " << endl;
				}
				else if (choice == 1)
				{
					int newHP = p1.P[index].getHP();
					attack(p2.P[index2], newHP, p1.P[index].getWeak()); // calls function that carries out the attack
					p1.P[index].setHP(newHP); // update the HP after the attack// calls function that carries out the attack
					if (p1.P[index].getHP() <= 0)
					{
						index = swap(index);
						if (p1.P[index].getHP() <= 0) // checks if the second pokemon is dead too or not
						{
							win2 = true;
						}
					}
				}
				else if (choice == 2)
				{
					index2 = swap(index2); // switch monsters if player chooses to 
					if (p2.P[index2].getHP() <= 0) // if pokemon is already dead then shifts to attack automatically and switches back to pokemon that is alive
					{
						cout << "\t\t\t\t\t\t\t\t" << p2.P[index2].getName() << " has been defeated." << endl;
						cout << "\t\t\t\t\t\t\t\tSwitching to Attack. " << endl;
						index2 = swap(index2);
						int newHP = p1.P[index].getHP();
						attack(p2.P[index2], newHP, p1.P[index].getWeak()); // calls function that carries out the attack
						p1.P[index].setHP(newHP); // update the HP after the attack
						if (p1.P[index].getHP() <= 0)
						{
							index = swap(index);
							if (p1.P[index].getHP() <= 0) // checks if the second pokemon is dead too or not
							{
								win2 = true;
							}
						}
					}
				}
				else if (choice == 3)
				{
					save_data(p1, p2, index, index2, turn);// function that inputs data onto a file
				}
			} while (choice < 1 || choice>3);
			turn++;
		}
	} while (!win1 && !win2); // reapeats loop till someone wins the match 
	if (win1)
	{
		system("cls");
		display_Pokemon();
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t" << p1.getName() << " has won the battle. " << endl;
		cout << endl;
		system("pause");
	}
	if (win2)
	{
		system("cls");
		display_Pokemon();
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t\t" << p2.name << " has won the battle. " << endl;
		cout << endl;
		system("pause");
	}
	main();
}
void save_data(player p1, player p2, int a, int b, int turn)
{
	ofstream fout("PoekmonGame.txt");
	fout << a << endl;
	fout << b << endl;
	fout << turn << endl;
	fout << p1.getName() << endl;
	for (int i = 0; i < 2; i++)
	{
		fout << p1.P[i].getName() << endl;
		fout << p1.P[i].getType() << endl;
		fout << p1.P[i].getWeak() << endl;
		fout << p1.P[i].getHP() << endl;
		fout << p1.P[i].getP_atk() << endl;
		fout << p1.P[i].getAtkP() << endl;
		fout << p1.P[i].getE_atk() << endl;
		fout << p1.P[i].getAtkE() << endl;
	}
	fout << p2.getName() << endl;
	for (int i = 0; i < 2; i++)
	{
		fout << p2.P[i].getName() << endl;
		fout << p2.P[i].getType() << endl;
		fout << p2.P[i].getWeak() << endl;
		fout << p2.P[i].getHP() << endl;
		fout << p2.P[i].getP_atk() << endl;
		fout << p2.P[i].getAtkP() << endl;
		fout << p2.P[i].getE_atk()<< endl;
		fout << p2.P[i].getAtkE() << endl;
	}
	fout.close();
	exit(0);
}
void attack(pokemon p, int& Health, string weakness)
{
	int choice; // choice from user to use which attack
	cout << endl;
	cout << "\t\t\t\t\t\t\tPokemon in play: " << p.getName()<< endl;
	cout << "\t\t\t\t\t\t\tAvailable Attacks: " << endl;
	cout << "\t\t\t\t\t\t\t1. Physical Attack ==> " << p.getP_atk() << "\t\t\t" << p.getAtkP() << endl;
	cout << "\t\t\t\t\t\t\t2. Elemental Attack ==> " << p.getE_atk() << "\t\t\t" << p.getAtkE() << endl;
	do {
		cout << "\t\t\t\t\t\t\t\tChoice ==> ";
		cin >> choice;
		if (choice < 1 || choice>2)
		{
			cout << "\t\t\t\t\t\t\t\tInvalid otion selected, try again!" << endl;
		}
	} while (choice < 1 || choice>2);
	if (choice == 1)
	{
		Health = Health - p.getAtkP();
	}
	else if (choice == 2)
	{
		if (p.getType() == weakness) // checks if the element is stronger 
		{
			Health = Health - (p.getAtkE() * 2);
		}
		else
		{
			Health = Health - p.getAtkE();
		}
	}
}
int swap(int a)
{
	if (a == 0)
	{
		a = 1;
	}
	else
	{
		a = 0;
	}
	return a;   // changes pokemon if one dies basically
}
void PvAI(player p, player CPU, int index, int index2, int turn)
{
	int choice; // variable to select options from player and a variable to store who wins
	bool win1 = false; // boolean variable to decide when the game ends and Player 1 has won
	bool win2 = false; // boolean variable to decide when the game ends and Player 2 has won
	do
	{
		system("cls");
		display_Pokemon();
		cout << endl << endl;
		cout << "\t\t\t\t\t\t\t" << setw(15) << p.getName() << ": " << setw(25) << CPU.getName() << ": " << endl;
		cout << "\t\t\t\t\t\t\t" << setw(15) << p.P[index].getName() << setw(25) << CPU.P[index2].getName() << endl;
		cout << "\t\t\t\t\t\t\t" << setw(15) << p.P[index].getHP() << setw(25) << CPU.P[index2].getHP() << endl;
		cout << endl << endl << endl;
		// player 1 options
		if (turn % 2 == 1)
		{
			cout << "\t\t\t\t\t\t\t\t" << p.getName() << "'s Turn: \n";
			cout << "\t\t\t\t\t\t\t\t1. Attack\n";
			cout << "\t\t\t\t\t\t\t\t2. Switch\n";
			cout << "\t\t\t\t\t\t\t\t3. Save and Quite" << endl;
			do
			{
				cout << "\t\t\t\t\t\t\t\tChoice ==> ";
				cin >> choice;
				if (choice < 1 || choice>3)
				{
					cout << "\n\t\t\t\t\t\t\t\tInvalid Option Selected: " << endl;
				}
				else if (choice == 1)
				{
					int newHP = CPU.P[index2].getHP(); // Line to add
					attack(p.P[index], newHP, CPU.P[index2].getWeak()); // Line to modify
					CPU.P[index2].setHP(newHP); // Line to add
					if (CPU.P[index2].getHP() <= 0)
					{
						index2 = swap(index2);
						if (CPU.P[index2].getHP() <= 0) // checks if the second pokemon is dead too or not
						{
							win1 = true;
						}
					}
				}
				else if (choice == 2)
				{
					index = swap(index); // switch monsters if player chooses to 
					if (p.P[index].getHP() <= 0) // if pokemon is already dead then shifts to attack automatically and switches back to pokemon that is alive
					{
						cout << "\t\t\t\t\t\t\t\t" << p.P[index].getName() << " has been defeated." << endl;
						cout << "\t\t\t\t\t\t\t\tSwitching to Attack. " << endl;
						index = swap(index);
						int newHP = CPU.P[index2].getHP(); // Line to add
						attack(p.P[index], newHP, CPU.P[index2].getWeak()); // Line to modify
						CPU.P[index2].setHP(newHP); // Line to add
						if (CPU.P[index2].getHP() <= 0)
						{
							index2 = swap(index2);
							if (CPU.P[index2].getHP() <= 0) // checks if the second pokemon is dead too or not
							{
								win1 = true;
							}
						}
					}
				}
				else if (choice == 3)
				{
					save_data(p, CPU, index, index2, turn);// function that inputs data onto a file 
				}
			} while (choice < 1 || choice>3);
			turn++;
		}
		// CPU AI Algorithm 
		else if (turn % 2 == 0)
		{
			if (p.P[index].getWeak() == CPU.P[index2].getType())
			{
				int newHP = p.P[index].getHP() - CPU.P[index2].getAtkE() * 2;
				p.P[index].setHP(newHP);
				cout << "\n\t\t\t\t\t\t\t\tCPU choose " << CPU.P[index2].getE_atk() << " and dealt " << CPU.P[index2].getAtkE() * 2 << " damage to " << p.P[index].getName() << endl;
				if (p.P[index].getHP() <= 0)
				{
					index = swap(index);
					if (p.P[index].getHP() <= 0) // checks if the second pokemon is dead too or not
					{
						win2 = true;
					}
				}
			}
			else
			{
				index2 = swap(index2);
				if (CPU.P[index2].getHP() <= 0)
				{
					index2 = swap(index2);
					if (p.P[index].getWeak() == CPU.P[index2].getType()) // checks if swaped pokemon is stronger or not 
					{
						p.P[index].setHP(p.P[index].getHP() - (2 * CPU.P[index2].getAtkE()));
						cout << "\n\t\t\t\t\t\t\t\tCPU choose " << CPU.P[index2].getE_atk() << " and dealt " << 2 * CPU.P[index2].getAtkE() << " damage to " << p.P[index].getName() << endl;
						if (p.P[index].getHP() <= 0)
						{
							index = swap(index);
							if (p.P[index].getHP() <= 0) // checks if the second pokemon is dead too or not
							{
								win2 = true;
							}
						}
					}
					else // checks weather physcial attack is stronger or elemental
					{
						if (CPU.P[index2].getAtkE() > CPU.P[index2].getAtkP())
						{
							p.P[index].setHP(p.P[index].getHP() - CPU.P[index2].getAtkE());
							cout << "\n\t\t\t\t\t\t\t\tCPU choose " << CPU.P[index2].getE_atk() << " and dealt " << CPU.P[index2].getAtkE() << " damage to " << p.P[index].getName() << endl;
							if (p.P[index].getHP() <= 0)
							{
								index = swap(index);
								if (p.P[index].getHP() <= 0) // checks if the second pokemon is dead too or not
								{
									win2 = true;
								}
							}
						}
						else
						{
							p.P[index].setHP(p.P[index].getHP() - CPU.P[index2].getAtkP());
							cout << "\n\t\t\t\t\t\t\t\tCPU choose " << CPU.P[index2].getP_atk() << " and dealt " << CPU.P[index2].getAtkP() << " damage to " << p.P[index].getName() << endl;
							if (p.P[index].getHP() <= 0)
							{
								index = swap(index);
								if (p.P[index].getHP() <= 0) // checks if the second pokemon is dead too or not
								{
									win2 = true;
								}
							}
						}
					}
				}
				else
				{
					cout << endl;
					cout << "\t\t\t\t\t\t\t\tCPU switched Pokemon from " << CPU.P[swap(index2)].getName() << " to " << CPU.P[index2].getName() << endl;
					cout << endl;
				}
			}
			turn++;
			cout << endl;
			system("pause");
		}
	} while (!win1 && !win2); // reapeats loop till someone wins the match 
	if (win1)
	{
		system("cls");
		display_Pokemon();
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t" << p.name << " has won the battle. " << endl;
		cout << endl;
		system("pause");
	}
	if (win2)
	{
		system("cls");
		display_Pokemon();
		cout << endl;
		cout << "\t\t\t\t\t\t\t\t" << CPU.name << " has won the battle. " << endl;
		cout << endl;
		system("pause");
	}
	main();
}



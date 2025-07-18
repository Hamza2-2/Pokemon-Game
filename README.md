# Pokémon Game 🕹️
A terminal-based Pokémon battle game implemented in **C++**, offering both **Player vs Player (PvP)** and **Player vs AI (PvAI)** modes. Choose your Pokémon, unleash attacks, and battle to victory using classic turn-based mechanics!

## 🔥 Game Modes

- **Player vs Player (PvP):** Two players battle each other by selecting their Pokémon and taking turns.
- **Player vs AI (PvAI):** Battle against a computer-controlled opponent with basic decision-making logic.


## Features 🎮

- Turn-based battle system
- Multiple Pokémon with unique stats
- Attack, defense, HP mechanics
- Interactive terminal input/output
- Object-Oriented structure for scalability
- Randomized AI attack selection in PvAI mode


## Game Preview 📸
![image](https://github.com/user-attachments/assets/231075a2-228d-455a-922d-78a76edaf97f)
![image](https://github.com/user-attachments/assets/4b12480b-ffd7-4308-9e32-664a5637422c)
![image](https://github.com/user-attachments/assets/68788c9c-38b7-43a3-903f-76f7c1aa0d17)
![image](https://github.com/user-attachments/assets/a3761357-b1e3-4aee-bf37-3c108fad5310)

## Technologies Used 🧪

- C++
- Standard Template Library (STL)
- Console-based I/O
- OOP principles


## Getting Started 🚀

### Prerequisites

Make sure you have a C++ compiler installed. Example: `g++`, `clang++`, or use Visual Studio / Code::Blocks.

### Compilation & Run (Using g++)

``` 
g++ -o pokemon_game main.cpp pokemon.cpp
```

Make sure all .cpp and .h files are in the same directory or properly linked.

### File Structure 📁

Pokemon-Game/
│

├── pokemon.cpp              # Main game loop and menu

└── README.md             # Project documentation

## How to Play 🎯

- Select Mode: Choose between PvP or PvAI.

- Pick Pokémon: Each player (or AI) selects a Pokémon.

- Battle Turns: Players take turns attacking until one Pokémon's HP reaches 0.

- Victory: The last standing Pokémon wins the match.

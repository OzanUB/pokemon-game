// File: proj2.cpp
// Project: CMSC 202 Project 2, Fall 2016
// Author: Ozan Ulug-Berter
// Date: 10/11/2016
// Section 3
// Email: gl95172@umbc.edu

// Description: A simple game based off of the famous Pokemon franchise. This main 
// cpp file implments a number of classes and reads from text files. The focus of 
// of this project was to incorporate concepts of vectors along with classes and objects

#include "proj2.h"

int main () {
  srand(10);
  vector<Pokemon> pokeDex;
  vector<MyPokemon> myCollection;
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu (pokeDex, myCollection);
  return 0;
}

// Name: getPokeDex(vector)
// Pre-condition: When the application loads, loads the complete pokemon list from file
// Post-condition: Returns a populated pokeDex vector
void getPokeDex(vector<Pokemon> & pokeDex){
  int num = 0;
  string name = "";
  int min = 0;
  int max = 0;
  int rare = 0;
  
  fstream inputStream;
  inputStream.open(POKEDEX); //opens the pokedex.txt file.
  
  for (int i=0; i < POKECOUNT; i++){ //POKECOUNT is global constant for 151(#
    
    inputStream >> num >> name >> min >> max >> rare;
    
    Pokemon newPoke(num, name, min, max, rare); //New object that creates a new pokemon
    pokeDex.push_back(newPoke); // populates the vector
  }
  inputStream.close();
}

// Name: getMyCollection
// Pre-condition: When the application loads, loads the user's pokemon collection from file
// Post-condition: Returns a populated myCollection vector
void getMyCollection(vector<MyPokemon> & myCollection){
  int num = 0;
  string name = "";
  int cP = 0;
  int hP = 0;
  int rare = 0;
  
  fstream inputStream;
  inputStream.open(MYCOLLECTION); //MYCOLLECTION is global constant for myCollection.txt
  
  while (inputStream >> num){ //while taking in a number...
    inputStream >> name >> cP >> hP >> rare;
    MyPokemon myPoke(num, name, cP, hP, rare); //object to put into a vector
    myCollection.push_back(myPoke); //populates vector
  }
  inputStream.close();
}

// Name: printPokeDex (vector)
// Pre-condition: Takes in populated pokeDex vector
// Post-condition: Prints num and name of each Pokemon in vector
void printPokeDex(vector <Pokemon> & pokeDex){
  for (unsigned int i = 0; i < pokeDex.size(); i++){
    cout << pokeDex[i].GetNum() <<  "\t";
    cout << pokeDex[i].GetName();
    cout << endl;
  }
}

// Name: printMyCollection (vector)
// Pre-condition: Takes in populated myCollection vector
// Post-condition: Prints num, name, CP, HP, rarity of each pokemon in vector
void printMyCollection(vector <MyPokemon> & myCollection){
  for (unsigned int i = 0; i < myCollection.size(); i++){
    cout << endl;
    cout << left << i << setw(4) << ". "; //makes a numbered list eg 1.
    cout << setw(8) <<  myCollection[i].GetNum() << "\t";
    cout << setw(12) << myCollection[i].GetName() << "\t" ;
    cout << setw(7) << myCollection[i].GetCP() << "\t";
    cout << setw(7) << myCollection[i].GetHP() << "\t";
    cout << myCollection[i].GetRarity();
    cout << endl;
  }  
  cout << "\n";
}

// Name: catchPokemon
// Pre-condition: Takes in the current user's collection and the pokeDex vector
// Post-condition: Prompts user for rarity (1-5) user would like to capture
//                 Based on rarity (1=65%, 2=45%, 3=25%, 4=10%, 5=1%) tries to find a random
//                 Pokemon based on that rarity.
//                 If a Pokemon is found, calls foundPokemon
void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  
  cout << "What type of Pokemon would you like to try and catch?:" << endl;
  cout << "1. Very Common (Very High Probability)"<< endl;
  cout << "2. Common (High Probability)" << endl;
  cout << "3. Uncommon (Normal Probability)" << endl;
  cout << "4. Rare (Low Probability)" << endl;
  cout << "5. Ultra Rare (Extremely Low Probability)" << endl;
  cout << "\n";
  
  int rareChoice = 0; //variable that chooses a rarity to search for
  
  cin >> rareChoice;
  srand(time(NULL)); //seeds rand function with the value of time
  
  int randPerc; //variable for a random percentage
  randPerc = rand() % 100 + 1; 
  int probability;
  
  if (rareChoice > 0 && rareChoice < 6) { 
    cout << "You start your search..." << endl;
    switch (rareChoice){
    case 1: //Very Common
      probability = 65; 
      if (randPerc <= probability) {
	foundPokemon(rareChoice, pokeDex, myCollection);
      }
      else{
	cout << "You found nothing." << endl;
      }
      break;
    case 2: //Common
      probability = 45; 
      if (randPerc <= probability){
	foundPokemon(rareChoice, pokeDex, myCollection);
      }
      else{
	cout << "You found nothing." << endl;
      }
      break;
    case 3: //Uncommon
      probability = 25;
      if (randPerc <= probability){
	foundPokemon(rareChoice, pokeDex, myCollection);
      }
      else{
	cout << "You found nothing." << endl;
      }
      break;
    case 4://Rare
      probability = 10; 
      if (randPerc <= probability){
	foundPokemon(rareChoice, pokeDex, myCollection);
      }
      else{
	cout << "You found nothing." << endl;
      }
      break;
    case 5://Ultra rare
      probability = 1; // change this back to 1
      if (randPerc <= probability){
	foundPokemon(rareChoice, pokeDex, myCollection);
      }
      else{
	cout << "You found nothing." << endl;
      }
      break;
    }  
  }
  
}

// Name: foundPokemon (rarity, vector pokeDex, vector myCollection)
// Pre-condition: After a Pokemon is found, rarity is passed to this function
// Post-condition: Using rarity, the pokeDex is randomly searched for a matching rarity
//                 After an appropriate Pokemon is found
//                 Adds new Pokemon to user's collection
void foundPokemon(int rarity, vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection ){
  int randPoke;
  
  do {
    srand(time(NULL));
    randPoke = rand() % (POKECOUNT + 1); //creates random number to index a pokemon from Dex    
  }
  while (pokeDex[randPoke].GetRarity()!= rarity);{ //Makes sure to find a pokemon with correct rarity
    cout << "Congrats! You found a " << pokeDex[randPoke].GetName()<< endl;
  }
  int minCP = pokeDex[randPoke].GetCPMin();
  int maxCP = pokeDex[randPoke].GetCPMax();
  int randCP = rand() % maxCP + minCP; //creates a random CP value within specified CP range
  int randHP = randCP * .1 ; //HP is 10% of given CP
  
  MyPokemon caughtPoke = MyPokemon(randPoke+1, pokeDex[randPoke].GetName(),randCP,randHP, pokeDex[randPoke].GetRarity());
  myCollection.push_back(caughtPoke); //Adds caught pokemon to myCollection vectr
}

// Name: mainMenu
// Pre-condition: Takes in vector pokeDex and vector myCollection
// Post-condition: Calls a variety of functions based on user
void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0;
  bool isExit = 0;
  do {
    do {
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cin >> option;
    }while(option < 1 || option > 6);
    
    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);    
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}

// Name: battlePokemon(vector pokeDex, vector myCollection)
// Pre-condition: Takes in both pokeDex and myCollection. Randomly chooses an enemy
//                Sets enemy CP as random number between minCP and maxCP
// Post-condition: Says if battle is won or lost - returns to mainMenu
void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  printMyCollection(myCollection);
  srand(time(NULL)); //random function with time as its seed
  int randPokemon = rand() % (POKECOUNT + 1); //a random number that indicates the pokemon 1-151
  int minCP = pokeDex[randPokemon].GetCPMin();
  int maxCP = pokeDex[randPokemon].GetCPMax();
  int randCP = rand() % maxCP + minCP; //random CP between max and min range
  int partyChoice = 0; //choice from myCollection
  int size =  myCollection.size(); //signed variable 
  
  cout << "You are going to fight a " << pokeDex[randPokemon].GetName()<< endl;
  cout << "The enemy has a CP of " << randCP << endl;
  
  cout << "Which of your Pokemon would you like to use?:" << endl;
  cin >> partyChoice;
  if (partyChoice < size){ //if the choice is in the vector myCollection
    if (myCollection[partyChoice].GetCP() > randCP){
      cout << "You Won!" << endl;
    }
    if (myCollection[partyChoice].GetCP() < randCP){
      cout << "You were defeated by the enemy" << endl;
    }
    
  }
  if (partyChoice >= size){
    cout << "You didn't select a vaild pokemon from your party" << endl;
  }
  if (size == 0){
    cout << "You do not have any Pokemon to fight with." << endl;
  }
}
// Name: trainPokemon(vector pokeDex, vector myCollection)
// Pre-condition: Takes in both pokeDex and myCollection
// Post-condition: Calls Train member function that increases CP by 10. Updates myCollection
void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  cout << "Which of your Pokemon would you like to train?:" << endl;
  printMyCollection(myCollection);
  int pokeChoice = 0;
  cin >> pokeChoice;
  int size = myCollection.size(); //signed variable
  
  if (pokeChoice < size  && pokeChoice >= 0){
    MyPokemon trainPoke = myCollection[pokeChoice];
    int pokeNum = trainPoke.GetNum();
    int maxCp = pokeDex[pokeNum-1].GetCPMax(); //gets max cp value from pokedex
    if (maxCp >= (myCollection[pokeChoice].GetCP() + 10)){ //makes sure not to train above max cp
      myCollection[pokeChoice].Train();
    }
    else { //if the CP of pokemon is less than max but greater than the max - 10, then set CP to max CP
      myCollection[pokeChoice].SetCP(maxCp);
    }
    
    cout << "Your " << myCollection[pokeChoice].GetName() << " has a new CP of " << myCollection[pokeChoice].GetCP() << endl;
  }
  else{
    cout << "You did not select a Pokemon from your party" << endl;
  } 
}



// Name: exitPokemon
// Pre-condition: From main menu, user selects 6
// Post-condition: Calls saveMyCollection and exits application
void exitPokemon(vector<MyPokemon> & myCollection){
  saveMyCollection(myCollection);
}

// Name: saveMyCollection(vector)
// Pre-condition: Takes in vector of user collection of Pokemon
// Post-condition: Saves a file with each Pokemon with number, name, CP, HP, rarity
void saveMyCollection(vector<MyPokemon> & myCollection){
  ofstream outputStream;
  outputStream.open(MYCOLLECTION);
  
  for (unsigned int i = 0; i < myCollection.size(); i++){ //iterates through vector
    outputStream << myCollection[i].GetNum() << " ";    //
    outputStream << myCollection[i].GetName() << " ";   //updates values in myCollection
    outputStream << myCollection[i].GetCP() << " ";     //in the text file
    outputStream << myCollection[i].GetHP() << " ";     //
    outputStream << myCollection[i].GetRarity() << endl;//
  }
  outputStream.close();
  cout << "File Saved." << endl << "Thank you for playing UMBC Pokemon!" << endl;;
}

// File: proj2.cpp
// Project: CMSC 202 Project 2, Fall 2016
// Author: Ozan Ulug-Berter
// Date: 10/11/2016
// Section 3
// Email: gl95172@umbc.edu

//Description: This is the class definition for the MyPokemon.cpp file and allows it to be
//implemented in the proj2.cpp so Pokemon objects can be created.

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class MyPokemon{
 public:
  //Constructors
  MyPokemon();
  MyPokemon(int num, string name, int cp, int hp, int rarity);

  //Accessors
  int GetCP();
  int GetHP();
  int GetRarity();
  string GetName();
  int GetNum();

  //Mutators
  void SetRarity(int newRarity);
  void SetName(string newName);
  void SetCP(int newCP);
  void SetHP(int newHP);

  //Member Functions
  void Train();

 private:
  int m_Num;
  string m_Name;
  int m_CP;
  int m_HP;
  int m_Rarity;
};

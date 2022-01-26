// File: proj2.cpp
// Project: CMSC 202 Project 2, Fall 2016
// Author: Ozan Ulug-Berter
// Date: 10/11/2016
// Section 3
// Email: gl95172@umbc.edu

//Description: This is the class definition for the Pokemon.cpp file and allows it to be
//implemented in the proj2.cpp so Pokemon objects can be created.
 
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Pokemon{
 public:
  //Constructors
  Pokemon();
  Pokemon(int num, string name, int cpMin, int cpMax, int rarity);
  
  //Accessors
  int GetCPMin();
  int GetCPMax();
  int GetRarity();
  string GetName();
  int GetNum();
  
  //Mutators
  void SetRarity(int newRarity);
  void SetName(string newName);
  void SetCP(int newCP);
  
 private:
  int m_Num;
  string m_Name;
  int m_MinCP;
  int m_MaxCP;
  int m_Rarity;
};

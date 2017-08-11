// Fill out your copyright notice in the Description page of Project Settings.
/*
This class is the holder of all of the data for the game. The UGameInstance class is able to use data across multiple levels.
In our case, we're using it as a singleton class to hold the array representing the playing fields. Every other class (walls, eaters, pellets, etc)
is able to access it to see what's on the playing field.
*/
#pragma once

#include <array>
#include <string>

class ANormalFoodPellet;

class FieldData
{
private:
  FieldData(const FieldData &);
  FieldData & operator=(const FieldData &);

public:
  enum class Item { EMPTY, EATER, WALL, PELLET, BONUS_PELLET };
  class Cell {
  public:
    std::pair<size_t, size_t> coord;
    Item item = Item::PELLET;

    void clear_object() {
      /// TODO
      //unrealObject->Destroy();
      unrealObject = nullptr;
    }

    void set_object(AActor * const ueObj) {
      clear_object();
      unrealObject = ueObj;
    }

    void take_object(Cell &rhs) {
      if (this != &rhs) {
        clear_object();
        unrealObject = rhs.unrealObject;
        rhs.unrealObject = nullptr;
      }
    }

  private:
    AActor * unrealObject = nullptr;
  };

  FieldData();

  static FieldData & get();

  void reset();

  static const size_t grid_size = 15;
  static const int render_scaling_factor = 200;

  std::array<std::array<Cell, grid_size>, grid_size> cells;
  std::pair<int, int> eater_pos;
  int eater_score = 0;

private:
  bool bStartup = true;
};

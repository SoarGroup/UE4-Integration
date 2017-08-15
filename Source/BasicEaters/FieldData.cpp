/// Fill out your copyright notice in the Description page of Project Settings.

#include "FieldData.h"

#include "Engine/World.h"

FieldData::FieldData() {
  for(size_t i = 0; i != grid_size; ++i) {
    for(size_t j = 0; j != grid_size; ++j)
      cells[i][j].coord = std::make_pair(i, j);
  }
}

FieldData & FieldData::get() {
  static FieldData fieldData;
  return fieldData;
}

void FieldData::reset() {
  cells = std::array<std::array<Cell, grid_size>, grid_size>();
  eater_pos = std::pair<int, int>();
  eater_score = 0;
}

void FieldData::increaseScore(int amount)
{
	eater_score += amount;
}

int FieldData::getScore()
{
	return eater_score;
}

void FieldData::resetScore()
{
	eater_score = 0;
}









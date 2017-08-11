/// Fill out your copyright notice in the Description page of Project Settings.

#include "FieldData.h"

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

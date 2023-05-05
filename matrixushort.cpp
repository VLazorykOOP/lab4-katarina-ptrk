#include "matrixushort.h"
#include "vectorushort.h"
#include <string.h> //memcpy

int MatrixUShort::num_matrix = 0;

MatrixUShort::MatrixUShort() {
  UShortArray = nullptr;
  rows = 0;
  cols = 0;
  codeError = 0;
  num_matrix++;
}

MatrixUShort::MatrixUShort(ui size) {
  UShortArray = new VectorUShort[size];
  for (ui i = 0; i < size; i++) {
    UShortArray[i] = VectorUShort(size);
  }
  rows = size;
  cols = size;
  codeError = 0;
  num_matrix++;
}

MatrixUShort::MatrixUShort(ui rows_, ui cols_) {
  UShortArray = new VectorUShort[rows_];
  for (ui i = 0; i < rows_; i++) {
    UShortArray[i] = VectorUShort(cols_);
  }
  rows = rows_;
  cols = cols_;

  codeError = 0;
  num_matrix++;
}

MatrixUShort::MatrixUShort(ui rows_, ui cols_, unsigned short value_) {
  UShortArray = new VectorUShort[cols_];
  for (ui i = 0; i < rows_; i++) {
    UShortArray[i] = VectorUShort(cols_, value_);
  }
  rows = rows_;
  cols = cols_;
  codeError = 0;
  num_matrix++;
}

MatrixUShort::MatrixUShort(const MatrixUShort &input) {
  UShortArray = new VectorUShort[input.rows];
  for (ui i = 0; i < input.rows; i++) {
    UShortArray[i] = input.UShortArray[i];
  }
  rows = input.rows;
  cols = input.cols;
  codeError = 0;
  num_matrix++;
}

MatrixUShort::~MatrixUShort() {
  delete[] UShortArray;
  num_matrix--;
}

std::ostream &operator<<(std::ostream &os, const MatrixUShort &out) {
  for (ui i = 0; i < out.rows; i++, os << std::endl) {
    for (ui z = 0; z < out.cols; z++)
      os << out.UShortArray[i][z] << " ";
  }
  return os;
}

std::istream &operator>>(std::istream &is, const MatrixUShort &in) {
  for (ui i = 0; i < in.rows; i++) {
    for (ui z = 0; z < in.cols; z++)
      is >> in.UShortArray[i][z];
  }
  return is;
}

int MatrixUShort::getRows() const { return rows; }

int MatrixUShort::getCols() const { return cols; }

int MatrixUShort::getCodeError() const { return codeError; }

MatrixUShort MatrixUShort::operator++(int) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] += 1;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator--(int) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] -= 1;
    }
  }
  return *this;
}

bool MatrixUShort::operator!() {
  if (rows != 0 && cols != 0)
    return true;
  return false;
}

MatrixUShort MatrixUShort::operator~() {
  MatrixUShort result(*this);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = ~UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator-() {
  MatrixUShort result(*this);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = -UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator=(MatrixUShort &input) {
  if ((rows != input.rows) || (cols != input.cols)) {
    if (UShortArray)
      delete[] UShortArray;
    rows = input.rows;
    cols = input.cols;
    UShortArray = new VectorUShort[cols];
    codeError = 0;
  }
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] = input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator+(MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] + input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator+(int input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] + input;
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator-(MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] - input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator-(int input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] - input;
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator*(MatrixUShort &input) {
  if (cols != input.rows) {
    std::cout << "Error! Can't multiply matrix, when cols1 not equal rows2."
              << std::endl;
    MatrixUShort nullMatrix(1);
    return nullMatrix;
  }
  MatrixUShort result(rows, input.cols);
  for (ui i = 0; i < rows; i++) {
    for (ui j = 0; j < input.cols; j++) {
      for (ui k = 0; k < cols; k++) {
        result.UShortArray[i][j] += UShortArray[i][k] * input.UShortArray[k][j];
      }
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator*(int input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] * input;
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator*(VectorUShort &input) {
  if (cols != input.getSize()) {
    std::cout << "Error! Can't multiply matrix and vector, when cols matrix "
                 "not equal size of vector."
              << std::endl;
    MatrixUShort nullMatrix(1, cols);
    return nullMatrix;
  }
  MatrixUShort result(1, cols);
  for (ui i = 0; i < rows; i++) {
    result.UShortArray[0][i] = 0;
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[0][i] += UShortArray[i][z] * input[z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator/(int input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] / input;
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator%(int input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] % input;
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator+=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      UShortArray[i][z] += input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator+=(const int input) {

  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] += input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator-=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      UShortArray[i][z] += input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator-=(const int input) {

  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] += input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator*=(const MatrixUShort &input) {
  if (cols != input.rows) {
    std::cout << "Error! Can't multiply matrix, when cols1 not equal rows2."
              << std::endl;
    MatrixUShort nullMatrix(1);
    return nullMatrix;
  }
  MatrixUShort result(rows, input.cols);
  for (ui i = 0; i < rows; i++) {
    for (ui j = 0; j < input.cols; j++) {
      for (ui k = 0; k < cols; k++) {
        result.UShortArray[i][j] += UShortArray[i][k] * input.UShortArray[k][j];
      }
    }
  }
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < input.cols; z++) {
      UShortArray[i][z] = result.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator*=(const int input) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] = UShortArray[i][z] * input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator*=(VectorUShort &input) {
  if (cols != input.getSize()) {
    std::cout << "Error! Can't multiply matrix and vector, when cols matrix "
                 "not equal size of vector."
              << std::endl;
    MatrixUShort nullMatrix(1, cols);
    return nullMatrix;
  }
  MatrixUShort result(1, cols);
  for (ui i = 0; i < rows; i++) {
    result.UShortArray[0][i] = 0;
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[0][i] += UShortArray[i][z] * input[z];
    }
  }
  for (ui i = 0; i < cols; i++) {
    UShortArray[0][i] = result.UShortArray[0][i];
  }
  rows = 1;
  return *this;
}

MatrixUShort MatrixUShort::operator/=(const int input) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] = UShortArray[i][z] / input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator%=(const int input) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] = UShortArray[i][z] % input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator|(const MatrixUShort &input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] | input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator^(const MatrixUShort &input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] ^ input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator^(const int input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] ^ input;
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator&(const MatrixUShort &input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] & input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator&(const int input) {
  MatrixUShort result(rows, cols);
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] & input;
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator>>=(const int input) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] >>= input;
    }
  }
  return *this;
}
MatrixUShort MatrixUShort::operator<<=(const int input) {
  std::cout << "<<=\n";
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] <<= input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator>>=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      UShortArray[i][z] >>= input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator<<=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      UShortArray[i][z] <<= input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator|=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      UShortArray[i][z] |= input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator|=(const int input) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] |= input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator^=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      UShortArray[i][z] ^= input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator^=(const int input) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] ^= input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator&=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      UShortArray[i][z] |= input.UShortArray[i][z];
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator&=(const int input) {
  for (ui i = 0; i < rows; i++) {
    for (ui z = 0; z < cols; z++) {
      UShortArray[i][z] |= input;
    }
  }
  return *this;
}

MatrixUShort MatrixUShort::operator==(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] == input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator!=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] != input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator>(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] > input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator<(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] < input.UShortArray[i][z];
    }
  }
  return result;
}

MatrixUShort MatrixUShort::operator<=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] <= input.UShortArray[i][z];
    }
  }
  return result;
}

VectorUShort MatrixUShort::operator[](int index) {
  if (index >= rows) {
    codeError = -1;
    return UShortArray[rows - 1];
  }
  return UShortArray[index];
}

MatrixUShort MatrixUShort::operator>=(const MatrixUShort &input) {
  ui res_rows = rows <= input.rows ? rows : input.rows;
  ui res_cols = cols <= input.cols ? cols : input.cols;
  MatrixUShort result(res_rows, res_cols);
  for (ui i = 0; i < res_rows; i++) {
    for (ui z = 0; z < res_cols; z++) {
      result.UShortArray[i][z] = UShortArray[i][z] >= input.UShortArray[i][z];
    }
  }
  return result;
}

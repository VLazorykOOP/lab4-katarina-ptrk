#ifndef MATRIXUINT_H
#define MATRIXUINT_H

typedef unsigned int ui;

#include "vectorushort.h"

class MatrixUShort {
private:
  VectorUShort *UShortArray;
  ui rows, cols;
  int codeError;

public:
  static int num_matrix;
  MatrixUShort();
  MatrixUShort(ui size);
  MatrixUShort(ui rows_, ui cols_);
  MatrixUShort(ui rows_, ui cols_, unsigned short value_);
  MatrixUShort(const MatrixUShort &input);
  ~MatrixUShort();

  int getRows() const;
  int getCols() const;
  int getCodeError() const;

  friend std::ostream &operator<<(std::ostream &os, const MatrixUShort &out);
  friend std::istream &operator>>(std::istream &is, const MatrixUShort &in);

  MatrixUShort operator++(int);
  MatrixUShort operator--(int);
  bool operator!();
  MatrixUShort operator~();
  MatrixUShort operator-();
  MatrixUShort operator=(MatrixUShort &input);

  MatrixUShort operator+(MatrixUShort &input);
  MatrixUShort operator+(int input);
  MatrixUShort operator-(MatrixUShort &input);
  MatrixUShort operator-(int input);
  MatrixUShort operator*(MatrixUShort &input);
  MatrixUShort operator*(int input);
  MatrixUShort operator*(VectorUShort &input);
  MatrixUShort operator/(int input);
  MatrixUShort operator%(int input);

  MatrixUShort operator+=(const MatrixUShort &input);
  MatrixUShort operator+=(const int input);
  MatrixUShort operator-=(const MatrixUShort &input);
  MatrixUShort operator-=(const int input);
  MatrixUShort operator*=(const MatrixUShort &input);
  MatrixUShort operator*=(VectorUShort &input);
  MatrixUShort operator*=(const int input);
  MatrixUShort operator/=(const int input);
  MatrixUShort operator%=(const int input);

  MatrixUShort operator|(const MatrixUShort &input);
  MatrixUShort operator^(const MatrixUShort &input);
  MatrixUShort operator^(const int input);
  MatrixUShort operator&(const MatrixUShort &input);
  MatrixUShort operator&(const int input);
  MatrixUShort operator<<=(const int input);
  MatrixUShort operator>>=(const int input);
  MatrixUShort operator>>=(const MatrixUShort &input);
  MatrixUShort operator<<=(const MatrixUShort &input);
  MatrixUShort operator|=(const MatrixUShort &input);
  MatrixUShort operator|=(const int input);
  MatrixUShort operator^=(const MatrixUShort &input);
  MatrixUShort operator^=(const int input);
  MatrixUShort operator&=(const MatrixUShort &input);
  MatrixUShort operator&=(const int input);

  MatrixUShort operator==(const MatrixUShort &input);
  MatrixUShort operator!=(const MatrixUShort &input);
  MatrixUShort operator>(const MatrixUShort &input);
  MatrixUShort operator>=(const MatrixUShort &input);
  MatrixUShort operator<(const MatrixUShort &input);
  MatrixUShort operator<=(const MatrixUShort &input);

  VectorUShort operator[](int);
};

#endif // MATRIXUINT_H

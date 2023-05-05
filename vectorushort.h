#ifndef VECTORUINT_H
#define VECTORUINT_H
#include <iostream>

class VectorUShort {
private:
  unsigned short *arr;
  unsigned int size;
  int codeError;

public:
  static unsigned int count;
  VectorUShort();
  VectorUShort(unsigned int elems);
  VectorUShort(unsigned int elems, unsigned short value);
  VectorUShort(VectorUShort &inp);
  ~VectorUShort();
  VectorUShort operator++(int);
  VectorUShort operator--(int);
  bool operator!();
  VectorUShort operator~();
  VectorUShort operator-();
  VectorUShort operator=(const VectorUShort &input);
  VectorUShort operator+(VectorUShort &input);
  VectorUShort operator+(unsigned int input);

  VectorUShort operator-(VectorUShort &input);
  VectorUShort operator-(unsigned int input);

  VectorUShort operator*(VectorUShort &input);
  VectorUShort operator*(unsigned int input);

  VectorUShort operator/(VectorUShort &input);
  VectorUShort operator/(unsigned int input);

  VectorUShort operator%(VectorUShort &input);
  VectorUShort operator%(unsigned int input);

  VectorUShort operator|(VectorUShort &input);
  VectorUShort operator|(unsigned int input);

  VectorUShort operator^(VectorUShort &input);
  VectorUShort operator^(unsigned int input);

  VectorUShort operator+=(VectorUShort &input);
  VectorUShort operator+=(unsigned int input);

  VectorUShort operator-=(VectorUShort &input);
  VectorUShort operator-=(unsigned int input);

  VectorUShort operator*=(VectorUShort &input);
  VectorUShort operator*=(unsigned int input);

  VectorUShort operator/=(VectorUShort &input);
  VectorUShort operator/=(unsigned int input);

  VectorUShort operator%=(VectorUShort &input);
  VectorUShort operator%=(unsigned int input);

  VectorUShort operator|=(VectorUShort &input);
  VectorUShort operator|=(unsigned int input);

  VectorUShort operator^=(VectorUShort &input);
  VectorUShort operator^=(unsigned int input);

  friend std::ostream &operator<<(std::ostream &os, const VectorUShort &out);
  friend std::istream &operator>>(std::istream &is, const VectorUShort &in);

  bool operator==(VectorUShort &input);
  bool operator!=(VectorUShort &input);

  unsigned short &operator[](const unsigned int index);
  void operator()();

  bool operator>(VectorUShort &input);
  bool operator>=(VectorUShort &input);
  bool operator<(VectorUShort &input);
  bool operator<=(VectorUShort &input);
  unsigned int getSize() const;
};

#endif // VECTORUINT_H

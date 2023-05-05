#include "vectorushort.h"

unsigned int VectorUShort::count = 0;

unsigned int VectorUShort::getSize() const { return size; }

VectorUShort::VectorUShort() {
  arr = new unsigned short[1];
  arr[0] = 0;
  codeError = 0;
  size = 1;
  count++;
}

VectorUShort::VectorUShort(unsigned int elems) {
  arr = new unsigned short[elems];
  size = elems;
  for (unsigned short i = 0; i < elems; i++)
    arr[i] = 0;
  codeError = 0;
  count++;
}

VectorUShort::VectorUShort(unsigned int elems, unsigned short value) {
  arr = new unsigned short[elems];
  size = elems;
  for (unsigned int i = 0; i < elems; i++)
    arr[i] = value;
  codeError = 0;
  count++;
}

VectorUShort::VectorUShort(VectorUShort &inp) {
  arr = new unsigned short[inp.size];
  size = inp.size;
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = inp.arr[i];
  }
  codeError = 0;
  count++;
}

VectorUShort::~VectorUShort() {
  delete[] arr;
  count--;
}

VectorUShort VectorUShort::operator++(int) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] += 1;
  }
  return *this;
}

VectorUShort VectorUShort::operator--(int) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] -= 1;
  }
  return *this;
}

bool VectorUShort::operator!() {
  if (size != 0)
    return true;
  else
    return false;
}

VectorUShort VectorUShort::operator~() {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = ~arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator-() {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = 0 - arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator=(const VectorUShort &input) {
  if (size != input.size) {
    if (arr)
      delete[] arr;
    size = input.size;
    arr = new unsigned short[size];
    codeError = 0;
  }
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator+(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  VectorUShort result(elems);
  for (unsigned int i = 0; i < elems; i++) {
    result.arr[i] = arr[i] + input.arr[i];
  }
  return result;
}

VectorUShort VectorUShort::operator+(unsigned int input) {
  VectorUShort result(size);
  for (unsigned int i = 0; i < size; i++) {
    result.arr[i] = arr[i] + input;
  }
  return result;
}

VectorUShort VectorUShort::operator-(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  VectorUShort result(elems);
  for (unsigned int i = 0; i < elems; i++) {
    result.arr[i] = arr[i] - input.arr[i];
  }
  return result;
}

VectorUShort VectorUShort::operator-(unsigned int input) {
  VectorUShort result(size);
  for (unsigned int i = 0; i < size; i++) {
    result.arr[i] = arr[i] - input;
  }
  return result;
}

VectorUShort VectorUShort::operator*(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  VectorUShort result(elems);
  for (unsigned int i = 0; i < elems; i++) {
    result.arr[i] = arr[i] * input.arr[i];
  }
  return result;
}

VectorUShort VectorUShort::operator*(unsigned int input) {
  VectorUShort result(size);
  for (unsigned int i = 0; i < size; i++) {
    result.arr[i] = arr[i] * input;
  }
  return result;
}

VectorUShort VectorUShort::operator/(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  VectorUShort result(elems);
  for (unsigned int i = 0; i < elems; i++) {
    result.arr[i] = arr[i] / input.arr[i];
  }
  return result;
}

VectorUShort VectorUShort::operator/(unsigned int input) {
  VectorUShort result(size);
  for (unsigned int i = 0; i < size; i++) {
    result.arr[i] = arr[i] / input;
  }
  return result;
}

VectorUShort VectorUShort::operator%(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  VectorUShort result(elems);
  for (unsigned int i = 0; i < elems; i++) {
    result.arr[i] = arr[i] % input.arr[i];
  }
  return result;
}

VectorUShort VectorUShort::operator%(unsigned int input) {
  VectorUShort result(size);
  for (unsigned int i = 0; i < size; i++) {
    result.arr[i] = arr[i] % input;
  }
  return result;
}

VectorUShort VectorUShort::operator|(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  VectorUShort result(elems);
  for (unsigned int i = 0; i < elems; i++) {
    result.arr[i] = arr[i] | input.arr[i];
  }
  return result;
}

VectorUShort VectorUShort::operator|(unsigned int input) {
  VectorUShort result(size);
  for (unsigned int i = 0; i < size; i++) {
    result.arr[i] = arr[i] | input;
  }
  return result;
}

VectorUShort VectorUShort::operator^(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  VectorUShort result(elems);
  for (unsigned int i = 0; i < elems; i++) {
    result.arr[i] = arr[i] ^ input.arr[i];
  }
  return result;
}

VectorUShort VectorUShort::operator^(unsigned int input) {
  VectorUShort result(size);
  for (unsigned int i = 0; i < size; i++) {
    result.arr[i] = arr[i] ^ input;
  }
  return result;
}

VectorUShort VectorUShort::operator+=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    arr[i] = arr[i] += input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator+=(unsigned int input) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = arr[i] += input;
  }
  return *this;
}

VectorUShort VectorUShort::operator-=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    arr[i] = arr[i] -= input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator-=(unsigned int input) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = arr[i] -= input;
  }
  return *this;
}

VectorUShort VectorUShort::operator*=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    arr[i] = arr[i] *= input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator*=(unsigned int input) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = arr[i] *= input;
  }
  return *this;
}

VectorUShort VectorUShort::operator/=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    arr[i] = arr[i] /= input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator/=(unsigned int input) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = arr[i] /= input;
  }
  return *this;
}

VectorUShort VectorUShort::operator%=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    arr[i] = arr[i] %= input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator%=(unsigned int input) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = arr[i] %= input;
  }
  return *this;
}

VectorUShort VectorUShort::operator|=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    arr[i] = arr[i] |= input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator|=(unsigned int input) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = arr[i] |= input;
  }
  return *this;
}

VectorUShort VectorUShort::operator^=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    arr[i] = arr[i] ^= input.arr[i];
  }
  return *this;
}

VectorUShort VectorUShort::operator^=(unsigned int input) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i] = arr[i] ^= input;
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, const VectorUShort &out) {
  for (unsigned int i = 0; i < out.size; i++) {
    os << out.arr[i] << " ";
  }
  os << std::endl;
  return os;
}

std::istream &operator>>(std::istream &is, const VectorUShort &in) {
  for (unsigned int i = 0; i < in.size; i++) {
    is >> in.arr[i];
  }
  return is;
}

bool VectorUShort::operator==(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    if (arr[i] != input.arr[i])
      return false;
  }
  return true;
}

bool VectorUShort::operator!=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    if (arr[i] == input.arr[i])
      return false;
  }
  return true;
}

unsigned short &VectorUShort::operator[](const unsigned int index) {
  if (index > size) {
    return arr[size - 1];
    codeError = -1;
  }
  return arr[index];
}

void VectorUShort::operator()() {
  //???
}

bool VectorUShort::operator>(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    if (arr[i] <= input.arr[i])
      return false;
  }
  return true;
}

bool VectorUShort::operator>=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    if (arr[i] < input.arr[i])
      return false;
  }
  return true;
}

bool VectorUShort::operator<(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    if (arr[i] >= input.arr[i])
      return false;
  }
  return true;
}

bool VectorUShort::operator<=(VectorUShort &input) {
  unsigned int elems = size <= input.size ? size : input.size;
  for (unsigned int i = 0; i < elems; i++) {
    if (arr[i] > input.arr[i])
      return false;
  }
  return true;
}

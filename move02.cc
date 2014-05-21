/*******************************************************************************
 *  
 *  Copyright (C) 2013 Andreas Mussgiller
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *  
 *******************************************************************************/

#include <iostream>
#include <vector>

class B
{
public:
  B(size_t sz = 0)
  :size_(sz), buffer_(new char [sz]) {
    objId_ = ++objCount_;
    std::cout << "B::B(" << size_ << "): " << objId_ << std::endl;
  }

  B(const B& other)
    :size_(other.size_), buffer_(new char [other.size_]) {
    std::copy(other.buffer_, other.buffer_+size_, buffer_);
    objId_ = ++objCount_;
    std::cout << "B::B(const B& other): " << objId_ << " from " << other.objId_ << std::endl;
  }

  B(B&& other)
    :size_(other.size_), buffer_(other.buffer_) {
    other.size_ = 0;
    other.buffer_ = 0;
    objId_ = ++objCount_;
    std::cout << "B::B(B&& other): " << objId_ << " from " << other.objId_ << std::endl;
  }

  auto operator=(const B& other) -> B& {
    std::cout << "B::operator=(const B& other): " << objId_ << " from " << other.objId_ << std::endl;

    delete [] buffer_;

    size_ = other.size_;
    buffer_ = new char [other.size_];

    std::copy(other.buffer_, other.buffer_+size_, buffer_);

    return *this;
  }

  auto operator=(B&& other) -> B& {
    std::cout << "B::operator=(B&& other): " << objId_ << " from " << other.objId_ << std::endl;

    delete [] buffer_;

    size_ = other.size_;
    buffer_ = other.buffer_;

    other.size_ = 0;
    other.buffer_ = 0;

    return *this;
  }

  ~B() {
    std::cout << "B::~B(" << size_ << "): " << objId_ << std::endl;
    size_ = 0;
    delete [] buffer_;
  }

  size_t size_;
  char * buffer_;
  static int objCount_;
  int objId_;
};

int B::objCount_ = 0;

B f(B b) {
  return b;
}

int main()
{
  std::cout << "--> test 1" << std::endl;
  {
    std::cout << "create b1:" << std::endl;
    B b1(1024);
    std::cout << std::endl;

    std::cout << "assign b1 to b2 (lvalue):" << std::endl;
    B b2 = b1;
    std::cout << std::endl;
  }
  std::cout << "<-- test 1\n" << std::endl;

  std::cout << "--> test 2" << std::endl;
  {
    std::cout << "create b3:" << std::endl;
    B b3(1024);
    std::cout << std::endl;

    std::cout << "assign b3 to b4 (rvalue/move):" << std::endl;
    B b4 = std::move(b3);
    std::cout << std::endl;

    std::cout << "assign b4 to b5 (rvalue/move):" << std::endl;
    B b5;
    b5 = std::move(b4);
    std::cout << std::endl;
  }
  std::cout << "<-- test 2\n" << std::endl;

  std::cout << "--> test 3" << std::endl;
  {
    std::cout << "create b6 via function (rvalue):" << std::endl;
    B b6;
    b6 = f(B(1024));
    std::cout << std::endl;
  }
  std::cout << "<-- test 3\n" << std::endl;
}

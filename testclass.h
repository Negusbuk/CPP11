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

class TestClass
{
public:
  TestClass(size_t sz = 0)
    :size_(sz),
     buffer_(new char [sz])
  {
    objId_ = ++objCount_;
    std::cout << "TestClass::TestClass(" << size_ << "): "
              << objId_ << std::endl;
  }

  TestClass(const TestClass& other)
    :size_(other.size_),
     buffer_(new char [other.size_])
  {
    std::copy(other.buffer_, other.buffer_+size_, buffer_);
    objId_ = ++objCount_;
    std::cout << "TestClass::TestClass(const TestClass& other): "
              << objId_ << " from " << other.objId_ << std::endl;
  }

  TestClass(TestClass&& other)
    : size_(other.size_),
      buffer_(other.buffer_)
  {
    other.size_ = 0;
    other.buffer_ = 0;
    objId_ = ++objCount_;
    std::cout << "TestClass::TestClass(A&& other): "
              << objId_ << " from " << other.objId_ << std::endl;
  }

  auto operator=(const TestClass& other) -> TestClass& {
    std::cout << "TestClass::operator=(const TestClass& other): "
              << objId_ << " from " << other.objId_ << std::endl;

    delete [] buffer_;

    size_ = other.size_;
    buffer_ = new char [other.size_];

    std::copy(other.buffer_, other.buffer_+size_, buffer_);

    return *this;
  }

  auto operator=(TestClass&& other) -> TestClass& {
    std::cout << "TestClass::operator=(TestClass&& other): "
              << objId_ << " from " << other.objId_ << std::endl;

    delete [] buffer_;

    size_ = other.size_;
    buffer_ = other.buffer_;

    other.size_ = 0;
    other.buffer_ = 0;

    return *this;
  }

  ~TestClass()
  {
    std::cout << "TestClass::~TestClass(" << size_ << "): " << objId_ << std::endl;
    size_ = 0;
    delete [] buffer_;
  }

  size_t size_;
  char * buffer_;
  static int objCount_;
  int objId_;
};

int TestClass::objCount_ = 0;

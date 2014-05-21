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

class A
{
public:
  A(size_t sz)
  :size_(sz), buffer_(new char [sz]) {
    objId_ = ++objCount_;
    std::cout << "A::A(" << size_ << "): " << objId_ << std::endl;
  }

  A(const A& other)
    :size_(other.size_), buffer_(new char [other.size_]) {
    std::copy(other.buffer_, other.buffer_+size_, buffer_);
    objId_ = ++objCount_;
    std::cout << "A::A(const A& other): " << objId_ << " from " << other.objId_ << std::endl;
  }

  A(A&& other)
    :size_(other.size_), buffer_(other.buffer_) {
    other.size_ = 0;
    other.buffer_ = 0;
    objId_ = ++objCount_;
    std::cout << "A::A(A&& other): " << objId_ << " from " << other.objId_ << std::endl;
  }

  ~A() {
    std::cout << "A::~A(" << size_ << "): " << objId_ << std::endl;
    size_ = 0;
    delete [] buffer_;
  }

  size_t size_;
  char * buffer_;
  static int objCount_;
  int objId_;
};

int A::objCount_ = 0;

int main()
{
  std::cout << "--> test 1" << std::endl;
  {
    std::vector<A> va;

    std::cout << "create a1:" << std::endl;
    A a1(1024);
    std::cout << std::endl;

    std::cout << "push a1 into vector (lvalue):" << std::endl;
    va.push_back(a1);
    std::cout << std::endl;
  }
  std::cout << "<-- test 1\n" << std::endl;

  std::cout << "--> test 2" << std::endl;
  {
    std::vector<A> va;

    std::cout << "create a2:" << std::endl;
    A a2(1024);
    std::cout << std::endl;

    std::cout << "create a3 from a2 (lvalue/copy):" << std::endl;
    A a3(a2);
    std::cout << std::endl;

    std::cout << "push a3 into vector (lvalue):" << std::endl;
    va.push_back(a3);
    std::cout << std::endl;
  }
  std::cout << "<-- test 2\n" << std::endl;

  std::cout << "--> test 3" << std::endl;
  {
    std::vector<A> va;

    std::cout << "create a4:" << std::endl;
    A a4(1024);
    std::cout << std::endl;

    std::cout << "push a3 into vector (rvalue/move):" << std::endl;
    va.push_back(std::move(a4));
    std::cout << std::endl;
  }
  std::cout << "<-- test 3\n" << std::endl;

  std::cout << "--> test 4" << std::endl;
  {
    std::cout << "create a5:" << std::endl;
    A a5(1024);
    std::cout << std::endl;

    std::cout << "create a6 from a5 (rvalue/move):" << std::endl;
    A a6(std::move(a5));
    std::cout << std::endl;
  }
  std::cout << "<-- test 4\n" << std::endl;

  std::cout << "--> test 5" << std::endl;
  {
    std::cout << "create a7:" << std::endl;
    A a7(1024);
    std::cout << std::endl;

    std::cout << "create a8 from a5 (rvalue):" << std::endl;
    A a8(static_cast<A&&>(a7));
    std::cout << std::endl;
  }
  std::cout << "<-- test 5" << std::endl;
}

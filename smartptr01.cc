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

#include <memory>
#include <iostream>

class A
{
public:
  A() {
    objId_ = ++objCount_;
    std::cout << "A::A(): " << objId_ << std::endl;
  }

  A(const A& other) {
    objId_ = ++objCount_;
    std::cout << "A::A(const A& other): " << objId_ << " from " << other.objId_ << std::endl;
  }

  A(A&& other) {
    objId_ = ++objCount_;
    std::cout << "A::A(A&& other): " << objId_ << " from " << other.objId_ << std::endl;
  }

  ~A() {
    std::cout << "A::~A(): " << objId_ << std::endl;
  }

  void func() {
    std::cout << "A::func(): " << objId_ << std::endl;;
  }

  static int objCount_;
  int objId_;
};

int A::objCount_ = 0;

int main()
{
  {
    std::unique_ptr<A> p(new A());
    std::cout << "p: " << p.get() << std::endl;
    p->func();
  }
  std::cout << std::endl;

  {
    std::unique_ptr<A> p1(new A());
    std::cout << "p1: "<< p1.get() << std::endl;
    p1->func();

    std::unique_ptr<A> p2 = std::move(p1);
    std::cout << "p1: "<< p1.get() << std::endl;
    std::cout << "p2: "<< p2.get() << std::endl;
    p2->func();
  }
  std::cout << std::endl;

  {
    A a;
    std::unique_ptr<A> p(&a); // crash due to double delete
    std::cout << "p: "<< p.get() << std::endl;
  }
}

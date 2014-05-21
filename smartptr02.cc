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
#include <vector>

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
  std::vector<std::unique_ptr<A>> v;

  v.push_back(std::unique_ptr<A>(new A));
  v.push_back(std::unique_ptr<A>(new A));

  std::cout << v[0].get() << std::endl;
  std::cout << v[1].get() << std::endl;
  v[1]->func();

  v[0] = std::move(v[1]);

  std::cout << v[0].get() << std::endl;
  std::cout << v[1].get() << std::endl;
  v[0]->func();
  // v[1]->func(); // segmentation violation

  std::unique_ptr<A> p = std::move(v[0]);
  std::cout << v[0].get() << std::endl;
  // v[0]->func(); // segmentation violation

  p->func();
}

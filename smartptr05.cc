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

class A : public std::enable_shared_from_this<A>
{
public:
  A() {
    std::cout << "A::A()" << std::endl;
  }

  ~A() {
    std::cout << "A::~A()" << std::endl;
  }

  std::shared_ptr<A> getSharedPtr() {
    std::cout << "A::getSharedPtr()" << std::endl;
    return shared_from_this();
  }
};

class B
{
public:
  B() {
    std::cout << "B::B()" << std::endl;
  }

  ~B() {
    std::cout << "B::~B()" << std::endl;
  }

  std::shared_ptr<B> getSharedPtr() {
    std::cout << "B::getSharedPtr()" << std::endl;
    return std::shared_ptr<B>(this);
  }
};

int main()
{

  {
    A* a = new A;

    std::shared_ptr<A> ap1(a);
    std::cout << "ap1: " << ap1.get() << " " << ap1.use_count() << std::endl;

    std::shared_ptr<A> ap2 = a->getSharedPtr();
    std::cout << "ap2: " << ap2.get() << " " << ap2.use_count() << std::endl;

    {
      std::shared_ptr<A> ap3 = a->getSharedPtr();
      std::cout << "ap3: " << ap3.get() << " " << ap3.use_count() << std::endl;
    }
    std::cout << "ap1: " << ap1.get() << " " << ap1.use_count() << std::endl;
    std::cout << "ap2: " << ap2.get() << " " << ap2.use_count() << std::endl;

    std::shared_ptr<A> ap4 = a->shared_from_this();
    std::cout << "ap4: " << ap4.get() << " " << ap4.use_count() << std::endl;
  }
  std::cout << std::endl;

  {
    B* b = new B;
    std::shared_ptr<B> bp1(b);
    std::cout << bp1.get() << " " << bp1.use_count() << std::endl;

    // crash due to double delete
    std::shared_ptr<B> bp2 = b->getSharedPtr();
    std::cout << bp2.get() << " " << bp2.use_count() << std::endl;
  }
}

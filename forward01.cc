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
#include <memory>
#include <utility>

class A {
public:
  A(int&& n) {
    std::cout << "rvalue overload, n=" << n << "\n";
  }
  A(int& n)  {
    std::cout << "lvalue overload, n=" << n << "\n";
  }
};

template<class T, class U>
std::unique_ptr<T> make_unique(U&& u)
{
  return std::unique_ptr<T>(new T(std::forward<U>(u)));
}

template<class T, class U>
std::unique_ptr<T> make_uniqueNoFwd(U&& u)
{
  return std::unique_ptr<T>(new T(u));
}

int main()
{
  int i = 1;

  std::unique_ptr<A> p;

  p = make_unique<A>(2);
  p = make_uniqueNoFwd<A>(2);

  p = make_unique<A>(i);
  p = make_uniqueNoFwd<A>(i);
}


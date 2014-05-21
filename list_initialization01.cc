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
#include <array>

class A {
public:
  A(int i1, int i2) :
  i1_(i1), i2_(i2)
  { std::cout << "A::A(" << i1_ << ", " << i2_ << ")" << std::endl; }
protected:
  int i1_, i2_;
};

int main()
{
  A a1(1,2);
  A a2{3,4};
  A a3 = A{5,6};
  // A a4{3,4,5};

  std::vector<int> v1 = {1,2,3,4,5,6};
  std::vector<int> v2{ {1,2,3,4,5,6} };

  for(auto& s: v1) std::cout << s << ' ';
  std::cout << std::endl;
  for(auto& s: v2) std::cout << s << ' ';
  std::cout << std::endl;

  std::array<int,6> ar1{ {1,2,3,4,5,6} };
  std::array<int,7> ar2{ {1,2,3,4,5,6} };
  // std::array<int,5> ar3{ {1,2,3,4,5,6} };

  for(auto& s: ar1) std::cout << s << ' ';
  std::cout << std::endl;
  for(auto& s: ar2) std::cout << s << ' ';
  std::cout << std::endl;
}

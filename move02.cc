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

#include "testclass.h"

TestClass function(TestClass obj) {
  return obj;
}

int main()
{
  std::cout << "--> test 1" << std::endl;
  {
    std::cout << "create obj1:" << std::endl;
    TestClass obj1(1024);
    std::cout << std::endl;

    std::cout << "assign obj1 to obj2 (lvalue):" << std::endl;
    TestClass obj2 = obj1;
    std::cout << std::endl;
  }
  std::cout << "<-- test 1\n" << std::endl;

  std::cout << "--> test 2" << std::endl;
  {
    std::cout << "create obj1:" << std::endl;
    TestClass obj1(1024);
    std::cout << std::endl;

    std::cout << "assign obj1 to obj2 (rvalue/move):" << std::endl;
    TestClass obj2 = std::move(obj1);
    std::cout << std::endl;

    std::cout << "assign obj2 to obj3 (rvalue/move):" << std::endl;
    TestClass obj3;
    obj3 = std::move(obj2);
    std::cout << std::endl;
  }
  std::cout << "<-- test 2\n" << std::endl;

  std::cout << "--> test 3" << std::endl;
  {
    std::cout << "create onj via function (rvalue):" << std::endl;
    TestClass obj;
    obj = function(TestClass(1024));
    std::cout << std::endl;
  }
  std::cout << "<-- test 3\n" << std::endl;
}

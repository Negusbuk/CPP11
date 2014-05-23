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

int main()
{
  std::cout << "--> test 1" << std::endl;
  {
    std::vector<TestClass> v;

    std::cout << "create obj:" << std::endl;
    TestClass obj(1024);
    std::cout << std::endl;

    std::cout << "push obj into vector (lvalue):" << std::endl;
    v.push_back(obj);
    std::cout << std::endl;
  }
  std::cout << "<-- test 1\n" << std::endl;

  std::cout << "--> test 2" << std::endl;
  {
    std::vector<TestClass> v;

    std::cout << "create obj1:" << std::endl;
    TestClass obj1(1024);
    std::cout << std::endl;

    std::cout << "create obj2 from obj1 (lvalue/copy):" << std::endl;
    TestClass obj2(obj1);
    std::cout << std::endl;

    std::cout << "push obj2 into vector (lvalue):" << std::endl;
    v.push_back(obj2);
    std::cout << std::endl;
  }
  std::cout << "<-- test 2\n" << std::endl;

  std::cout << "--> test 3" << std::endl;
  {
    std::vector<TestClass> v;

    std::cout << "create obj:" << std::endl;
    TestClass obj(1024);
    std::cout << std::endl;

    std::cout << "push obj into vector (rvalue/move):" << std::endl;
    v.push_back(std::move(obj));
    std::cout << std::endl;
  }
  std::cout << "<-- test 3\n" << std::endl;

  std::cout << "--> test 4" << std::endl;
  {
    std::cout << "create a5:" << std::endl;
    TestClass obj1(1024);
    std::cout << std::endl;

    std::cout << "create obj2 from obj1 (rvalue/move):" << std::endl;
    TestClass obj2(std::move(obj1));
    std::cout << std::endl;
  }
  std::cout << "<-- test 4\n" << std::endl;

  std::cout << "--> test 5" << std::endl;
  {
    std::cout << "create obj1:" << std::endl;
    TestClass obj1(1024);
    std::cout << std::endl;

    std::cout << "create obj2 from obj1 (rvalue):" << std::endl;
    TestClass obj2(static_cast<TestClass&&>(obj1));
    std::cout << std::endl;
  }
  std::cout << "<-- test 5\n" << std::endl;
}

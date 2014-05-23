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

class SmartPtrTestClass
{
public:
  SmartPtrTestClass() {
    objId_ = ++objCount_;
    std::cout << "SmartPtrTestClass::SmartPtrTestClass(): " << objId_ << std::endl;
  }

  SmartPtrTestClass(const SmartPtrTestClass& other) {
    objId_ = ++objCount_;
    std::cout << "SmartPtrTestClass::SmartPtrTestClass(const A& other): "
              << objId_ << " from " << other.objId_ << std::endl;
  }

  SmartPtrTestClass(SmartPtrTestClass&& other) {
    objId_ = ++objCount_;
    std::cout << "SmartPtrTestClass::SmartPtrTestClass(SmartPtrTestClass&& other): "
              << objId_ << " from " << other.objId_ << std::endl;
  }

  ~SmartPtrTestClass() {
    std::cout << "SmartPtrTestClass::~SmartPtrTestClass(): " << objId_ << std::endl;
  }

  void func() {
    std::cout << "SmartPtrTestClass::func(): " << objId_ << std::endl;;
  }

  static int objCount_;
  int objId_;
};

int SmartPtrTestClass::objCount_ = 0;

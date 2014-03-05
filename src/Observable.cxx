/**
 * libcppattern - C++ Pattern library
 * Copyright (C) 2014  Andreas Speier
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <iostream>

#include "Observable.hxx"


Observable::~Observable() {
    this->_observers.clear();
}

void Observable::Attach( IObserver* o ) {
    this->_observers.push_back( o );
}

void Observable::Detach( IObserver* o ) {
    _observers.remove(o);
}

void Observable::Notify() {
    std::list<IObserver*>::iterator it = this->_observers.begin();
    
    for(; it != this->_observers.end(); it++ ) {
        IObserver* io = (IObserver*) *it;
        io->Update();
    }
}


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


#ifndef OBSERVABLE_HPP_
#define OBSERVABLE_HPP_

#include <list>

#include "IObserver.hxx"

class Observable {
    public:
        Observable() {}
        virtual ~Observable();

        void Attach( IObserver* );
        void Detach( IObserver* );
        void Notify();

    protected:
        std::list<IObserver*>   _observers;

};


#endif


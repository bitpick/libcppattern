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


#ifndef ICOMMAND_INTERFACE_
#define ICOMMAND_INTERFACE_

#include <string>

class ICommand {
    public:
        ICommand() {}
        ICommand(const &ICommand) = 0;

        virtual ~ICommand() {}

        virtual void SetParams( std::string& ) = 0;
        virtual void Execute() = 0;
        virtual void Undo() = 0;
        virtual void Redo() = 0;
};

#endif

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

#ifndef SINGLETONT_HXX
#define SINGLETONT_HXX


#include <assert.h>
#include <cstdint>

#ifdef USE_PTHREAD
#include <pthread.h>
#endif

		
template <class T> class SingeltonT
{
public:
	static T* instance()
	{
        #ifdef USE_PTHREAD
		pthread_mutex_init( mutex, NULL );
        #endif
		
		if(m_instance == NULL)
		{
            #ifdef USE_PTHREAD
			pthread_mutex_lock( mutex );
            #endif
				
			if(m_instance == NULL)
				m_instance = new T();
                
            #ifdef USE_PTHREAD
			pthread_mutex_unlock( mutex );
            #endif
		}

		assert(m_instance != NULL);

        return m_instance;
	}
			
private:
	    static T*  m_instance;
        #ifdef USE_PTHREAD
	    static pthread_mutex_t *mutex;
        #endif

	    SingeltonT() { }
		
protected:
	    virtual ~SingeltonT() {
	    	#ifdef USE_PTHREAD
	    	pthread_mutex_lock(mutex);
	    	#endif

	    	delete m_instance;

	    	#ifdef USE_PTHREAD
	    	pthread_mutex_unlock(mutex);
	    	#endif 
	    	
	    	m_instance = 0;
	    }
};

template <class T> T* SingeltonT <T>::m_instance = 0;

#endif

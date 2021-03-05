#pragma once


#include "../Core/Threading/Runnable.h"
#include <iostream>

namespace Untether {

	class ThreadTest : public Runnable {
        int counter = 0;
	public:
		void run() override {

            std::cout << "thread iteration " << ++counter << std::endl;
                // Sleep and check for interrupt.
                // To check for interrupt without sleep,
                // use boost::this_thread::interruption_point()
                // which also throws boost::thread_interrupted  
                //std::this_thread::sleep(boost::posix_time::milliseconds(900));        
            Sleep(500);
		}

        ~ThreadTest() {
            std::cout << "ThreadTest ending" << std::endl;
        }
	};

}
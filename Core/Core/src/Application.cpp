#include "Application.h"
#include <iostream>
#include <Logger/Logger.h>

namespace Core {
        Application::Application( ApplicationConfig config )
                : _config( config ){
                Logger::Init();
                CORE_LOG_INFO("Core Logger Initialized");
        };

        bool Application::Init()
        {
                return true;
        }

        void Application::Run()
        {
                std::cout << "App running!" << std::endl;
        }
        
        void Application::Stop(){};
}
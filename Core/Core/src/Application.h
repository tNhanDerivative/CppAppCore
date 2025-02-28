#pragma once

#include <string>

namespace Core {
        struct ApplicationConfig {
                std::string name;
                std::string version;
        };

        class Application {
        public:
                Application( ApplicationConfig config );
                virtual ~Application()=default;
                
                virtual bool Init();
                virtual void Run();
                virtual void Stop();
                
        private:
                ApplicationConfig _config;
        };


}
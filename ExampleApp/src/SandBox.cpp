#include <Core/src/Application.h>
#include <Core/Logger/Logger.h>
#include <iostream>
#include <thread>
#include <chrono>

class SandBox : public Core::Application
{
public:
        SandBox(Core::ApplicationConfig config) : Core::Application(config) {};

        virtual bool Init() override {
                std::cout << "Initializing SandBox" << std::endl;
                return true;
        };

        virtual void Run() override {
                while (true) {
                        std::cout << "Hello SandBox" << std::endl;
                        LOG_INFO("Client Logger works");
                        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                }
        }

        virtual void Stop() override {
                std::cout << "SandBox Shutting down" << std::endl;
        }
};




int main() {
        Core::ApplicationConfig appConfig;
        appConfig.name = "SandBox";
        appConfig.version = "0.0.1";

        SandBox* application = new SandBox(appConfig);

	if (application->Init()) {
		application->Run();
	}

	application->Stop();
	delete application;

	return 0;
}
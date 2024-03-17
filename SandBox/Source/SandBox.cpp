#include <Pop.hpp>

class Sandbox : public Pop::Core::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Pop::Core::Application* Pop::Core::CreateApplication()
{
	return new Sandbox();
}
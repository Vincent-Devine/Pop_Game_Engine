#include <Pop.hpp>

class Sandbox : public Pop::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Pop::Application* Pop::CreateApplication()
{
	return new Sandbox();
}
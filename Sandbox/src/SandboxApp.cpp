#include <Argonex.h>

class Sandbox : public Argonex::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Argonex::Application* Argonex::CreateApplication()
{
	return new Sandbox();
}
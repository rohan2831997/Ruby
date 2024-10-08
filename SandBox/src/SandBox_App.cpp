#include "ruby.h"

class SandBox : public Ruby::Application 
{
public:
	SandBox() {};
	~SandBox() {};
};

Ruby::Application* Ruby::CreateApplication()
{
	return new SandBox();
}

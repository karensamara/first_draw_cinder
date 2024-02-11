#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class FirstDraw : public App
{
public:
	void draw() override;
	void setup() override;
	void update() override;

protected:
	vec2 position;
	vec2 velocity;
	float radius;
	float gravity;
};

void FirstDraw::draw()
{
	gl::clear();
	gl::drawSolidCircle(position, radius);
}

void FirstDraw::setup()
{
	position = getWindowCenter();
	velocity = vec2(5, 2);
	radius = 40;
	gravity = 0.15f;
}

void FirstDraw::update()
{
	position += velocity;
	velocity.y += gravity;

	if (position.x - radius < 0 || position.x + radius > getWindowWidth())
	{
		velocity.x *= -1.0f;
		velocity.y *= 0.9f;
	}
	if (position.y - radius < 0 || position.y + radius > getWindowHeight())
	{

		velocity.y *= -0.8f;
		velocity.x *= 0.875f;
		position.y = getWindowHeight() - radius;
		if (std::abs(velocity.y) < 0.5f)
		{
			velocity.y = 0;
		}
		else if (std::abs(velocity.y) < 1.1f)
		{
			velocity.y += 0.2f;
		}

		if (std::abs(velocity.x) < 0.01f)
		{
			velocity.x = 0;
		}
	}
}

CINDER_APP(FirstDraw, RendererGl)

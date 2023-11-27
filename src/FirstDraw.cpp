#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class FirstDraw : public App {
  public:
	void draw() override;
};

void FirstDraw::draw()
{
	gl::clear();
	gl::drawSolidCircle( getWindowCenter(), 200 );
}

CINDER_APP( FirstDraw, RendererGl )

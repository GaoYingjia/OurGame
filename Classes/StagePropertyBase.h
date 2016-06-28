#ifndef __STAGEPROPBASE__
#define __STAGEPROPBASE__

#include "cocos2d.h"
#include "testResource.h"

USING_NS_CC;
#if CC_USE_PHYSICS

class StagePropertyBase : public Sprite
{
public:
	static StagePropertyBase* create(const std::string& filename);
	virtual void personalized(cocos2d::Vec2 p, float scale);//subclass override this func to modify componet shape category contact collision
private:
};
#endif
#endif
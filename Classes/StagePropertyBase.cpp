#include "StagePropertyBase.h"

USING_NS_CC;

StagePropertyBase * StagePropertyBase::create(const std::string& filename)
{
	StagePropertyBase *sprite = new StagePropertyBase();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease(); 
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void StagePropertyBase::personalized(cocos2d::Vec2 p, float scale)
{
	setScale(scale);
	setPosition(p);
	addComponent(PhysicsBody::createBox(Size(48.0f, 108.0f)));
	PhysicsBody *body = getPhysicsBody();
	body->addShape(PhysicsShapeBox::create(Size(48.0f, 108.0f)));
	body->setRotationEnable(false);
	body->setDynamic(false);
	body->getShape(0)->setFriction(30);
	body->getShape(0)->setRestitution(0.0);
	body->getShape(0)->setCategoryBitmask(0x0001);
	body->getShape(0)->setContactTestBitmask(0x0001);
	body->getShape(0)->setCollisionBitmask(0x0001);
	body->setContactTestBitmask(0x03);
}
#include "UserPlayer.h"

USING_NS_CC;

UserPlayer::UserPlayer(){
	m_direction = UserPlayer::kRight;
	m_state = UserPlayer::kStatic;
	m_hp = 3;
	//m_runState = true;
}

UserPlayer::~UserPlayer(){
}

UserPlayer * UserPlayer::create(const std::string& filename)
{
	UserPlayer *sprite = new UserPlayer();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}
bool UserPlayer::initPlayer(){
	//attackSprite
	m_move1 = Sprite::create("Images/grossini_dance_01.png")->getTexture();

	m_attackSprite = Sprite::createWithTexture(m_move1);
	m_attackSprite->addComponent(PhysicsBody::createBox(Size(20.0f, 20.0f)));
	m_attackSprite->getPhysicsBody()->setRotationEnable(false);
	m_attackSprite->getPhysicsBody()->setDynamic(false);
	m_attackSprite->getPhysicsBody()->setEnabled(false);
	m_attackSprite->setPosition(this->getPosition().x - 150, this->getPosition().y);
	m_attackSprite->setVisible(false);
	this->addChild(m_attackSprite);

	return true;
}
void UserPlayer::personalized(cocos2d::Vec2 p, float scale)
{
	setScale(scale);
	setPosition(p);
	this->setScale(0.5);
	this->setPosition(VisibleRect::bottom() + Vec2((13 / 2 - 5) * 11, (14 - 13) * 5 + 100));
	this->addComponent(PhysicsBody::createBox(Size(48.0f, 108.0f)));
	this->getPhysicsBody()->setTag(128);
	this->getPhysicsBody()->setRotationEnable(false);
	this->getPhysicsBody()->setDynamic(true);
	this->getPhysicsBody()->getShape(0)->setFriction(30);
	this->getPhysicsBody()->getShape(0)->setRestitution(0.0);
	this->getPhysicsBody()->getShape(0)->setCategoryBitmask(0x0001);
	this->getPhysicsBody()->getShape(0)->setContactTestBitmask(0x0001);
	this->getPhysicsBody()->getShape(0)->setCollisionBitmask(0x0001);

	initPlayer();
}

void UserPlayer::AttackEnd(float dt){
	m_attackSprite->setVisible(false);
	m_attackSprite->getPhysicsBody()->setEnabled(false);
}
void UserPlayer::Attack(){


	m_attackSprite->setPosition(this->getPosition().x - 170, this->getPosition().y);
	m_attackSprite->setVisible(true);
	m_attackSprite->getPhysicsBody()->setEnabled(true);

	scheduleOnce(schedule_selector(UserPlayer::AttackEnd), 0.2f);
	//this->addChild(m_attackSprite);

}
void UserPlayer::Jump(){
	/*setRunState(true);
	setJumpState(jumpStart);*/
	if (m_state != kStatic)
		return;

	setPlayerState(kJump);

	if (m_direction == kLeft)
		this->getPhysicsBody()->setVelocity(Vec2(-100, 350));
	else if (m_direction == kRight)
		this->getPhysicsBody()->setVelocity(Vec2(100, 350));
}
void UserPlayer::Move(){
	//this->getPhysicsBody()->
	/*if (m_runState)
	this->setTexture(m_move1);
	else
	this->setTexture(m_move2);

	m_runState = !m_runState;*/
	//this->runAction(m_moveAnimate);
	//UserPlayerMove();
	//setRunState(true);
	if (m_state != kStatic)
		return;

	setPlayerState(kMove);
	if (m_direction == kLeft){
		auto move = MoveBy::create(100, Vec2(this->getPhysicsBody()->getPosition().x -20000, this->getPhysicsBody()->getPosition().y));
		this->runAction(RepeatForever::create(move));
	}
	else if (m_direction == kRight){
		auto move = MoveBy::create(100, Vec2(-this->getPhysicsBody()->getPosition().x +20000, this->getPhysicsBody()->getPosition().y));
		this->runAction(RepeatForever::create(move));
	}
}

void UserPlayer::endMove(){
	if (m_state == UserPlayer::kMove){
		setPlayerState(kStatic);
		this->stopAllActions();
	}
}
void UserPlayer::playerMove(){
	this->getPhysicsBody()->setVelocity(Vec2(50, 0));

	/*Vec2 curr_pos = this->getPosition();
	this->setPosition(Vec2(curr_pos.x +1, curr_pos.y));*/
}
void UserPlayer::reBound(){
	if (m_direction == kLeft)
		this->getPhysicsBody()->setVelocity(Vec2(-200, -100));
	
	else
		this->getPhysicsBody()->setVelocity(Vec2(200, -100));
}
void UserPlayer::getAttacked(){
	//setRunState(true);
	auto move = MoveBy::create(0.5, Vec2(VisibleRect::center().x, 0));
	//auto move_ease_in = EaseIn::create(move->clone(), 2.5f);
	auto action = Spawn::create(
		Blink::create(2, 10),
		move,
		nullptr);
	//auto blink = Blink::create(2, 10);
	this->runAction(action);


}
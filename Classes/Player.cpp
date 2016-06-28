#include "Player.h"

Player::Player(){
	m_direction = Player::kRight;
	m_state = Player::kStatic;
	m_hp = 3;	
	m_runState = true;
}

Player::~Player(){
}

Animation * Player::createAnimation(){
	auto animation = Animation::create();
	for (int i = 1; i<3; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "Images/grossini_dance_%02d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);

	return animation;
}

bool Player::initPlayer(){	
	/*auto animation = Animation::create();
	for (int i = 1; i<3; i++)
	{
		char szName[100] = { 0 };
		sprintf(szName, "Images/grossini_dance_%02d.png", i);
		animation->addSpriteFrameWithFile(szName);
	}
	animation->setDelayPerUnit(2.8f / 14.0f);
	animation->setRestoreOriginalFrame(true);*/
	//m_move1 = Texture2D

	m_move1 = Sprite::create("Images/grossini_dance_01.png")->getTexture();
	m_move2 = Sprite::create("Images/grossini_dance_05.png")->getTexture();

	auto cache = AnimationCache::getInstance();
	cache->addAnimationsWithFile("animations/animations-2.plist");
	auto animation2 = cache->getAnimation("dance_1");
	m_moveAnimate = Animate::create(animation2);
	/*m_jumpAnimate = Animate::create(createAnimation());
	m_AttackAnimate = Animate::create(createAnimation());*/

	/*m_attackSprite = Sprite::createWithTexture(m_move1);
	m_attackSprite->addComponent(PhysicsBody::createBox(Size(20.0f, 20.0f)));*/



	m_playerSprite = Sprite::createWithTexture(Sprite::create("Images/grossini.png")->getTexture(), Rect(0, 0, 85, 121));
	//m_playerSprite->createWithTexture(Sprite::create("Images/grossini.png")->getTexture(), Rect(0, 0, 85, 121));
	m_playerSprite->setScale(0.5);
	m_playerSprite->setPosition(VisibleRect::bottom() + Vec2((13 / 2 - 5) * 11, (14 - 13) * 5 + 100));
	m_playerSprite->addComponent(PhysicsBody::createBox(Size(48.0f, 108.0f)));
	m_playerSprite->getPhysicsBody()->setTag(128);
	m_playerSprite->getPhysicsBody()->setRotationEnable(false);
	m_playerSprite->getPhysicsBody()->setDynamic(true);
	m_playerSprite->getPhysicsBody()->getShape(0)->setFriction(30);
	m_playerSprite->getPhysicsBody()->getShape(0)->setRestitution(0.0);
	m_playerSprite->getPhysicsBody()->getShape(0)->setCategoryBitmask(0x0001);
	m_playerSprite->getPhysicsBody()->getShape(0)->setContactTestBitmask(0x0001);
	m_playerSprite->getPhysicsBody()->getShape(0)->setCollisionBitmask(0x0001);
	//this->getPhysicsBody()->addShape(PhysicsShapeBox::create(Size(48.0f, 108.0f)));

	//attackSprite
	m_attackSprite = Sprite::createWithTexture(m_move1);
	m_attackSprite->addComponent(PhysicsBody::createBox(Size(20.0f, 20.0f)));
	m_attackSprite->getPhysicsBody()->setRotationEnable(false);
	m_attackSprite->getPhysicsBody()->setDynamic(false);
	m_attackSprite->getPhysicsBody()->setEnabled(false);
	m_attackSprite->setPosition(m_playerSprite->getPosition().x - 150, m_playerSprite->getPosition().y);
	m_attackSprite->setVisible(false);
	m_playerSprite->addChild(m_attackSprite);


	return true;
}
void Player::AttackEnd(){
	m_attackSprite->setVisible(false);
	m_attackSprite->getPhysicsBody()->setEnabled(false);
}
void Player::Attack(){


	m_attackSprite->setPosition(m_playerSprite->getPosition().x-170 , m_playerSprite->getPosition().y);
	m_attackSprite->setVisible(true);
	m_attackSprite->getPhysicsBody()->setEnabled(true);



	//m_playerSprite->addChild(m_attackSprite);

}
void Player::Jump(){
	if (m_direction == kLeft)
		m_playerSprite->getPhysicsBody()->setVelocity(Vec2(-100, 350));
	else if (m_direction == kRight)
		m_playerSprite->getPhysicsBody()->setVelocity(Vec2(100, 350));
}
void Player::Move(){
	//m_playerSprite->getPhysicsBody()->
	/*if (m_runState)
		m_playerSprite->setTexture(m_move1);
	else
		m_playerSprite->setTexture(m_move2);

	m_runState = !m_runState;*/
	//m_playerSprite->runAction(m_moveAnimate);
	//playerMove();
	if (m_direction == kLeft)
		m_playerSprite->getPhysicsBody()->setVelocity(Vec2(-100, 0));
	else if (m_direction == kRight)
		m_playerSprite->getPhysicsBody()->setVelocity(Vec2(100, 0));
}
Player * Player::create(){
	Player * player = new Player();
	//_player = player;
	if (player) {
		//player->autorelease();
		//player->setSize();
		player->initPlayer();
		return player;
	}
	CC_SAFE_DELETE(player);
	return NULL;
}

void Player::endMove(){
	m_playerSprite->getPhysicsBody()->setVelocity(Vec2(0, 0));
}
void Player::playerMove(){
	m_playerSprite->getPhysicsBody()->setVelocity(Vec2(50, 0));

	/*Vec2 curr_pos = m_playerSprite->getPosition();
	m_playerSprite->setPosition(Vec2(curr_pos.x +1, curr_pos.y));*/
}
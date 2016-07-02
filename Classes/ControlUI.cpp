#include "ControlUI.h"
#include "AppMacros.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* ControlUI::scene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	ControlUI *layer = ControlUI::create();
	// add layer as a child to scene
	scene->addChild(layer);
	//scene->initWithPhysics();
	// return the scene
	return scene;
}
bool ControlUI::init(){
	if (!Layer::init())
	{
		return false;
	}	
	// Left walk button
	Button* button_left = Button::create("buttons_sprite/left_walk.png",
	"buttons_sprite/left_walk_press.png");
	button_left->setPosition(VisibleRect::leftBottom()+Vec2(50,20));
	//button->setZoomScale(0.4f);
	button_left->setPressedActionEnabled(true);
	button_left->addTouchEventListener(CC_CALLBACK_2(ControlUI::leftWalkTouchEvent, this));
	this->addChild(button_left);

	//Right walk button
	Button* button_right = Button::create("buttons_sprite/right_walk.png",
		"buttons_sprite/right_walk_press.png");
	button_right->setPosition(button_left->getPosition() + Vec2(50, 0));
	//button->setZoomScale(0.4f);
	button_right->setPressedActionEnabled(true);
	button_right->addTouchEventListener(CC_CALLBACK_2(ControlUI::rightWalkTouchEvent, this));
	this->addChild(button_right);

	//Left jump button
	Button* button_left_jump = Button::create("buttons_sprite/left_jump.png",
		"buttons_sprite/left_jump_press.png");
	button_left_jump->setPosition(button_left->getPosition() + Vec2(-25, 35));
	//button->setZoomScale(0.4f);
	button_left_jump->setPressedActionEnabled(true);
	button_left_jump->addTouchEventListener(CC_CALLBACK_2(ControlUI::leftJumpTouchEvent, this));
	this->addChild(button_left_jump);

	//straight jump button
	Button* button_jump = Button::create("buttons_sprite/straight_jump.png",
		"buttons_sprite/straight_jump_press.png");
	button_jump->setPosition(button_left_jump->getPosition() + Vec2(50, 0));
	//button->setZoomScale(0.4f);
	button_jump->setPressedActionEnabled(true);
	this->addChild(button_jump);

	//right jump button
	Button* button_right_jump = Button::create("buttons_sprite/right_jump1.png",
		"buttons_sprite/right_jump_press1.png");
	button_right_jump->setPosition(button_jump->getPosition() + Vec2(50, 0));
	//button->setZoomScale(0.4f);
	button_right_jump->setPressedActionEnabled(true);
	button_right_jump->addTouchEventListener(CC_CALLBACK_2(ControlUI::rightJumpTouchEvent, this));
	this->addChild(button_right_jump);


	//attack button;
	Button* button_attack = Button::create("buttons_sprite/attack.png",
		"buttons_sprite/attack_press.png");
	button_attack->setPosition(VisibleRect::rightBottom()+Vec2(-40,20));
	//button->setZoomScale(0.4f);
	button_attack->setPressedActionEnabled(true);
	button_attack->addTouchEventListener(CC_CALLBACK_2(ControlUI::attackTouchEvent, this));
	this->addChild(button_attack);

	//test button
	Button* button_test = Button::create("buttons_sprite/test.png",
		"buttons_sprite/test_press.png");
	button_test->setPosition(button_attack->getPosition() + Vec2(0, 35));
	//button->setZoomScale(0.4f);
	button_test->setPressedActionEnabled(true);
	button_test->addTouchEventListener(CC_CALLBACK_2(ControlUI::testTouchEvent, this));
	this->addChild(button_test);

	//Button

	//Button* button = Button::create("CloseNormal.png",
	//	"CloseSelected.png");
	///*CCLOG("content size should be greater than 0:  width = %f, height = %f", button->getContentSize().width,
	//	button->getContentSize().height);*/
	//button->setPosition(VisibleRect::center());
	//button->addTouchEventListener(CC_CALLBACK_2(ControlUI::touchEvent, this));
	//button->setZoomScale(0.4f);
	//button->setPressedActionEnabled(true);
	//this->addChild(button);

	
	return true;
}

void ControlUI::touchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		//m_gameLayer->startMovePlayer();
		break;

	case Widget::TouchEventType::MOVED:
		//_displayValueLabel->setString("Touch Moved");
		break;

	case Widget::TouchEventType::ENDED:
		//_displayValueLabel->setString("Touch Ended");
		//m_gameLayer->endMovePlayer();
		break;

	case Widget::TouchEventType::CANCELED:
		//_displayValueLabel->setString("Touch Canceled");
		break;

	default:
		break;
	}
}

void ControlUI::leftWalkTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		m_player->SetDirection(UserPlayer::kLeft);
		m_player->Move();
		if (!m_gameLayer->isFocus())
			m_gameLayer->focusOnPlayer();
		//m_gameLayer->startMovePlayer();
		break;
	case Widget::TouchEventType::MOVED:
		break;

	case Widget::TouchEventType::ENDED:
		m_player->endMove();
		//m_gameLayer->stopFocusOnPlayer();
		break;

	case Widget::TouchEventType::CANCELED:
		//_displayValueLabel->setString("Touch Canceled");
		break;
	default:
		break;
	}
}
void ControlUI::rightWalkTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:	
		m_player->SetDirection(UserPlayer::kRight);
		m_player->Move();
		if (!m_gameLayer->isFocus())
			m_gameLayer->focusOnPlayer();
		//m_gameLayer->startMovePlayer();
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		m_player->endMove();
		//m_gameLayer->stopFocusOnPlayer();	
		break;

	case Widget::TouchEventType::CANCELED:
		//_displayValueLabel->setString("Touch Canceled");
		break;
	default:
		break;
	}
}
void ControlUI::leftJumpTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:		
		m_player->SetDirection(UserPlayer::kLeft);
		m_player->Jump();
		if (!m_gameLayer->isFocus())
			m_gameLayer->focusOnPlayer();
		//m_gameLayer->startMovePlayer();
		break;
	case Widget::TouchEventType::MOVED:
		break;

	case Widget::TouchEventType::ENDED:
		break;

	case Widget::TouchEventType::CANCELED:
		//_displayValueLabel->setString("Touch Canceled");
		break;
	default:
		break;
	}
}
void ControlUI::rightJumpTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:	
		m_player->SetDirection(UserPlayer::kRight);
		m_player->Jump();
		if (!m_gameLayer->isFocus())
			m_gameLayer->focusOnPlayer();
		//m_gameLayer->startMovePlayer();
		break;
	case Widget::TouchEventType::MOVED:
		break;

	case Widget::TouchEventType::ENDED:
		break;
	case Widget::TouchEventType::CANCELED:
		//_displayValueLabel->setString("Touch Canceled");
		break;
	default:
		break;
	}
}
void ControlUI::attackTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		m_player->SetDirection(UserPlayer::kRight);
		m_player->Attack();
		//scheduleOnce(schedule_selector(ControlUI::endPlayerAttack), 0.2f);
		//m_gameLayer->startMovePlayer();
		break;
	case Widget::TouchEventType::MOVED:
		break;
	case Widget::TouchEventType::ENDED:
		break;
	case Widget::TouchEventType::CANCELED:
		//_displayValueLabel->setString("Touch Canceled");
		break;
	default:
		break;
	}
}
//void ControlUI::endPlayerAttack(float dt){
//	m_player->AttackEnd();
//}
void ControlUI::testTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
	case Widget::TouchEventType::BEGAN:
		m_gameLayer->focusOnPlayer();
		//m_player->SetDirection(UserPlayer::kLeft);
		//m_player->getAttacked();
		m_player->reBound();
		//m_gameLayer->startMovePlayer();
		break;
	case Widget::TouchEventType::MOVED:
		break;

	case Widget::TouchEventType::ENDED:
		break;

	case Widget::TouchEventType::CANCELED:
		//_displayValueLabel->setString("Touch Canceled");
		break;
	default:
		break;
	}
}
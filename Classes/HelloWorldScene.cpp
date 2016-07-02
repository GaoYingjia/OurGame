#include "HelloWorldScene.h"
#include "AppMacros.h"
#include "StagePropertyBase.h"

USING_NS_CC;



Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
	scene->initWithPhysics();
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
	ControlUI *layerControl = ControlUI::create();
	layerControl->SetGameLayer(layer);
	layerControl->SetPlayer(layer->getPlayerPtr());

    // add layer as a child to scene
	scene->addChild(layerControl);
    scene->addChild(layer);
	
	
	//Scene::initWithPhysics();
    // return the scene
    return scene;
}
namespace
{
	Color4F STATIC_COLOR(1.0f, 0.0f, 0.0f, 1.0f);
	const int DRAG_BODYS_TAG = 0x80;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	InitLayer();
	//loadBackGround();
	
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
    
    closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    //auto label = Label::createWithTTF("Hello World", "fonts/arial.ttf", TITLE_FONT_SIZE);
    //
    //// position the label on the center of the screen
    //label->setPosition(origin.x + visibleSize.width/2,
    //                        origin.y + visibleSize.height - label->getContentSize().height);

    //// add the label as a child to this layer
    //this->addChild(label, 1);
	
    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");

    //// position the sprite on the center of the screen
    //sprite->setPosition(Vec2(visibleSize / 2) + origin);

    //// add the sprite as a child to this layer
    //this->addChild(sprite);

	//
	scheduleOnce(CC_SCHEDULE_SELECTOR(HelloWorld::updateOnceTestScene), 1.0);
    return true;
}
//void  HelloWorld::movePlayer(float dt){
//	//Player::Instance()->Move();
//
//	//if (m_scale < 2.0){
//	//	this->setScale(m_scale);
//	//	m_scale += 0.01;
//	//}
//
//	m_userPlayer -> Move();
//	Vec2 pos = m_userPlayer->getPosition();
//	this->setPosition(-pos.x + VisibleRect::center().x, -pos.y + VisibleRect::center().y-100);
//}
cocos2d::Sprite* HelloWorld::addGrossiniAtPosition(cocos2d::Vec2 p, float scale/* = 1.0*/){
	//int posx, posy;

	//posx = CCRANDOM_0_1() * 200.0f;
	//posy = CCRANDOM_0_1() * 200.0f;

	//posx = (posx % 4) * 85;
	//posy = (posy % 3) * 121;

	auto sp = Sprite::createWithTexture(Sprite::create("Images/grossini.png")->getTexture(), Rect(0, 0, 85, 121));

	sp->setScale(scale);
	sp->setPosition(p);
	sp->addComponent(PhysicsBody::createBox(Size(48.0f, 108.0f)));
	sp->getPhysicsBody()->addShape(PhysicsShapeBox::create(Size(48.0f, 108.0f)));
	//HelloWorld::scene()->addChild(sp);
	addChild(sp);

	return sp;
}
void  HelloWorld::updateOnceTestScene(float delta){
	/*m_parNode=ParallaxNode::create();*/
	this->getScene()->getPhysicsWorld()->setGravity(Vec2(0, -750));
	//m_label->setString("xixixi");
	m_contactCount++;
	char buffer[10];
	sprintf(buffer, "%d", m_contactCount);
	m_label->setString(buffer);
	//Player::Instance()->
	
	//m_userPlayer->Jump();
	//schedule(CC_SCHEDULE_SELECTOR(HelloWorld::movePlayer), 0.07f);
	/*auto hero=this->getChildByTag(99);
	hero->getPhysicsBody()->setVelocity(Vec2(50,350));*/
}
//void HelloWorld::startMovePlayer(){
//	//m_userPlayer->Attack();
//	m_userPlayer->playerMove();
//	//schedule(CC_SCHEDULE_SELECTOR(HelloWorld::movePlayer), 0.01f);
//}
//void HelloWorld::endMovePlayer(){
//	m_userPlayer->endMove();
//	//m_userPlayer->AttackEnd();
//	//unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::movePlayer));
//}
void HelloWorld::onClickTest(Ref* sender){
	m_contactCount++;
	char buffer[10];
	sprintf(buffer, "%d", m_contactCount);
	m_label->setString(buffer);
	//this->setPosition(Vec2(m_contactCount, 0))
			
	
		;
}
void HelloWorld::toggleDebugCallback(cocos2d::Ref* sender){
	m_debugDraw = !m_debugDraw;
	this->getScene()->getPhysicsWorld()->setDebugDrawMask(m_debugDraw ? PhysicsWorld::DEBUGDRAW_ALL : PhysicsWorld::DEBUGDRAW_NONE);
}
bool HelloWorld::onContactBegin(cocos2d::PhysicsContact& contact){
	//PhysicsBody* a = contact.getShapeA()->getBody();
	//PhysicsBody* b = contact.getShapeB()->getBody();
	/*m_contactCount++;*/
	char buffer[10];
	sprintf(buffer, "beg");
	m_label->setString(buffer);
	/*if (m_userPlayer->getRunState()){
		m_userPlayer->getPhysicsBody()->setVelocity(Vec2(0.0, 0.0));
		m_userPlayer->setRunState(false);
	}*/
	//m_userPlayer->getPhysicsBody()->setDynamic(false);
	if (m_userPlayer->getPlayerState() == UserPlayer::kJump){
		m_userPlayer->setPlayerState(UserPlayer::kStatic);
		m_userPlayer->getPhysicsBody()->setVelocity(Vec2(0.0, 0.0));
		//m_userPlayer->setRunState(false);
	}
	/*PhysicsBody* a = contact.getShapeA()->getBody();
	PhysicsBody* b = contact.getShapeB()->getBody();

	if (a->getTag() == 128)
		a->setVelocity(Vec2(0.0, 0.0));
	else
		b->setVelocity(Vec2(0.0, 0.0));*/
	/*a->setResting(true);
	b->setResting(true);*/
	/*a->resetForces();
	b->resetForces();*/
	/*a->setDynamic(false);
	b->setDynamic(false);*/
	//PhysicsBody* body = (a->getCategoryBitmask() == 0x04 || a->getCategoryBitmask() == 0x08) ? a : b;
	//CC_UNUSED_PARAM(body);
	//CC_ASSERT(body->getCategoryBitmask() == 0x04 || body->getCategoryBitmask() == 0x08);

	return true;

}

void  HelloWorld::InitLayer(){
	//HelloWorld::scene()->getPhysicsWorld()->setGravity(Vec2(0, 99));
	
	m_focusOn = false;
	m_debugDraw = false;
	m_contactCount = 0;
	m_scale = 0.5;
	char buffer[10];

	sprintf(buffer, "%d", m_contactCount);
	m_label = Label::createWithTTF(buffer, "fonts/arial.ttf", 32);
	addChild(m_label, 1);

	
	auto s = VisibleRect::getVisibleRect().size;
	m_label->setPosition(Vec2(s.width / 2, s.height - 50));

	m_labelState = Label::createWithTTF("test", "fonts/arial.ttf", 32);
	m_labelState->setPosition(Vec2(s.width / 2, s.height - 100));
	addChild(m_labelState, 1);

	m_focusState = Label::createWithTTF("unFocus", "fonts/arial.ttf", 32);
	m_focusState->setPosition(Vec2(s.width / 2, s.height - 150));
	addChild(m_focusState, 1);
	//m_label->setString()

	//toggle click
	// menu for debug layer
	MenuItemFont::setFontSize(18);
	auto item = MenuItemFont::create("Toggle debug", CC_CALLBACK_1(HelloWorld::toggleDebugCallback, this));

	auto menu = Menu::create(item, nullptr);
	this->addChild(menu);
	menu->setPosition(Vec2(VisibleRect::right().x - item->getContentSize().width / 2 - 10, VisibleRect::top().y - item->getContentSize().height / 2 - 10));


	//click test
	MenuItemFont::setFontSize(35);
	//auto click = MenuItemFont::create("Click ", CC_CALLBACK_1(HelloWorld::onClickTest, this));
	////

	//auto menu1 = Menu::create(click, nullptr);
	//menu1->alignItemsHorizontally();
	//menu1->setPosition(Vec2(s.width / 2, s.height - 150));
	//addChild(menu1, 1);



	//back ground
	//m_parNode = ParallaxNode::create();
	////m_sp = cocos2d::Sprite::create();
	//	 
	//addChild(m_parNode);
	//addChild(m_sp);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	
	///bottom edge
	auto node = Node::create();
	node->addComponent(PhysicsBody::createEdgeSegment(VisibleRect::leftBottom() + Vec2(0, 50),
		VisibleRect::rightBottom() + Vec2(0, 50)));
	/*auto edgeShape = PhysicsShapeEdgeSegment::create(VisibleRect::leftBottom() + Vec2(0, 50),
		VisibleRect::rightBottom() + Vec2(0, 50));
	node->getPhysicsBody()->addShape(edgeShape);*/
	//node->getPhysicsBody()->
	node->getPhysicsBody()->getShape(0)->setRestitution(99);
	//node->getPhysicsBody()->getShape(0)->setFriction(99999);
	node->getPhysicsBody()->getShape(0)->setCategoryBitmask(0x0001);    // 0100
	node->getPhysicsBody()->getShape(0)->setContactTestBitmask(0x0001); // 0001
	node->getPhysicsBody()->getShape(0)->setCollisionBitmask(0x0001);   // 0110

	//top edge
	auto node2 = Node::create();
	node2->addComponent(PhysicsBody::createEdgeSegment(VisibleRect::leftTop() - Vec2(0, 50),
		VisibleRect::rightTop() -Vec2(0, 50)));
	/*node->addComponent(PhysicsBody::createEdgeSegment(VisibleRect::leftBottom() + Vec2(0, 50),
		VisibleRect::rightBottom() + Vec2(0, 50)));*/
	//node->drawSegment(VisibleRect::leftBottom() + Vec2(0, 50), VisibleRect::rightBottom() + Vec2(0, 50), 1, STATIC_COLOR);


	

	//Player *m_userPlayer1 = Player::create();
	////m_userPlayer1->setPosition(VisibleRect::bottom() + Vec2((13 / 2 - 13) * 11, (14 - 13) * 23 + 55));
	//addChild(m_userPlayer1);
	//add man///////////////

	//add user
	m_userPlayer = UserPlayer::create("Images/grossini.png");
	m_userPlayer->personalized(VisibleRect::bottom() + Vec2((13 / 2 - 5) * 11, (14 - 13) * 5 + 100), 0.5f);
	addChild(m_userPlayer);
	m_userPlayer->setTag(99);
	m_userPlayer->getPhysicsBody()->setTag(DRAG_BODYS_TAG);

	//thing test
	/*StagePropertyBase *m_sp = StagePropertyBase::create("Images/grossini.png");
	m_sp->personalized(VisibleRect::bottom() + Vec2((13 / 2 - 13) * 11, (14 - 13) * 23+55), 0.5f);
	addChild(m_sp);
	m_sp->setTag(99);
	m_sp->getPhysicsBody()->setTag(DRAG_BODYS_TAG);
*/
	auto contactListener2 = EventListenerPhysicsContactWithBodies::create(node->getPhysicsBody(), m_userPlayer->getPhysicsBody());
	//auto contactListener = EventListenerPhysicsContact::create();
	//contactListener->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
	contactListener2->onContactBegin = CC_CALLBACK_1(HelloWorld::onContactBegin, this);
	contactListener2->onContactPreSolve = CC_CALLBACK_1(HelloWorld::onContactPreSolve, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener2, this);
	///////////////////////////////////////////////
	/*PhysicsBody* box = PhysicsBody::create();
	box->setRotationEnable(false);
	node->addComponent(box);*/
	//box->addShape(PhysicsShapeEdgeBox::create(Size(VisibleRect::getVisibleRect().size.width - 10, VisibleRect::getVisibleRect().size.height - 50), PHYSICSSHAPE_MATERIAL_DEFAULT, 1));
	addChild(node);
	addChild(node2);
	//HelloWorld::scene()->addChild(node);
	
	/*HelloWorld::scene()->getPhysicsWorld()->*/
}
void HelloWorld::loadBackGround(){
	//auto background = Sprite::create(s_back);
	//// scale the image (optional)
	//background->setScale(1.5f);
	//// change the transform anchor point (optional)
	//background->setAnchorPoint(Vec2(0, 0));

	///*auto voidNode = ParallaxNode::create();*/
	//m_parNode->addChild(background, -1, Vec2(0.4f, 0.5f), Vec2::ZERO);
	////addChild(voidNode);
}
//void HelloWorld ::attackEnd(){
//	m_userPlayer->AttackEnd();
//}
void HelloWorld::menuCloseCallback(Ref* sender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	auto location = touch->getLocation();
	auto arr = this->getScene()->getPhysicsWorld()->getShapes(location);

	PhysicsBody* body = nullptr;
	for (auto& obj : arr)
	{
		if ((obj->getBody()->getTag() & DRAG_BODYS_TAG) != 0)
		{
			body = obj->getBody();
			break;
		}
	}

	if (body != nullptr)
	{
		Node* mouse = Node::create();
		auto physicsBody = PhysicsBody::create(PHYSICS_INFINITY, PHYSICS_INFINITY);
		physicsBody->setDynamic(false);
		mouse->addComponent(physicsBody);
		mouse->setPosition(location);
		this->addChild(mouse);
		PhysicsJointPin* joint = PhysicsJointPin::construct(physicsBody, body, location);
		joint->setMaxForce(5000.0f * body->getMass());
		this->getScene()->getPhysicsWorld()->addJoint(joint);
		_mouses.insert(std::make_pair(touch->getID(), mouse));

		return true;
	}

	return false;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	auto it = _mouses.find(touch->getID());

	if (it != _mouses.end())
	{
		it->second->setPosition(touch->getLocation());
	}
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	auto it = _mouses.find(touch->getID());

	if (it != _mouses.end())
	{
		this->removeChild(it->second);
		_mouses.erase(it);
	}
}
void HelloWorld::focusOnPlayer(){
	m_focusOn = true;
	schedule(CC_SCHEDULE_SELECTOR(HelloWorld::followPlayer), 0.01f);
}
//void HelloWorld::stopFocusOnPlayer(){
//	unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::followPlayer));
//}
void HelloWorld::followPlayer(float dt){
	//double test = m_contactCount
	m_contactCount++;
	Vec2 pos = m_userPlayer->getPosition();
	this->setPosition(-pos.x + VisibleRect::center().x, -pos.y + VisibleRect::center().y - 100);
	//this->setPosition(-pos.x + m_contactCount, -pos.y + VisibleRect::center().y - 100);
	//Vec2 vel = m_userPlayer->getPhysicsBody()->getVelocity();

	if (m_focusOn){
		m_focusState->setString("focusOn");
	}
	else{
		m_focusState->setString("unFocus");
	}

	if (m_userPlayer->getPlayerState() == UserPlayer::kStatic){
		m_contactCount++;
		/*char buffer[10];
		sprintf(buffer, "endtest%d", m_contactCount);
		m_label->setString(buffer);*/
		unschedule(CC_SCHEDULE_SELECTOR(HelloWorld::followPlayer));
		m_focusOn = false;
		m_focusState->setString("unFocus");
	}
	
	if (m_userPlayer->getPlayerState() == UserPlayer::kStatic){
		char buffer[10];
		sprintf(buffer, "static");
		m_labelState->setString(buffer);
	}
	else if (m_userPlayer->getPlayerState() == UserPlayer::kJump){
		char buffer[10];
		sprintf(buffer, "jump");
		m_labelState->setString(buffer);
	}
	else if (m_userPlayer->getPlayerState() == UserPlayer::kMove){
		char buffer[10];
		sprintf(buffer, "move");
		m_labelState->setString(buffer);
	}
	else{
		char buffer[10];
		sprintf(buffer, "undifine");
		m_labelState->setString(buffer);
	}
}
bool HelloWorld::onContactPreSolve(cocos2d::PhysicsContact& contact){
	//m_contactCount++;
	char buffer[10];
	sprintf(buffer, "%d",99);
	m_label->setString(buffer);

	//solve.ignore();
	m_userPlayer->getPhysicsBody()->setVelocity(Vec2(0.0, 0.0));
	if (m_userPlayer->getPlayerState() == UserPlayer::kJump){
		m_userPlayer->setPlayerState(UserPlayer::kStatic);
		m_userPlayer->getPhysicsBody()->setVelocity(Vec2(0.0, 0.0));
		//m_userPlayer->setRunState(false);
	}
	//if (m_userPlayer->getPlayerState() == UserPlayer::kJump)
	//PhysicsContactPreSolve::ignore();
	
	return true;
}
bool HelloWorld::onContactPostSolve(cocos2d::PhysicsContact& contact){
	//m_contactCount++;
	char buffer[10];
	sprintf(buffer, "%d",11);
	m_label->setString(buffer);

	m_userPlayer->getPhysicsBody()->setVelocity(Vec2(0.0, 0.0));
	


	return true;
}
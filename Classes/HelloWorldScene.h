#pragma once
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
#include "visiblerect.h"
#include "testresource.h"

#include "ControlUI.h"
#include "UserPlayer.h"

#if CC_USE_PHYSICS

class ControlUI;
class HelloWorld : public cocos2d::Layer
{
public:
    virtual bool init() override;

    static cocos2d::Scene* scene();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	void loadBackGround();
    // a selector callback
    void menuCloseCallback(Ref* sender);

	cocos2d::Sprite* addGrossiniAtPosition(cocos2d::Vec2 p, float scale = 1.0);

	void InitLayer();
	void updateOnceTestScene(float delta);
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	bool onContactPreSolve(cocos2d::PhysicsContact& contact);
	bool onContactPostSolve(cocos2d::PhysicsContact& contact);

	void toggleDebugCallback(cocos2d::Ref* sender);
	void onClickTest(Ref* sender);

	/*void startMovePlayer();
	void endMovePlayer();*/
	/*void movePlayer(float dt);*/
    // implement the "static create()" method manually
	
	/*void attackEnd();*/

	UserPlayer * getPlayerPtr(){
		return m_userPlayer;
	}
	
	void focusOnPlayer();
	//void stopFocusOnPlayer();

	void followPlayer(float dt);
    CREATE_FUNC(HelloWorld);

	bool isFocus(){
		return m_focusOn;
	}
private:
	//cocos2d::ParallaxNode* m_parNode;
	std::unordered_map<int, cocos2d::Node*> _mouses;
	int	m_contactCount;

	float m_scale;
	UserPlayer * m_userPlayer;
	cocos2d::Label* m_label;
	cocos2d::Label* m_labelState;
	cocos2d::Label* m_focusState;
	bool m_debugDraw;
	bool m_focusOn;
	//cocos2d::Sprite* m_sp;
};
#endif
#endif // __HELLOWORLD_SCENE_H__

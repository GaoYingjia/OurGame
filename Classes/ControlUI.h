#pragma once
#ifndef __CONTROL_UI_H__
#define __CONTROL_UI_H__
#include "cocos2d.h"
//#include "extensions/cocos-ext.h"
#include "visiblerect.h"
#include "ui/CocosGUI.h"
#include "editor-support/cocostudio/CocoStudio.h"
#include "Player.h"

typedef cocos2d::ui::Button Button;
typedef cocos2d::ui::Widget Widget;

class HelloWorld;
class ControlUI : public cocos2d::Layer{

public:
	CREATE_FUNC(ControlUI);
	virtual bool init() override;
	static cocos2d::Scene* scene();
	void touchEvent(Ref *pSender, Widget::TouchEventType type);
	void SetGameLayer(HelloWorld * layer){
		m_gameLayer = layer;
	}
	void SetPlayer(Player * player){
		m_player = player;
	}
public:
	void leftWalkTouchEvent(Ref *pSender, Widget::TouchEventType type);
	void rightWalkTouchEvent(Ref *pSender, Widget::TouchEventType type);
	void straightJumpTouchEvent(Ref *pSender, Widget::TouchEventType type);
	void leftJumpTouchEvent(Ref *pSender, Widget::TouchEventType type);
	void rightJumpTouchEvent(Ref *pSender, Widget::TouchEventType type);
	void attackTouchEvent(Ref *pSender, Widget::TouchEventType type);
private:
	void endPlayerAttack(float dt);
private:
	HelloWorld * m_gameLayer;
	Player * m_player;
	
};
#endif
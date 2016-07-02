#ifndef __USERPLAYER_H__
#define __USERPLAYER_H__

#include "cocos2d.h"
#include "visiblerect.h"
#include "testResource.h"
#include "StagePropertyBase.h"

USING_NS_CC;
#if CC_USE_PHYSICS

class UserPlayer :public StagePropertyBase{
public:
	typedef enum{
		jumpStart,
		jumpDone
	} PlayerJumpState;

	typedef enum
	{
		kLeft,
		kRight
	} PlayerDirection;
	typedef enum
	{
		kStatic,
		kMove,
		kFall,
		kJump,
		kAttack,
		kBeAttacked
	} PlayerState;

	bool initPlayer();
	//actiosn for player
	void setPlayerState(PlayerState state){
		m_state = state;
	}
	PlayerState getPlayerState(){
		return m_state;
	}

	void SetDirection(PlayerDirection dir){
		m_direction = dir;
	}
	
	
	void Move();
	void Jump();
	void Attack();

	void playerMove();
	void endMove();
	void getAttacked();
	void reBound();

	static UserPlayer* create(const std::string& filename);
	virtual void personalized(cocos2d::Vec2 p, float scale);//subclass override this func to modify componet shape category contact collision
private:
	void AttackEnd(float dt);
private:

	UserPlayer();
	~UserPlayer();
	//PlayerJumpState m_jumpState;
	PlayerDirection m_direction;
	PlayerState m_state;
	int m_hp;
	cocos2d::Sprite * m_attackSprite;
	//cocos2d::Sprite * m_playerSprite;
	//Animate * m_moveAnimate;
	//Animate * m_jumpAnimate;
	//Animate	* m_AttackAnimate;

	//bool m_runState;
	Texture2D * m_move1;
	Texture2D * m_move2;
};

#endif
#endif
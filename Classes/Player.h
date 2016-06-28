#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "visiblerect.h"
#include "testResource.h"

USING_NS_CC;
#if CC_USE_PHYSICS

class Player {
public:
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

	cocos2d::Sprite * returnSprite(){
		return m_playerSprite;
	}
	static Player * create(void);
	Animation * createAnimation();
	/*static Player * Instance(){
		return _player;
	}*/
	void SetDirection(PlayerDirection dir){
		m_direction = dir;
	}
	void Move();
	void Jump();
	void Attack();
	void AttackEnd();
	void playerMove();
	void endMove();
private:
	
	Player();
	~Player();
	
	//virtual void update(float dt);

	PlayerDirection m_direction;
	PlayerState m_state;
	int m_hp;
	cocos2d::Sprite * m_attackSprite;
	cocos2d::Sprite * m_playerSprite;
	Animate * m_moveAnimate;
	Animate * m_jumpAnimate;
	Animate	* m_AttackAnimate;

	bool m_runState;
	Texture2D * m_move1;
	Texture2D * m_move2;
	/*static Player * _player;*/
		//	Animation*
};
#endif
#endif
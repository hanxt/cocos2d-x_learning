#ifndef __BALL_SCENE_H__
#define __BALL_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class Ball : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual bool onTouchBegan(Touch* pTouches, Event* pEvent) override;

	// implement the "static create()" method manually
	CREATE_FUNC(Ball);


	void addNewSpriteAtPosition(Vec2 p);
	

};

#endif 


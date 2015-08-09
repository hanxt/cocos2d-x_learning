#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
private:
	cocos2d::Sprite* hour;
	cocos2d::Sprite* minute;
	cocos2d::Sprite* second;
private:
	cocos2d::Node* seekFromRootByName(cocos2d::Node* root, std::string& name);
	void HelloWorld::timeChanged(float dt);

};

#endif // __HELLOWORLD_SCENE_H__

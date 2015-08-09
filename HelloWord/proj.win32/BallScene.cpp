#include "BallScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

Scene* Ball::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	// 'layer' is an autorelease object
	auto layer = Ball::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Ball::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	//定义世界的边界
	auto body = PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT, 5.0f);                     
	auto edgeNode = Node::create();                                         
	edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));              
	edgeNode->setPhysicsBody(body);                                      
	this->addChild(edgeNode);
                                       
	//设置为单点触摸
	EventDispatcher* dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Ball::onTouchBegan, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}

bool Ball::onTouchBegan(Touch* pTouche, Event* pEvent){
	auto point = pTouche->getLocation();
	addNewSpriteAtPosition(point);

	return true;
}



void Ball::addNewSpriteAtPosition(Vec2 p)
{
	auto sp = Sprite::create("Ball.png");                                    
	sp->setTag(1);                                                      

	auto body = PhysicsBody::createCircle(sp->getContentSize().width / 2);              
	//auto body = PhysicsBody::createBox(sp->getContentSize());                      
	sp->setPhysicsBody(body);                                           
	sp->setPosition(p);
	addChild(sp);
}
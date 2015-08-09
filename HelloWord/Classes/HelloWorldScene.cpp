#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;

using namespace cocostudio::timeline;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
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
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	hour = dynamic_cast<Sprite*>(seekFromRootByName(rootNode, std::string("h")));
	minute = dynamic_cast<Sprite*>(seekFromRootByName(rootNode, std::string("m")));
	second = dynamic_cast<Sprite*>(seekFromRootByName(rootNode, std::string("s")));

	schedule(schedule_selector(HelloWorld::timeChanged), 1.0);

    return true;
}

Node* HelloWorld::seekFromRootByName(Node* root, std::string& name)
{
	if (!root)
		return nullptr;
	if (root->getName() == name)
		return root;

	const auto& arrayNode = root->getChildren();
	for (auto& child : arrayNode)
	{
		Node* pNode = dynamic_cast<Node*>(child);
		if (pNode)
		{
			Node* res = seekFromRootByName(pNode, name);
			if (res)
				return res;
		}
	}

	return nullptr;
}

void HelloWorld::timeChanged(float dt)
{
	static int cnt = 0;
	static float h = hour->getRotation();
	static float m = minute->getRotation();
	static float s = second->getRotation();

	s += 6.0;
	m += 0.1;
	cnt = ++cnt % 12;
	if (cnt == 0)
	{
		h += 0.1;
		hour->setRotation(h);
	}
	minute->setRotation(m);
	second->setRotation(s);
	SimpleAudioEngine::getInstance()->playEffect("clock.mp3");
}
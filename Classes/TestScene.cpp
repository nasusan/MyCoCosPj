#include "TestScene.h"

USING_NS_CC;

TestScene::TestScene()
{
}


TestScene::~TestScene()
{
}

Scene* TestScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// •\Ž¦•¨‚Ì’è‹`
	auto label = Label::createWithTTF("Hello World2", "fonts/Marker Felt.ttf", 24);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// position the label on the center of the screen
	label->setPosition(Vec2(	origin.x + visibleSize.width / 2,
								origin.y + visibleSize.height - label->getContentSize().height)	);
	
	// add layer as a child to scene
	scene->addChild(label,1);

	// return the scene
	return scene;
}



#include "HelloWorldScene.h"
#include "TestScene.h"
#include "base/ccMacros.h"

USING_NS_CC;

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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	// ��ʉE���ɕ\��
	// origin()=(0,0)����Ȃ����Ƃɒ��ӁB
	// �K���{origin ���Ă��Ȃ��Ƃ����Ȃ�
	// �f�t�H���g�̃A���J�[�|�C���g��Node�̒����̂��߁A����Q���Ă���
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto closeMenu = Menu::create(closeItem, NULL);
    closeMenu->setPosition(Vec2::ZERO);
    this->addChild(closeMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

#if 0
    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
#endif 

#if 0
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
#endif

#if 0
	/////////////////////////////////////////////////////////
	//  �e�X�g���j���[�쐬�����i�����܂ŉ��̂��́j
	//TestController* testController = new TestController();

	//�e�X�g���j���[�쐬
	TestItem* test = new TestItem();
	test->setTestName("test");

	//testController->add(test);

	// �����̕\��
	//testController->draw();

	// this->addChild(testController);
#endif


#if 0
	//�摜���g�������j���[�Ăяo����
	//menu���g���Ă݂�
	//	http://study-cocos2d-x.info/scenelayer/61/
	//�{�^�������������Ƀ����_�����Ăяo��
	//CC_CALLBACK_1�ł�OK
	auto mItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [](Ref*sender) {

		// create a scene. it's an autorelease object
		auto scene = TestScene::createScene();
		// run
		Director::getInstance()->pushScene(scene);
	});

	mItem->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));

	//���j���[���쐬
	auto testMenu = Menu::create(mItem, NULL);
	testMenu->setPosition(Point::ZERO);
	this->addChild(testMenu);
#endif 

#if 1
	//�e�L�X�g���j���[���g������
	//	http://study-cocos2d-x.info/scenelayer/61/

	float menuY = visibleSize.height - 16;

	// �e�X�g�P
	auto testName1 = LabelTTF::create("TEST 1", "Arial", 32);
	auto labelItem1 = MenuItemLabel::create(testName1, [](Ref*sender) {
		//�{�^�������������Ƀ����_�����Ăяo��
		//CC_CALLBACK_1�ł�OK
		auto scene = TestScene::createScene();
		Director::getInstance()->pushScene(scene);
	});
	labelItem1->setPosition(Point(visibleSize.width / 2, menuY ));

	// �e�X�g�Q
	auto testName2 = LabelTTF::create("TEST 2", "Arial", 32);
	auto labelItem2 = MenuItemLabel::create(testName2, [](Ref*sender) {
		//�{�^�������������Ƀ����_�����Ăяo��
		//CC_CALLBACK_1�ł�OK
		auto scene = TestScene::createScene();
		Director::getInstance()->pushScene(scene);
	});
	labelItem2->setPosition(Point(visibleSize.width / 2, menuY-32));

	// �e�X�g�R
	auto testName3 = LabelTTF::create("TEST 3", "Arial", 32);
	auto labelItem3 = MenuItemLabel::create(testName3, [](Ref*sender) {
		//�{�^�������������Ƀ����_�����Ăяo��
		//CC_CALLBACK_1�ł�OK
		auto scene = TestScene::createScene();
		Director::getInstance()->pushScene(scene);
	});
	labelItem3->setPosition(Point(visibleSize.width / 2, menuY-32*2));

	//���j���[���쐬
	auto testMenu = Menu::create(labelItem1, labelItem2, labelItem3, NULL);
	testMenu->setPosition(Point::ZERO);
	this->addChild(testMenu);

#endif 

    return true;
}

 
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

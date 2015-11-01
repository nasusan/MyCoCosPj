#pragma once
#include "cocos2d.h"

/**
*Å¶éQçlÅ@/cocos2d/build/cpp_test/MenuTest.h
*/
class TestItem :
	public cocos2d::Layer
{
public:
	TestItem();
	~TestItem();

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	
	void setTestName(const std::string& testName) { _testName = testName; }
	std::string getTestName() const { return _testName; }

private:
	std::string _testName;
};


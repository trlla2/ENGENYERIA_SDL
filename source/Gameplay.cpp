#include "Gameplay.h"
#include "TestObject.h "

void Gameplay::OnEnter()
{
	TestObject* test1 = new TestObject();
	_objects.push_back(test1);
	TestObject* test2 = new TestObject();
	_objects.push_back(test2);
}

void Gameplay::OnExit() { Scene::OnExit(); }

void Gameplay::Update(float dt) { Scene::Update(dt); }

void Gameplay::Render() { Scene::Render(); }

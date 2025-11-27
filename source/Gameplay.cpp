#include "Gameplay.h"
#include "TestObject.h "
#include "TextObject.h"

void Gameplay::OnEnter()
{
	SPAWNER.SpawnObject(new TestObject());
	SPAWNER.SpawnObject(new TestObject());

	TextObject* temp = new TextObject("Press S to apply force Press R to apply torque");
	temp->GetTransform()->_position = Vector2(100.f, 100.f);
	_ui.push_back(temp);
}

void Gameplay::OnExit() { Scene::OnExit(); }

void Gameplay::Update(float dt) { Scene::Update(dt); }

void Gameplay::Render() { Scene::Render(); }

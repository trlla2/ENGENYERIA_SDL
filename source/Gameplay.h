#pragma once
#include "Scene.h"

class Gameplay : public Scene
{
public:
	Gameplay() = default;

	void OnEnter() override;
	void OnExit() override;
	void Update(float dt) override;
	void Render() override;
};


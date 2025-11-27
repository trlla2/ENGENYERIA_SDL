#pragma once
#include <unordered_map>
#include "Scene.h"




#define SM SceneManager::Instance()

class SceneManager
{
private:
	SceneManager() = default;
	SceneManager(SceneManager&) = delete;
	SceneManager& operator =(const SceneManager&) = delete;

public:
	static SceneManager& Instance()
	{
		static SceneManager instance;
		return instance;
	}

private:
	std::unordered_map < std::string, Scene* > _scenes;
	Scene* _currentScene = nullptr;
	std::string _nextScene = "";
public:
	bool AddScene(std::string name, Scene* scene)
	{
		if (_scenes.find(name) == _scenes.end())
		{

			_scenes.emplace(name, scene);
			return true;
		}

		return false;
	}

	Scene* GetScene(const std::string name)
	{
		if (_scenes.find(name) != _scenes.end())
			return _scenes[name];
		return nullptr;
	}

	bool InitFirstScene(const std::string name)
	{
		if (_scenes.find(name) != _scenes.end())
		{
			_currentScene = _scenes[name];
			_currentScene->OnEnter();
			return true;
		}

		return false;
	}

	Scene* GetCurrentScene() const { return _currentScene; }

	bool SetNextScene(std::string name)
	{
		if (_scenes.find(name) != _scenes.end())
			return false;

		_nextScene = name;

		return true;
	}

	void UpdateCurrentScene(float dt)
	{
		if (_nextScene != "")
		{
			_currentScene->OnExit();
			_currentScene = _scenes[_nextScene];
			_currentScene->OnEnter();
			_nextScene = "";
		}

		_currentScene->Update(dt);
	}
};


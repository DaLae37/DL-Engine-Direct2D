#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager() {
	currentScene = nullptr;
}

SceneManager::~SceneManager() {
	SAFE_DELETE(currentScene);
}

void SceneManager::Render() {
	currentScene->Render();
}

void SceneManager::Update(float dTime) {
	currentScene->Update(dTime);
}

void SceneManager::ChangeScene(Scene* scene, std::string sceneName = "scene", bool deleteBeforeScene = false) {
	if (deleteBeforeScene) {
		SAFE_DELETE(currentScene);
		scenes.erase(sceneName);
	}

	scene->LoadResourceData();
	scene->LoadResourceFromFiles();
	currentScene = scene;

	if (scenes.find(sceneName) != scenes.end()) {
		SAFE_DELETE(scenes[sceneName]);
		scenes.erase(sceneName);
	}
	else {
		scenes[sceneName] = scene;
	}
}

void SceneManager::WaitThreadsEnd() {
	int numThreads = loadingThreads.size();
	for (int i = 0; i < numThreads; i++) {
		loadingThreads[i]->join();
	}
}

D2D_COLOR_F SceneManager::GetCurrentSceneBackgroundColor() {
	return currentScene->getBackgroundColor();
}
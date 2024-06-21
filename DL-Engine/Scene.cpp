#include "stdafx.h"
#include "Scene.h"

Scene::Scene() {
	backgroundColor = { 1.0f, 1.0f, 1.0f, 1.0f };
}

Scene::~Scene() {
	for (auto& object : objectList) {
		SAFE_DELETE(object);
	}
	for (auto& ui : uiList) {
		SAFE_DELETE(ui);
	}
}

void Scene::Render() {
	for (auto& object : objectList) {
		object->Render();
	}

	for (auto& ui : uiList) {
		ui->Render();
	}
}

void Scene::Update(float dTime) {
	for (auto& object : objectList) {
		object->Update(dTime);
	}

	for (auto& ui : uiList) {
		ui->Update(dTime);
	}
}

void Scene::AddObject(Object* object) {
	objectList.push_back(object);
	object->setParent(nullptr);
}

void Scene::RemoveObject(Object* object) {
	objectList.remove(object);
}

void Scene::AddUI(Object* ui) {
	uiList.push_back(ui);
	ui->setParent(nullptr);
}

void Scene::RemoveUI(Object* ui) {
	uiList.remove(ui);
}

void Scene::setBackgroundColor(D2D_COLOR_F backgroundColor) {
	this->backgroundColor = backgroundColor;
}

D2D1_COLOR_F Scene::getBackgroundColor() {
	return backgroundColor;
}
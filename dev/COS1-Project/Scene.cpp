#include "Scene.h"

Scene::Scene(
	const std::string& sceneTitle,
	const std::string& sceneDescription)
{
	title = sceneTitle;
	description = sceneDescription;
}

void Scene::AddChoice(
	const std::string& choiceText,
	int nextScene)
{
	Choice newChoice;

	newChoice.text = choiceText;
	newChoice.nextScene = nextScene;

	choices.push_back(newChoice);
}
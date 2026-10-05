#pragma once

#include <string>
#include <vector>

struct Choice
{
    std::string text;
    int nextScene;
};

class Scene
{
private:
    std::string title;
    std::string description;
    std::vector<Choice> choices;

public:
    Scene(
        const std::string& sceneTitle,
        const std::string& sceneDescription
    );

    void AddChoice(const std::string& choiceText, int nextScene);

    std::string GetTitle() const;
    std::string GetDescription() const;
    const std::vector<Choice>& GetChoices() const;
};
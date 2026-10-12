#pragma once
#include <set>

enum class PlayerStat
{
    Hunting,
    Lore,
    Perception,
    Courage,
    Charisma,
    Stealth
};

class Player
{
private:

    int hunting = 0;
    int lore = 0;
    int perception = 0;
    int courage = 0;
    int charisma = 0;
    int stealth = 0;

    std::set<int> mCollectedNotebookPages;

public:

    // Getters
    int GetHunting() const;
    int GetLore() const;
    int GetPerception() const;
    int GetCourage() const;
    int GetCharisma() const;
    int GetStealth() const;

    // Skill Check System
    bool CheckStat(PlayerStat stat, int requiredLevel) const;

    // Increase stats
    void IncreaseHunting();
    void IncreaseLore();
    void IncreasePerception();
    void IncreaseCourage();
    void IncreaseCharisma();
    void IncreaseStealth();

    // Lore System
    bool CollectNotebookPage(int pageNumber);
    bool HasNotebookPage(int pageNumber) const;
    int GetNotebookPageCount() const;
    bool HasCompleteNotebook() const;
};
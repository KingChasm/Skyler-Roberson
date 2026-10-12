#include "Player.h"

// Getters

int Player::GetHunting() const
{
	return hunting;
}

int Player::GetLore() const
{
	return lore;
}

int Player::GetPerception() const
{
	return perception;
}

int Player::GetCourage() const
{
	return courage;
}

int Player::GetCharisma() const
{
	return charisma;
}

int Player::GetStealth() const
{
	return stealth;
}

// Increase stats

void Player::IncreaseHunting()
{
	if (hunting < 10)
	{
		hunting++;
	}
}

void Player::IncreaseLore()
{
	if (lore < 10)
	{
		lore++;
	}
}

void Player::IncreasePerception()
{
	if (perception < 10)
	{
		perception++;
	}
}

void Player::IncreaseCourage()
{
	if (courage < 10)
	{
		courage++;
	}
}

void Player::IncreaseCharisma()
{
	if (charisma < 10)
	{
		charisma++;
	}
}

void Player::IncreaseStealth()
{
	if (stealth < 10)
	{
		stealth++;
	}
}

// =============================
// Collectible Lore System
// =============================

// Collects a notebook page if it is valid and not already collected.
bool Player::CollectNotebookPage(int pageNumber)
{
	// Only pages 1, 2, and 3 exist at this time; potentially adding more as I increase the 
	// scene amount.
	if (pageNumber < 1 || pageNumber > 3)
	{
		return false;
	}

	// insert().second is true if the page was newly added.
	return mCollectedNotebookPages.insert(pageNumber).second;
}

// Checks whether the player already has a specific page.
bool Player::HasNotebookPage(int pageNumber) const
{
	return mCollectedNotebookPages.contains(pageNumber);
}

// Returns the number of unique notebook pages collected.
int Player::GetNotebookPageCount() const
{
	return static_cast<int>(mCollectedNotebookPages.size());
}

// Checks whether the player has collected all pages; again, currently only 3 pages exist Mrs. Asphodel.
bool Player::HasCompleteNotebook() const
{
	return GetNotebookPageCount() == 3;
}

// ============================================
// Skill Check System
// ============================================

bool Player::CheckStat(PlayerStat stat, int requiredLevel) const
{
	switch (stat)
	{
	case PlayerStat::Hunting:
		return GetHunting() >= requiredLevel;

	case PlayerStat::Lore:
		return GetLore() >= requiredLevel;

	case PlayerStat::Perception:
		return GetPerception() >= requiredLevel;

	case PlayerStat::Courage:
		return GetCourage() >= requiredLevel;

	case PlayerStat::Charisma:
		return GetCharisma() >= requiredLevel;

	case PlayerStat::Stealth:
		return GetStealth() >= requiredLevel;

	default:
		return false;
	}
}
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

using namespace std;

////////////////////////////////////////////////////////////////////////////////
								// Card //
////////////////////////////////////////////////////////////////////////////////
class Card
{
public:
	friend ostream& operator<<(ostream&, Card&);
	Card(){}
	~Card(){}
	Card(int n, int s)
	{
		_num = static_cast<Card::number>(n);
		_suit = static_cast<Card::suit>(s);
	}
	void Flip()
	{
		if (position == true)
			position = false;
		else
			position = true;
	}

	bool IsFaceUp()
	{
		return position;
	}

	int GetValue()
	{
		return _num;
	}

protected:
	enum suit { clubs, diamonds, hearts, spades } _suit;
	enum number { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king } _num;
	bool position;
};

ostream& operator<<(ostream& os, Card& c)
{
	if (c.IsFaceUp())
	{
		os << "XX";
	}
	else
	{

		if (c._num >= 2 && c._num < 10)
		{
			os << c._num << " suit  " << c._suit;
		}
		else
		{
			switch (c._num)
			{
			case Card::jack: os << "J"; break;
			case Card::queen: os << "Q"; break;
			case Card::king: os << "K"; break;
			case Card::ace: os << "A"; break;
			}
			os << c._num;
		}

		switch (c._suit)
		{
		case Card::clubs: os << static_cast<char>(5); break;
		case Card::diamonds: os << static_cast<char>(4); break;
		case Card::hearts: os << static_cast<char>(3); break;
		case Card::spades: os << static_cast<char>(6); break;
		}
	}
	return os;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
								// Hand //
////////////////////////////////////////////////////////////////////////////////
class Hand :public Card
{
public:
	Hand(){}
	~Hand(){}
	void Add(Card* newCard)
	{
		hand.push_back(newCard);
	}
	void Clear()
	{
		hand.clear();
	}
	int getValue()
	{
		int sumAce = 0;
		int sum = 0;
		for (size_t i = 0; i < hand.size(); i++)
		{
			if ((hand[i]->GetValue()) == 1)
			{
				sumAce++;
				sum += hand[i]->GetValue();
			}
			else
			{
				if ((hand[i]->GetValue() == jack) || (hand[i]->GetValue() == queen) || (hand[i]->GetValue() == king))
					sum += 0;
				else
					sum += hand[i]->GetValue();
			}
		}
		if (sum <= 11 && sumAce > 0)
		{
			sum += 10;
		}
		return sum;
	}
protected:
	vector<Card*> hand;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
								// GenericPlayer //
////////////////////////////////////////////////////////////////////////////////
class GenericPlayer :public Hand
{
public:
	friend ostream& operator<<(ostream&, GenericPlayer&);
	virtual bool IsHitting() = 0;
	bool IsBoosted()
	{
		if (Hand::getValue() > 21)
			return true;
		else
			return false;
	}
	void Bust()
	{
		cout << name << " перебор !" << endl;
	}

protected:
	string name;
};

ostream& operator<<(ostream& os, GenericPlayer& gp)
{
	os << gp.name << ": " << gp.getValue() << " - ";
	for (vector<int>::size_type i = 0; i != gp.hand.size(); i++)
	{
		os << *gp.hand[i] << ", ";
	}
	return os;
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
								// Player //
////////////////////////////////////////////////////////////////////////////////
class Player :public GenericPlayer
{
public:
	Player(){}
	Player(const string& _name)
	{
		name = _name;
	}
	virtual ~Player(){}

	virtual bool IsHitting() override
	{
		char s;
		cout << "Нужна ещё карта (y/n) ?: ";
		cin >> s;
		if (s == 'y')
		{
			return true;
		}
		return false;
	}

	void Win()
	{
		cout << "Игрок " << name << " выиграл" << endl;
	}

	void Lose()
	{
		cout << "Игрок " << name << " проиграл" << endl;
	}

	void Push()
	{
		cout << "Игрок " << name << " сыграл вничью" << endl;
	}

};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
								// House //
////////////////////////////////////////////////////////////////////////////////
class House :public GenericPlayer
{
public:
	virtual bool IsHitting() override
	{
		return(getValue() <= 16);
	}

	virtual ~House()
	{}
	void FlipFirstCard()
	{
		if (hand.empty())
		{
			cout << "No card !" << endl;
		}
		else
		{
			hand[0]->Flip();
		}
	}
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
								// Deck //
////////////////////////////////////////////////////////////////////////////////
class Deck :public Hand
{
public:
	Deck()
	{
		hand.reserve(52);
		Populate();
	}
	~Deck(){}
	void Populate()
	{
		Clear();
		for (int s = Card::clubs; s <= Card::spades; s++)
		{
			for (int n = Card::ace; n <= Card::king; n++)
			{
				Add(new Card(static_cast<Card::number>(n), static_cast<Card::suit>(s)));
			}
		}
	}
	void Shuffle()
	{
		random_shuffle(hand.begin(), hand.end());
	}
	void Deal(Hand& aHand)
	{
		if (!hand.empty())
		{
			aHand.Add(hand.back());
			hand.pop_back();
		}
		else
		{
			cout << "Out of cards. Unable to deal.";
		}

	}
	void AdditionalCards(GenericPlayer& _GenericPlayer)
	{
		while (!(_GenericPlayer.IsBoosted()) && _GenericPlayer.IsHitting())
		{
			Deal(_GenericPlayer);
			cout << _GenericPlayer << endl;
			if (_GenericPlayer.IsBoosted())
			{
				_GenericPlayer.Bust();
			}
		}
	}
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
								// Game //
////////////////////////////////////////////////////////////////////////////////
class Game
{
public:
	Game(const vector<string>& names)
	{
		vector<string>::const_iterator pName;
		for (pName = names.begin(); pName != names.end(); ++pName)
		{
			m_Players.push_back(Player(*pName));
		}
		srand(static_cast<unsigned int>(time(0)));
		m_Deck.Populate();
		m_Deck.Shuffle();
	}
	~Game(){}
	void Play()
	{
		vector<Player>::iterator pPlayer;
		for (int i = 0; i < 2; ++i)
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			{
				m_Deck.Deal(*pPlayer);
			}
			m_Deck.Deal(m_House);
		}
		m_House.FlipFirstCard();
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			cout << *pPlayer << endl;
		}
		cout << m_House << endl;
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.AdditionalCards(*pPlayer);
		}
		m_House.FlipFirstCard();
		cout << endl << m_House;
		m_Deck.AdditionalCards(m_House);
		if (m_House.IsBoosted())
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			{
				if (!(pPlayer->IsBoosted()))
				{
					pPlayer->Win();
				}
			}
		}
		else
		{
			for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			{
				if (!(pPlayer->IsBoosted()))
				{
					if (pPlayer->getValue() > m_House.getValue())
					{
						pPlayer->Win();
					}
					else if (pPlayer->getValue() < m_House.getValue())
					{
						pPlayer->Lose();
					}
					else
					{
						pPlayer->Push();
					}
				}
			}
		}
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			pPlayer->Clear();
		}
		m_House.Clear();
	}
private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
};
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
								// main //
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "\t\tWelcome to Blackjack!\n\n";
	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7)
	{
		cout << "How many players? (1 - 7): ";
		cin >> numPlayers;
	}
	vector<string> names;
	string name;
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
	}
	cout << endl;
	Game aGame(names);
	char again = 'y';
	while (again != 'n' && again != 'N')
	{
		aGame.Play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
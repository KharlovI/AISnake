#include "Utilities.h"
bool AllSnakesIsDead(Snake snakes[], int count)
{
	for (int i = 0; i < count; i++)
	{
		if (snakes[i].GetAliveStatus())
			return 0;
	}

	return 1;
}
int FirstAction(std::vector<Button> b, sf::RenderWindow& w, int& FPS, sf::Sprite& appleSprite, sf::Sprite& backgroundSprite, std::vector<sf::Sprite> snakeSprites)
{
	Snake snake;
	Apple apple;
	apple.SetSprite(appleSprite);
	snake.SetApple(apple);

	snake.AddSprites(snakeSprites);
    snake.UpdateSprites(snakeSprites);
	while (w.isOpen())
	{
		sf::Event event;

		if (w.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				w.close();
				return 0;
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mp = sf::Mouse::getPosition(w);

				for (int i = 0; i < b.size(); i++)
					b[i].SetIsPressed(mp);

				if (b[0].IsPressed())
				{
					return 1;
				}

				else if (b[1].IsPressed())
				{
					return 2;
				}

				else if (b[2].IsPressed())
				{
					return 3;
				}

				else if (b[3].IsPressed())
				{
					if (FPS < 150)
					{
						FPS += 5;
						w.setFramerateLimit(FPS);
					}
				}

				else if (b[4].IsPressed())
				{
					if (FPS > 14)
					{
						FPS -= 5;
						w.setFramerateLimit(FPS);
					}
				}
			}
		}

		w.clear();

        w.draw(backgroundSprite);
		snake.PrintSnakeSprites(w);
		apple.PrintAppleSprite(w);

		if (snake.GetAliveStatus())
		{
			if (snake.MoveAI(apple))
			{
				snake.AddSprites(snakeSprites);
				snake.UpdateSprites(snakeSprites);
			}

			snake.UpdateSprites(snakeSprites);
			snake.SetIsAliveStatus();
			snake.IncrementSteps();
		}

		else
		{
			std::cout << snake.GetGeneration() << " " << snake.GetCountOfApple() << std::endl;
			Snake snake3;
			snake = snake3;
			snake.AddSprites(snakeSprites);
            snake.UpdateSprites(snakeSprites);
			snake.SetApple(apple);
		}

		for (int i = 0; i < b.size(); i++)
		{
			b[i].Draw(w);
		}

		w.display();
	}

	return -1;
}
int SecondAction(std::vector<Button> b, sf::RenderWindow& w, int& FPS, sf::Sprite& appleSprite, std::vector<sf::Sprite> snakeSprites)
{
	const int countOfSnakes = 100;
	int maxValue = 70;

	Snake snake[countOfSnakes];
	for (int i = 0; i < countOfSnakes; i++)
	{
		Snake temp;
		snake[i] = temp;
	}
	Apple apple[countOfSnakes];

	for (int i = 0; i < countOfSnakes; i++)
		snake[i].SetApple(apple[i]);

	while (w.isOpen())
	{
		sf::Event event;

		if (w.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				w.close();
				return 0;
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mp = sf::Mouse::getPosition(w);

				for (int i = 0; i < b.size(); i++)
					b[i].SetIsPressed(mp);

				if (b[0].IsPressed())
				{
					return 1;
				}

				else if (b[1].IsPressed())
				{
					return 2;
				}

				else if (b[2].IsPressed())
				{
					return 3;
				}

				else if (b[3].IsPressed())
				{
					if (FPS < 150)
					{
						FPS += 5;
						w.setFramerateLimit(FPS);
					}
				}

				else if (b[4].IsPressed())
				{
					if (FPS > 14)
					{
						FPS -= 5;
						w.setFramerateLimit(FPS);
					}
				}
			}
		}

		w.clear();

		for (int i = 0; i < countOfSnakes; i++)
		{
			if (snake[i].GetAliveStatus())
			{
				snake[i].PrintSnake(w);
				apple[i].PrintAppleShape(w);							// PrintAppleSprite
			}
		}

		for (int i = 0; i < countOfSnakes; i++)
		{
			if (snake[i].GetAliveStatus())
			{
				snake[i].MoveAI(apple[i]);
				snake[i].SetIsAliveStatus();
				snake[i].IncrementSteps();
			}
		}

		if (AllSnakesIsDead(snake, countOfSnakes))
		{
			int generation = snake[0].GetGeneration();
			std::cout << "Generation: " << generation << std::endl;

			for (int i = 0; i < countOfSnakes; i++)
			{
				snake[i].CalculateTotalScore();
			}

			Genotype* best = GetBestParents(snake, countOfSnakes, maxValue);
			std::cout << std::endl;

			for (int i = 0; i < countOfSnakes; i++)
			{
				Snake snake2{ best , generation };
				snake[i] = snake2;
			}

			for (int i = 0; i < countOfSnakes; i++)
				snake[i].SetApple(apple[i]);
		}
		for (int i = 0; i < b.size(); i++)
		{
			b[i].Draw(w);
		}

		w.display();
	}

	return -1;
}
int ThirdAction(std::vector<Button> b, sf::RenderWindow& w, int& FPS, sf::Sprite& appleSprite, sf::Sprite& backgroundSprite, std::vector<sf::Sprite> snakeSprites)
{
	Snake snake(1);
	Apple apple;
	apple.SetSprite(appleSprite);
	snake.SetApple(apple);

	snake.AddSprites(snakeSprites);
	snake.UpdateSprites(snakeSprites);

	while (w.isOpen())
	{
		sf::Event event;

		if (w.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				w.close();
				return 0;
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i mp = sf::Mouse::getPosition(w);

				for (int i = 0; i < b.size(); i++)
					b[i].SetIsPressed(mp);

				if (b[0].IsPressed())
				{
					return 1;
				}

				else if (b[1].IsPressed())
				{
					return 2;
				}

				else if (b[2].IsPressed())
				{
					return 3;
				}

				else if (b[3].IsPressed())
				{
					if (FPS < 150)
					{
						FPS += 5;
						w.setFramerateLimit(FPS);
					}
				}

				else if (b[4].IsPressed())
				{
					if (FPS > 14)
					{
						FPS -= 5;
						w.setFramerateLimit(FPS);
					}
				}
			}
		}

		w.clear();

        w.draw(backgroundSprite);
		snake.PrintSnakeSprites(w);
		apple.PrintAppleSprite(w);

		if (snake.GetAliveStatus())
		{
			if (snake.MoveAI(apple))
			{
				snake.AddSprites(snakeSprites);
				snake.UpdateSprites(snakeSprites);
			}
			snake.UpdateSprites(snakeSprites);
			snake.SetIsAliveStatus();
			snake.IncrementSteps();
		}

		else
		{
			std::cout << snake.GetGeneration() << " " << snake.GetCountOfApple() << std::endl;
			Snake snake3{ 1 };
			snake = snake3;
			snake.SetApple(apple);
			snake.AddSprites(snakeSprites);
			snake.UpdateSprites(snakeSprites);
		}

		for (int i = 0; i < b.size(); i++)
		{
			b[i].Draw(w);
		}

		w.display();
	}

	return -1;
}
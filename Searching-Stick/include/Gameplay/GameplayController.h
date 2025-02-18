#pragma once

namespace Gameplay
{
	class GameplayView;

	class GameplayController
	{
	private:

		GameplayView* gameplay_view;

		void destroy();
	public:

		GameplayController();
		~GameplayController();

		void initialize();
		void render();
		void update();

		void reset();
	};
}
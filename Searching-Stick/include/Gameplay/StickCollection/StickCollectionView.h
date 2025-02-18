#pragma once

namespace Gameplay
{
	namespace Collection
	{
		class StickCollectionView
		{
		private:

			void destroy();

		public:
			StickCollectionView();
			~StickCollectionView();

			void initialize();
			void render();
			void update();

		};
	}
}
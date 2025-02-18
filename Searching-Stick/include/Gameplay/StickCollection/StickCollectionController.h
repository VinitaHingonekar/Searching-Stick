#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>
#include <string>

namespace Gameplay {

    namespace Collection {

        class StickCollectionModel;
        class StickCollectionView;
        enum class SearchType;
        struct Stick;

        class StickCollectionContoller {

        private:
            StickCollectionView* collection_view;
            StickCollectionModel* collection_model;

            std::vector<Stick*> sticks;
            Stick* stick_to_search;

            Collection::SearchType search_type;

            int number_of_comparisons;
            int number_of_array_access;

            int current_operation_delay;

            std::thread search_thread;

            int delay_in_ms;
            sf::String time_complexity;

            void processSearchThreadState();
            void joinThreads();

            void initializeSticks();
            float calculateStickWidth();

            void updateSticksPosition();
            void shuffleSticks();

            void resetSticksColor();
            void resetVariables();
            void resetSearchStick();

            void processLinearSearch();
            void processBinarySearch();

            void initializeSticksArray();
            float calculateStickHeight(int array_pos);

            void sortElements();
            bool compareElementsByData(const Stick* a, const Stick* b) const;

            void destroy();

        public:

            StickCollectionContoller();
            ~StickCollectionContoller();

            void initialize();
            void update();
            void render();

            void reset();
            void searchElement(SearchType search_type);

            SearchType getSearchType();
            int getNumberOfComparisons();
            int getNumberOfArrayAccess();

            int getNumberOfSticks();

            int getDelayMilliseconds();
            std::string getTimeComplexity();
        };
    }


}
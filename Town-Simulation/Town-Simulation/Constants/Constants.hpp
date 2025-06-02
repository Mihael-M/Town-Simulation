#ifndef Constants_hpp
#define Constants_hpp

#include <stdio.h>

namespace Constants {
static constexpr int MAX_NUMBER_TYPES = 10;
static constexpr size_t DEFAULT_INITIAL_RESIDENTS = 8;
static constexpr size_t MAX_INITIAL_RESIDENTS = 40;

static constexpr double CENTRAL_LOCATION_RENT_MULTIPLIER = 2.5;
static constexpr double PERIPHERAL_LOCATION_RENT_MULTIPLIER = 0.8;
static constexpr double MODERN_BUILDING_RENT = 1000.00;
static constexpr double PANEL_BLOCK_BUILDING_RENT = 500.00;
static constexpr double DORMITORY_BUILDING_RENT = 40.00;
static constexpr double FOOD_EXPENSES = 50;

static constexpr int MINER_MAX_SALARY = 3000;
static constexpr int MINER_MIN_SALARY = 1000;
static constexpr int PROGRAMMER_MAX_SALARY = 5000;
static constexpr int PROGRAMMER_MIN_SALARY = 2000;
static constexpr int TEACHER_MAX_SALARY = 1300;
static constexpr int TEACHER_MIN_SALARY = 1200;
static constexpr int UNEMPLOYED_SALARY = 0;

static constexpr int RESIDENT_MIN_INFO = 20;
static constexpr int RESIDENT_MAX_INFO = 100;

static constexpr int ADD_RESIDENT_ARGUMENTS = 7;
static constexpr int REMOVE_RESIDENT_ARGUMENTS = 3;

static constexpr int STEP_ARGUMENTS = 0;
static constexpr int STEPS_ARGUMENTS = 1;

static constexpr int BUILDING_INFO_ARGUMENTS = 2;

static constexpr int RESIDENT_INFO_ARGUMENTS = 3;

static constexpr int INFO_ARGUMENTS = 0;

static constexpr int SAVE_ARGUMENTS = 1;

static constexpr int LOAD_ARGUMENTS = 1;


static constexpr int GENERATE_CITY_ARGUMENTS = 2;

static constexpr int BUILDING_TYPES = 3;
}

#endif /* Constants_hpp */

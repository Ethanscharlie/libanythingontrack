#pragma once

#include <stddef.h>
#include <stdint.h>
#include <time.h>

typedef enum { AOT_PERIOD_DAILY, AOT_PERIOD_WEEKLY, AOT_PERIOD_MONTHLY, AOT_PERIOD_YEARLY } AOT_Period;

typedef struct AOT_Tracker AOT_Tracker;

////////////////////////////////////////////////////////////////////////////////////////////////
// AOT  ////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
void AOT_Init();

////////////////////////////////////////////////////////////////////////////////////////////////
// TRACKER /////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
AOT_Tracker* AOT_CreateTracker(char* name, float value, AOT_Period period, uint16_t periodCount);

/**
 *
 */
AOT_Tracker* AOT_CreateTrackerFromFile(char* filepath);

/**
 *
 */
void AOT_DestroyTracker(AOT_Tracker* tracker);

/**
 *
 */
float AOT_GetTrackerBalance(AOT_Tracker* tracker);

/**
 *
 */
char* AOT_GetTrackerName(AOT_Tracker* tracker);

/**
 *
 */
float AOT_GetTrackerValue(AOT_Tracker* tracker);

/**
 *
 */
AOT_Period AOT_GetTrackerPeriod(AOT_Tracker* tracker);

/**
 *
 */
uint16_t AOT_GetTrackerPeriodCount(AOT_Tracker* tracker);

/**
 *
 */
int AOT_GetTrackerDay(AOT_Tracker* tracker);

/**
 *
 */
int AOT_GetTrackerMonth(AOT_Tracker* tracker);

/**
 *
 */
int AOT_GetTrackerYear(AOT_Tracker* tracker);

/**
 *
 */
void AOT_SetTrackerName(AOT_Tracker* tracker, char* name);

/**
 *
 */
void AOT_SetTrackerValue(AOT_Tracker* tracker, float value);

/**
 *
 */
void AOT_SetTrackerPeriod(AOT_Tracker* tracker, AOT_Period period);

/**
 *
 */
void AOT_SetTrackerPeriodCount(AOT_Tracker* tracker, uint16_t periodCount);

/**
 *
 */
void AOT_SetTrackerDay(AOT_Tracker* tracker, int day);

/**
 *
 */
void AOT_SetTrackerMonth(AOT_Tracker* tracker, int month);

/**
 *
 */
void AOT_SetTrackerYear(AOT_Tracker* tracker, int year);

////////////////////////////////////////////////////////////////////////////////////////////////
// RECORDS /////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

/**
 *
 */
void AOT_TrackerAddRecord(AOT_Tracker* tracker, char* note, float value);

/**
 *
 */
size_t AOT_GetTrackerRecordCount(AOT_Tracker* tracker);

/**
 *
 */
void AOT_TrackerRemoveRecordAtIndex(AOT_Tracker* tracker, size_t index);

/**
 *
 */
char* AOT_GetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index);

/**
 *
 */
float AOT_GetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index);

/**
 *
 */
uint8_t AOT_GetTrackerRecordDayAtIndex(AOT_Tracker* tracker, size_t index);

/**
 *
 */
uint8_t AOT_GetTrackerRecordMonthAtIndex(AOT_Tracker* tracker, size_t index);

/**
 *
 */
uint16_t AOT_GetTrackerRecordYearAtIndex(AOT_Tracker* tracker, size_t index);

/**
 *
 */
void AOT_SetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index, char* note);

/**
 *
 */
void AOT_SetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index, float value);

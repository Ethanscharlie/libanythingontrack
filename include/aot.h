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
 * Initializes the library.
 *
 * This function must be called before creating any trackers with AOT_CreateTracker.
 */
void AOT_Init();

////////////////////////////////////////////////////////////////////////////////////////////////
// TRACKER /////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Creates an instance of the Tracker object.
 *
 * Used to create a new tracker, for loading a tracker from a file check out AOT_CreateTrackerFromFile.
 * Tracker must be destroyed with AOT_DestroyTracker.
 *
 * @param name The title given to the tracker.
 * @param value Number to be added to total multiplied by the periods that have passed.
 * @param period The block a time in between each total increase.
 * @param periodCount Multiplier for the period. Ex: 2 weeks.
 * @return A Tracker Object, must be destroyed with AOT_DestroyTracker.
 */
AOT_Tracker* AOT_CreateTracker(char* name, float value, AOT_Period period, uint16_t periodCount);

/**
 * Creates an instance of the Tracker object based off of a file.
 *
 * Tracker must be destroyed with AOT_DestroyTracker.
 *
 * @param filepath The path where the file is located.
 * @return A Tracker Object, must be destroyed with AOT_DestroyTracker.
 */
AOT_Tracker* AOT_CreateTrackerFromFile(char* filepath);

/**
 * Destroys a Tracker object created with AOT_CreateTracker or AOT_CreateTrackerFromFile.
 *
 * Must be called on any Tracker object when ready.
 *
 * @param tracker A Tracker object.
 */
void AOT_DestroyTracker(AOT_Tracker* tracker);

/**
 * Gets the current balance remaining in the tracker.
 *
 * The balance will be calculated by the tracker value multiplied by the number of periods passed subtracked by the
 * total value of all the records.
 *
 * @param tracker A Tracker object.
 */
float AOT_GetTrackerBalance(AOT_Tracker* tracker);

char* AOT_GetTrackerName(AOT_Tracker* tracker);
float AOT_GetTrackerValue(AOT_Tracker* tracker);
AOT_Period AOT_GetTrackerPeriod(AOT_Tracker* tracker);
uint16_t AOT_GetTrackerPeriodCount(AOT_Tracker* tracker);
int AOT_GetTrackerDay(AOT_Tracker* tracker);
int AOT_GetTrackerMonth(AOT_Tracker* tracker);
int AOT_GetTrackerYear(AOT_Tracker* tracker);

void AOT_SetTrackerName(AOT_Tracker* tracker, char* name);
void AOT_SetTrackerValue(AOT_Tracker* tracker, float value);
void AOT_SetTrackerPeriod(AOT_Tracker* tracker, AOT_Period period);
void AOT_SetTrackerPeriodCount(AOT_Tracker* tracker, uint16_t periodCount);
void AOT_SetTrackerDay(AOT_Tracker* tracker, int day);
void AOT_SetTrackerMonth(AOT_Tracker* tracker, int month);
void AOT_SetTrackerYear(AOT_Tracker* tracker, int year);

////////////////////////////////////////////////////////////////////////////////////////////////
// RECORDS /////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Adds a record to the tracker.
 *
 * The record will be saved in the tracker and will be used to determine the balance of the tracker.
 *
 * @param tracker A Tracker object.
 * @param note A note attached the record.
 * @param value The value of the record.
 */
void AOT_TrackerAddRecord(AOT_Tracker* tracker, char* note, float value);

size_t AOT_GetTrackerRecordCount(AOT_Tracker* tracker);
void AOT_TrackerRemoveRecordAtIndex(AOT_Tracker* tracker, size_t index);
char* AOT_GetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index);
float AOT_GetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index);
uint8_t AOT_GetTrackerRecordDayAtIndex(AOT_Tracker* tracker, size_t index);
uint8_t AOT_GetTrackerRecordMonthAtIndex(AOT_Tracker* tracker, size_t index);
uint16_t AOT_GetTrackerRecordYearAtIndex(AOT_Tracker* tracker, size_t index);

void AOT_SetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index, char* note);
void AOT_SetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index, float value);

#include "aot.h"

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

typedef struct tm Datetime;

typedef struct {
  char* note;
  Datetime date;
  float value;
} AOT_Record;

struct AOT_Tracker {
  uint32_t id;
  char* name;
  AOT_Period period;
  uint16_t periodCount;
  Datetime date;
  AOT_Record* records;
  size_t numberOfRecords;
};

static Datetime currentDate() {
  time_t t = time(NULL);
  return *localtime(&t);
}

void AOT_Init() { srand(time(NULL)); }

AOT_Tracker* AOT_CreateTracker(char* name, AOT_Period period, uint16_t periodCount) {
  AOT_Tracker* tracker = malloc(sizeof(AOT_Tracker));

  tracker->id = 0;
  tracker->name = name;
  tracker->period = period;
  tracker->periodCount = periodCount;
  tracker->date = currentDate();

  tracker->records = (AOT_Record*)malloc(sizeof(AOT_Record) * 0);
  tracker->numberOfRecords = 0;

  return tracker;
}

AOT_Tracker* AOT_CreateTrackerFromFile(char* filepath) {
  // TODO
}

void AOT_DestroyTracker(AOT_Tracker* tracker) { free(tracker); }

float AOT_GetTrackerBalance(AOT_Tracker* tracker) {
  // TODO
}

char* AOT_GetTrackerName(AOT_Tracker* tracker) { return tracker->name; }

AOT_Period AOT_GetTrackerPeriod(AOT_Tracker* tracker) { return tracker->period; }

uint16_t AOT_GetTrackerPeriodCount(AOT_Tracker* tracker) { return tracker->periodCount; }

void AOT_SetTrackerName(AOT_Tracker* tracker, char* name) { tracker->name = name; }

void AOT_SetTrackerPeriod(AOT_Tracker* tracker, AOT_Period period) { tracker->period = period; }

void AOT_SetTrackerPeriodCount(AOT_Tracker* tracker, uint16_t periodCount) { tracker->periodCount = periodCount; }

void AOT_TrackerAddRecord(AOT_Tracker* tracker, char* note, float value) {
  tracker->numberOfRecords++;
  tracker->records = realloc(tracker->records, tracker->numberOfRecords * sizeof(AOT_Record));

  AOT_Record record = {note, currentDate(), value};
  tracker->records[tracker->numberOfRecords - 1] = record;
}

size_t AOT_GetTrackerRecordCount(AOT_Tracker* tracker) { return tracker->numberOfRecords; }

void AOT_TrackerRemoveRecordAtIndex(AOT_Tracker* tracker, size_t index) {
  // TODO
}

char* AOT_GetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index) { return tracker->records[index].note; }

float AOT_GetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index) { return tracker->records[index].value; }

uint8_t AOT_GetTrackerRecordDayAtIndex(AOT_Tracker* tracker, size_t index) {
  return tracker->records[index].date.tm_mday;
}

uint8_t AOT_GetTrackerRecordMonthAtIndex(AOT_Tracker* tracker, size_t index) {
  return tracker->records[index].date.tm_mon + 1;
}

uint16_t AOT_GetTrackerRecordYearAtIndex(AOT_Tracker* tracker, size_t index) {
  return tracker->records[index].date.tm_year + 1900;
}

void AOT_SetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index, char* note) {
  tracker->records[index].note = note;
}

void AOT_SetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index, float value) {
  tracker->records[index].value = value;
}

#include "aot.h"

#include <stdint.h>

struct AOT_Tracker {
  uint32_t id;
  char* name;
  AOT_Period period;
  uint16_t periodCount;
};

AOT_Tracker* AOT_CreateTracker(char* name, AOT_Period period, uint16_t periodCount) {}

AOT_Tracker* AOT_CreateTrackerFromFile(char* filepath) {}

AOT_Tracker* AOT_DestroyTracker(AOT_Tracker* tracker) {}

float AOT_GetTrackerBalance(AOT_Tracker* tracker) {}

char* AOT_GetTrackerName(AOT_Tracker* tracker) { return tracker->name; }

AOT_Period AOT_GetTrackerPeriod(AOT_Tracker* tracker) { return tracker->period; }

uint16_t AOT_GetTrackerPeriodCount(AOT_Tracker* tracker) { return tracker->periodCount; }

void AOT_SetTrackerName(AOT_Tracker* tracker, char* name) { tracker->name = name; }

void AOT_SetTrackerPeriod(AOT_Tracker* tracker, AOT_Period period) { tracker->period = period; }

void AOT_SetTrackerPeriodCount(AOT_Tracker* tracker, uint16_t periodCount) { tracker->periodCount = periodCount; }

void AOT_TrackerAddRecord(AOT_Tracker* tracker, char* name, float value) {}

size_t AOT_GetTrackerRecordCount(AOT_Tracker* tracker) {}

void AOT_TrackerRemoveRecordAtIndex(AOT_Tracker* tracker, size_t index) {}

char* AOT_GetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index) {}

float AOT_GetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index) {}

Datetime AOT_GetTrackerRecordDateAtIndex(AOT_Tracker* tracker, size_t index) {}

void AOT_SetTrackerRecordNoteAtIndex(AOT_Tracker* tracker, size_t index, char* note) {}

void AOT_SetTrackerRecordValueAtIndex(AOT_Tracker* tracker, size_t index, float value) {}

void AOT_SetTrackerRecordDateAtIndex(AOT_Tracker* tracker, size_t index, Datetime date) {}

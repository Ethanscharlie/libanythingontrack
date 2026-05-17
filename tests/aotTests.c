#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aot.h"

static void clearLog() {
  FILE* fp;
  char* filename = "log.txt";

  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return;
  }

  fprintf(fp, "");
  fclose(fp);
}

void writeToLog(const char* format, ...) {
  FILE* fp;
  char* filename = "log.txt";

  fp = fopen(filename, "a");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return;
  }

  va_list args;
  va_start(args, format);
  vfprintf(fp, format, args);
  va_end(args);

  fputc('\n', fp);
  fclose(fp);
}

int main(int argc, char* argv[]) {
  AOT_Init();

  char* testName = argv[1];
  writeToLog("\n --- %s --- ", testName);

  if (strcmp(testName, "ClearTestLog") == 0) {
    clearLog();
    return EXIT_SUCCESS;
  }

  else if (strcmp(testName, "CurrentDate") == 0) {
    AOT_Tracker* tracker = AOT_CreateTracker("ONE", AOT_PERIOD_MONTHLY, 1);
    AOT_TrackerAddRecord(tracker, "", 0.0F);

    int d = AOT_GetTrackerRecordDayAtIndex(tracker, 0);
    int m = AOT_GetTrackerRecordMonthAtIndex(tracker, 0);
    int y = AOT_GetTrackerRecordYearAtIndex(tracker, 0);

    AOT_DestroyTracker(tracker);

    writeToLog("%d/%d/%d", d, m, y);
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}

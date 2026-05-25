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

static int periodTypeTests(char* testName, AOT_Period period) {
  if (strcmp(testName, "BalanceNoRecords") == 0) {
    const float v = 100.0F;

    AOT_Tracker* tracker = AOT_CreateTracker("ONE", v, period, 1);
    float balance = AOT_GetTrackerBalance(tracker);
    AOT_DestroyTracker(tracker);

    writeToLog("Balance: %.2f, should be %2f", balance, v);
    if (balance == v) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }

  else if (strcmp(testName, "BalanceOneRecord") == 0) {
    const float v = 200.0F;
    const float x = 50.0F;

    AOT_Tracker* tracker = AOT_CreateTracker("ONE", v, period, 1);
    AOT_TrackerAddRecord(tracker, "note", x);
    float balance = AOT_GetTrackerBalance(tracker);
    AOT_DestroyTracker(tracker);

    writeToLog("Balance: %.2f, should be %2f", balance, v - x);
    if (balance == v - x) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }

  else if (strcmp(testName, "BalanceMultipleRecords") == 0) {
    const float v = 400.0F;
    const float x = 50.0F;
    const float y = 80.0F;

    AOT_Tracker* tracker = AOT_CreateTracker("ONE", v, period, 1);
    AOT_TrackerAddRecord(tracker, "note", x);
    AOT_TrackerAddRecord(tracker, "note2", y);
    float balance = AOT_GetTrackerBalance(tracker);
    AOT_DestroyTracker(tracker);

    writeToLog("Balance: %.2f, should be %2f", balance, v - x - y);
    if (balance == v - x - y) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }

  else if (strcmp(testName, "BalanceNegitiveRecord") == 0) {
    const float v = -1000.0F;
    const float x = -1.0F;

    AOT_Tracker* tracker = AOT_CreateTracker("ONE", v, period, 1);
    AOT_TrackerAddRecord(tracker, "note", x);
    float balance = AOT_GetTrackerBalance(tracker);
    AOT_DestroyTracker(tracker);

    writeToLog("Balance: %.2f, should be %2f", balance, v - x);
    if (balance == v - x) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }

  return EXIT_FAILURE;
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
    AOT_Tracker* tracker = AOT_CreateTracker("ONE", 100.0F, AOT_PERIOD_MONTHLY, 1);
    AOT_TrackerAddRecord(tracker, "", 0.0F);

    int d = AOT_GetTrackerRecordDayAtIndex(tracker, 0);
    int m = AOT_GetTrackerRecordMonthAtIndex(tracker, 0);
    int y = AOT_GetTrackerRecordYearAtIndex(tracker, 0);

    AOT_DestroyTracker(tracker);

    writeToLog("%d/%d/%d", d, m, y);
    return EXIT_SUCCESS;
  }

  else if (strcmp(testName, "CanAddRecord") == 0) {
    AOT_Tracker* tracker = AOT_CreateTracker("ONE", 100.0F, AOT_PERIOD_MONTHLY, 1);
    AOT_TrackerAddRecord(tracker, "", 0.0F);
    size_t count = AOT_GetTrackerRecordCount(tracker);
    AOT_DestroyTracker(tracker);

    if (count == 1) {
      return EXIT_SUCCESS;
    } else {
      return EXIT_FAILURE;
    }
  }

  else if (strcmp(testName, "period") == 0) {
    char* periodName = argv[3];
    AOT_Period period;
    if (strcmp(periodName, "daily") == 0) {
      period = AOT_PERIOD_DAILY;
    } else if (strcmp(periodName, "weekly") == 0) {
      period = AOT_PERIOD_WEEKLY;
    } else if (strcmp(periodName, "monthly") == 0) {
      period = AOT_PERIOD_MONTHLY;
    } else if (strcmp(periodName, "yearly") == 0) {
      period = AOT_PERIOD_YEARLY;
    }

    return periodTypeTests(argv[2], period);
  }

  return EXIT_FAILURE;
}

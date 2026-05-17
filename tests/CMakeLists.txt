add_executable(aot_tests aotTests.c)
target_link_libraries(aot_tests PRIVATE anythingontrack)

add_test(NAME ClearTestLog COMMAND aot_tests ClearTestLog)
add_test(NAME CurrentDate COMMAND aot_tests CurrentDate)
add_test(NAME CanAddRecord COMMAND aot_tests CanAddRecord)

add_test(NAME DailyBalanceNoRecords COMMAND aot_tests period BalanceNoRecords daily)
add_test(NAME DailyBalanceOneRecord COMMAND aot_tests period BalanceOneRecord daily)
add_test(NAME DailyBalanceMultipleRecords COMMAND aot_tests period BalanceMultipleRecords daily)
add_test(NAME DailyBalanceNegitiveRecord COMMAND aot_tests period BalanceNegitiveRecord daily)

add_test(NAME WeeklyBalanceNoRecords COMMAND aot_tests period BalanceNoRecords weekly)
add_test(NAME WeeklyBalanceOneRecord COMMAND aot_tests period BalanceOneRecord weekly)
add_test(NAME WeeklyBalanceMultipleRecords COMMAND aot_tests period BalanceMultipleRecords weekly)
add_test(NAME WeeklyBalanceNegitiveRecord COMMAND aot_tests period BalanceNegitiveRecord weekly)

add_test(NAME MonthlyBalanceNoRecords COMMAND aot_tests period BalanceNoRecords monthly)
add_test(NAME MonthlyBalanceOneRecord COMMAND aot_tests period BalanceOneRecord monthly)
add_test(NAME MonthlyBalanceMultipleRecords COMMAND aot_tests period BalanceMultipleRecords monthly)
add_test(NAME MonthlyBalanceNegitiveRecord COMMAND aot_tests period BalanceNegitiveRecord monthly)

add_test(NAME YearlyBalanceNoRecords COMMAND aot_tests period BalanceNoRecords yearly)
add_test(NAME YearlyBalanceOneRecord COMMAND aot_tests period BalanceOneRecord yearly)
add_test(NAME YearlyBalanceMultipleRecords COMMAND aot_tests period BalanceMultipleRecords yearly)
add_test(NAME YearlyBalanceNegitiveRecord COMMAND aot_tests period BalanceNegitiveRecord yearly)

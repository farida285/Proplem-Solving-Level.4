# Problem Solving — Level 4 🗓️
### Dr. Mohamed Abu Hudhud's C++ Roadmap

> **Topic:** Date & Time Manipulation in C++  
> **Problems:** 65 exercises across 33 files  
> **Core Data Structure:** `stDate` struct `{ unsigned short year, month, day }`

---

## 📋 Table of Contents

| # | File | Topic |
|---|------|-------|
| 01 | `#01ReadNumberPrintTheTextOfNumber.cpp` | Number to English text (recursive) |
| 02–03 | `#02LeadYear.cpp` / `#03LeadYearInOneCode.cpp` | Leap year check (2 approaches) |
| 04 | `#04NumberofDays-Hours-Minutes-SecondsInaYear.cpp` | Days/Hours/Minutes/Seconds in a year |
| 05–06 | `#05&06NumberofDays-Hours-Minutes-SecondsInaMonth.cpp` | Days/Hours/Minutes/Seconds in a month |
| 07 | `#07DayName.cpp` | Day name from date (Tomohiko Sakamoto algorithm) |
| 08 | `#08MonthCelender.cpp` | Month calendar printer |
| 09 | `#09YearCelender.cpp` | Full year calendar printer |
| 10 | `#10TotalDaysFromTheBeginningOfYear.cpp` | Day order in year |
| 11 | `#11DateFromDayOrderInaYear.cpp` | Day order ↔ date conversion (round-trip) |
| 12 | `#12AddDaysToDate.cpp` | Add N days to a date (2 algorithms) |
| 13 | `#13CheckifDate1isLessThanDate2.cpp` | Date comparison: is Date1 < Date2? (3 approaches) |
| 14 | `#14CheckIfDate1EqualDate2.cpp` | Date equality check (2 approaches) |
| 15 | `#15IsLastDayIsLastMonth.cpp` | Check if last day in month / last month in year |
| 16 | `#16IncreaseDateByOneDay.cpp` | Increment date by 1 day |
| 17 | `#17DiffInDays.cpp` | Date difference in days (2 algorithms) |
| 18 | `#18YourAgeInDays.cpp` | Age calculator in days using system date |
| 19 | `#19DiffInDaysV2.cpp` | Date difference with negative support (swap dates) |
| 20–32 | `#20to32IncreaseDateProblems.cpp` | 13 increase-date functions |
| 33–46 | `#33to46DecreaseDateProblems.cpp` | 13 decrease-date functions |
| 47–53 | `#47to53MoreDateProblem.cpp` | Week/business day utilities |
| 54 | `#54CalcVactionDays.cpp` | Vacation days calculator (weekends excluded) |
| 55 | `#55CalcReturnDayFromVaction.cpp` | Return date from vacation |
| 56 | `#56IsDate1AfterDate2.cpp` | Is Date1 after Date2? |
| 57 | `#57CompareDateFunction.cpp` | 3-way date comparison (-1 / 0 / 1) |
| 58 | `#58CheckPeriodOverlap.cpp` | Do two date periods overlap? |
| 59 | `#59PeriodLength.cpp` | Period length in days |
| 60 | `#60DayWithinPeriodOrNot.cpp` | Is a date within a period? |
| 61 | `#61CountOverlapDays.cpp` | Count overlapping days between two periods (2 algorithms) |
| 62 | `#62ValidateDate.cpp` | Date validation |
| 63–64 | `#63&64.cpp` | String ↔ stDate conversion |
| 65 | `#65.cpp` | Date formatter with custom format strings |

---

## 🧱 Core Building Blocks

These helper functions appear and build on each other throughout all files:

```cpp
struct stDate { unsigned short year, month, day; };

bool IsLeapYear(unsigned short year);
unsigned short NumberOfDaysInMonth(unsigned short year, unsigned short month);
unsigned short NumberOfDaysFromTheBeginningOfYear(unsigned short year, unsigned short month, unsigned short day);
stDate TakeOrderDayInYearAndconvertToDate(unsigned short year, unsigned short dateOrderInYear);
stDate IncreaseDateByOneDay(stDate date);
stDate DecreaseDateByOneDay(stDate date);
bool CheckDate1LessThanDate2(stDate date1, stDate date2);
bool CheckDate1EqualThanDate2(stDate date1, stDate date2);
bool CheckDate1AfterDate2(stDate date1, stDate date2);
```

---

## 📂 Detailed File Descriptions

### `#01` — Number to English Text
Converts any positive integer up to the trillions into its English text representation using recursion.  
Example: `1234` → `"One Thousand Two Hundreds Thirty Four"`

---

### `#02` & `#03` — Leap Year
Two versions of the same logic:
- `#02`: uses `if/else` chain
- `#03`: condenses to a single `return` expression

```cpp
// Rule: divisible by 400 → leap | divisible by 100 → not leap | divisible by 4 → leap
bool IsLeapYear(unsigned short year) {
    return (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0));
}
```

---

### `#04` — Time Units in a Year
Calculates days (365/366), hours (×24), minutes (×60), and seconds (×60) for a given year, accounting for leap years.

---

### `#05–06` — Time Units in a Month
Same as `#04` but at the month level. Uses `NumberOfDaysInMonth` which handles February with leap year detection.

---

### `#07` — Day Name
Uses the **Tomohiko Sakamoto algorithm** to calculate the day of the week (0=Sunday … 6=Saturday) for any date.

```cpp
unsigned short d = (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
```

---

### `#08` — Month Calendar
Prints a formatted calendar for a given month. Uses `DayOrder` to find which column the 1st day falls in, then fills remaining days row by row with `setw` formatting.

---

### `#09` — Year Calendar
Calls `PrintMonthCelender` in a loop for all 12 months to print a full year calendar.

---

### `#10` — Days From Start of Year
Sums all days in months before the given month, then adds the day number.

---

### `#11` — Round-Trip: Day Order ↔ Date
`NumberOfDaysFromTheBeginningOfYear` converts a date to its ordinal (e.g., Feb 1 = day 32).  
`TakeOrderDayInYearAndconvertToDate` reverses it back to a date by subtracting month lengths iteratively.

---

### `#12` — Add Days to Date
Two algorithms implemented and compared:
- **`AddDaysToDate`**: year-by-year approach — faster for huge numbers
- **`AddDaysToDate2`**: month-by-month traversal — cleaner for medium ranges

---

### `#13` — Is Date1 < Date2?
Three implementations showing different styles:
1. Chained ternary operator
2. Year-first comparison then day-order comparison
3. Sequential `if` statements (clearest and recommended)

---

### `#14` — Date Equality
Two implementations:
1. Direct `&&` comparison of all three fields
2. Nested ternary (functionally identical, less readable)

---

### `#15` — Last Day / Last Month
```cpp
bool IsLastDayInmonth(year, month, day)  → day == NumberOfDaysInMonth(year, month)
bool IsLastMonthInYear(month)            → month == 12
```

---

### `#16` — Increase Date by One Day
Handles three cases: normal day increment, end-of-month rollover, and end-of-year rollover.

---

### `#17` — Difference in Days
Two algorithms:
- **`GetDifferenceInDays1`**: fast — jumps year by year, then calculates remaining days using ordinals
- **`GetDifferenceInDays2`**: slow but simple — calls `IncreaseDateByOneDay` in a loop

Both support an `includeEndDay` flag.

---

### `#18` — Age in Days
Uses `<ctime>` to get today's system date, then calls `GetDifferenceInDays1` between the birth date and today.

---

### `#19` — Difference in Days V2 (with negative support)
Extends `#17` to handle Date1 > Date2: swaps the dates internally and returns a negative result.

---

### `#20–32` — Increase Date Functions (13 functions)

| Function | Description |
|----------|-------------|
| `IncreaseDateByOneDay` | +1 day |
| `IncreaseDateByXDaysForSmallNumbers` | loop-based, good for small N |
| `IncreaseDateByXDaysForMediumNumbers` | month-by-month, medium N |
| `IncreaseDateByXDaysFasterForHugeNumbers` | year-by-year, huge N |
| `IncreaseDateByOneWeek` | +7 days |
| `IncreaseDateByXWeeks` | +7×N days |
| `IncreaseDateByOneMonth` | +1 month (with leap day fix) |
| `IncreaseDateByXMonths` | +N months |
| `IncreaseDateByOneYear` | +1 year |
| `IncreaseDateByXYears` | +N years (preserves Feb 29 when possible) |
| `IncreaseDateByXYearsFaster` | direct `year += N` |
| `IncreaseDateByOneDecade` | +10 years |
| `IncreaseDateByXDecades` / `Faster` | +10×N years |
| `IncreaseDateByOneCentury` | +100 years |
| `IncreaseDateByOneMillennium` | +1000 years |

**Key helper:** `FixLeapDayIfNeededInYearsFunctions` — if Feb 29 doesn't exist in the target year, rolls back to Feb 28.

---

### `#33–46` — Decrease Date Functions (13 functions)
Mirror of `#20–32` in the subtraction direction. Uses:
- `IsFirstDayInmonth` / `IsFirstMonthInYear`
- `DecreaseDateByXDaysForMediumNumbers`: walks backward month by month
- `DecreaseDateByXDaysFasterForHugeNumbers`: year-by-year subtraction using day ordinals

---

### `#47–53` — Week & Business Day Utilities
Uses an `enum enDays { Sunday=0, ..., Saturday=6 }`.

| Function | Description |
|----------|-------------|
| `IsEndOfWeek` | day == Saturday |
| `IsWeekEndDay` | day == Friday or Saturday |
| `IsBusinessDay` | not a weekend day |
| `DaysUntilEndOftheWeek` | `6 - DayOrder(date)` |
| `DaysUntilEndOftheMonth` | `daysInMonth - day` |
| `DaysUntilEndOftheYear` | `(365/366) - dayOrdinal` |

Runs on the system date via `GetSystemDate()`.

---

### `#54` — Actual Vacation Days
Iterates from start to end date, counting only business days (Mon–Thu). Weekends (Fri/Sat) are excluded.

---

### `#55` — Vacation Return Date
Given a start date and number of vacation days (business days only), advances the date counting only business days until the vacation quota is used up.

---

### `#56` — Is Date1 After Date2?
```cpp
bool CheckDate1AfterDate2(date1, date2) {
    return !CheckDate1EqualThanDate2(date1, date2) && !CheckDate1LessThanDate2(date1, date2);
}
```

---

### `#57` — 3-Way Date Compare
Uses `enum enCompareResult { Before=-1, Equal=0, After=1 }` for a clean comparison interface.

---

### `#58` — Period Overlap Check
Uses a `stPeriod { stDate startDate, endDate }` struct.  
Two periods overlap if neither ends before the other starts:
```cpp
!(period1.endDate < period2.startDate) && !(period1.startDate > period2.endDate)
```

---

### `#59` — Period Length
Wraps `GetDifferenceInDays` for a period, with optional `includeEndDay` flag.

---

### `#60` — Date Within Period?
```cpp
bool CheckDateWithinPeriod(period, date) {
    return date >= period.startDate && date <= period.endDate;
}
```

---

### `#61` — Count Overlapping Days (2 algorithms)
- **`NumberOfOverlapDays`** (O(n)): advances `period1.startDate` to the later start, then iterates day by day counting days that fall within both periods.  
- **`NumberOfOverlapDaysV2`** (O(1)): calculates overlap directly:
  - `startOverlap = max(period1.start, period2.start)`
  - `endOverlap   = min(period1.end,   period2.end)`
  - returns `GetDifferenceInDays(startOverlap, endOverlap, true)`

---

### `#62` — Date Validation
Validates that month is 1–12 and day is within the valid range for that month (accounting for leap years in February).

---

### `#63–64` — String ↔ Date Conversion
- `ReadStringDate()`: reads and validates a string in `dd/mm/yyyy` format
- `ConvertStringDateToStDate()`: splits on `/`, converts parts to `unsigned short`
- `DateToString()`: rebuilds `"dd/mm/yyyy"` string from struct fields

---

### `#65` — Date Formatter
`FormatDate(date, formatString, separator)` supports arbitrary format strings:

```cpp
FormatDate(date, "dd/mm/yyyy")               // 22/4/2026
FormatDate(date, "yyyy/dd/mm")               // 2026/22/4
FormatDate(date, "mm-dd-yyyy", '-')          // 4-22-2026
FormatDate(date, "Day:dd, Month:mm, Year:yyyy", ':', ",")  // Day:22, Month:4, Year:2026
```

Uses `ReplaceWordInString` with whole-word boundary checking to avoid replacing `"mm"` inside `"mmm"`.

---

## 🔑 Key Concepts Practiced

- Recursive functions (number-to-text)
- Structs (`stDate`, `stPeriod`)
- Enums (`enDays`, `enCompareResult`)
- Algorithm efficiency comparison (O(1) vs O(n))
- Input validation with `do-while` loops
- `<ctime>` for system date
- String parsing and formatting
- Leap year edge cases (especially Feb 29)
- Function overloading and default parameters

---

## 🛠️ How to Compile & Run

```bash
g++ -std=c++17 "#01ReadNumberPrintTheTextOfNumber.cpp" -o problem01
./problem01
```

Or open any `.cpp` file directly in your IDE (Visual Studio, CLion, VS Code) and run.

---

## 🔗 GitHub

All projects from this roadmap are available at: [github.com/farida285](https://github.com/farida285)

//  https://stackoverflow.com/questions/11714325/how-to-get-enum-item-name-from-its-value

#include <Streaming.h>

class CTest
{
public:
  #define WEEK_DAYS \
  X(MON, "Monday", true) \
  X(TUE, "Tuesday", true) \
  X(WED, "Wednesday", true) \
  X(THU, "Thursday", true) \
  X(FRI, "Friday", true) \
  X(SAT, "Saturday", false) \
  X(SUN, "Sunday", false)

  #define X(day, name, workday) day,
  enum class WeekDay : size_t
  {
      WEEK_DAYS
  };
  #undef X

  #define X(day, name, workday) name,
  constexpr static char const *weekday_name[]
  {
      WEEK_DAYS
  };
  #undef X

  #define X(day, name, workday) workday,
  constexpr static bool weekday_workday[]
  {
      WEEK_DAYS
  };
  #undef X

};

void setup()
{
  Serial.begin (9600);

  Serial << "Enum value: " << (int)CTest::WeekDay::THU << endl;
  Serial << "Name string: " << CTest::weekday_name[(int)CTest::WeekDay::THU] << endl;
  Serial << "Work day: " << CTest::weekday_workday[(int)CTest::WeekDay::THU] << endl;

  CTest::WeekDay wd = CTest::WeekDay::SUN;
  Serial << "Enum value: " << (int)wd << endl;
  Serial << "Name string: " << CTest::weekday_name[(int)wd] << endl;
  Serial << "Work day: " << CTest::weekday_workday[(int)wd] << endl;
}

void loop() {
  // put your main code here, to run repeatedly:

}

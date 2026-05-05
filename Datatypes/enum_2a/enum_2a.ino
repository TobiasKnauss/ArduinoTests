//  https://stackoverflow.com/questions/11714325/how-to-get-enum-item-name-from-its-value

#include <Streaming.h>

#define WEEK_DAYS \
X(MON, "Monday", true) \
X(TUE, "Tuesday", true) \
X(WED, "Wednesday", true) \
X(THU, "Thursday", true) \
X(FRI, "Friday", true) \
X(SAT, "Saturday", false) \
X(SUN, "Sunday", false)

#define X(day, name, workday) day,
enum WeekDay : size_t
{
    WEEK_DAYS
};
#undef X

#define X(day, name, workday) name,
char const *weekday_name[]
{
    WEEK_DAYS
};
#undef X

#define X(day, name, workday) workday,
bool weekday_workday[]
{
    WEEK_DAYS
};
#undef X


void setup()
{
  Serial.begin (9600);

  Serial << "Enum value: " << WeekDay::THU << endl;
  Serial << "Name string: " << weekday_name[WeekDay::THU] << endl;
  Serial << "Work day: " << weekday_workday[WeekDay::THU] << endl;

  WeekDay wd = SUN;
  Serial << "Enum value: " << wd << endl;
  Serial << "Name string: " << weekday_name[wd] << endl;
  Serial << "Work day: " << weekday_workday[wd] << endl;
}

void loop() {
  // put your main code here, to run repeatedly:

}

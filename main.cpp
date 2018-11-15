#include "Calendar.h"

int main()
{
    StudyTask s1("English","Grammar booster page 3,4,5","Studying","Grammar",12,34,18,42);
    BusinessTask b1("Sofia","Joy Station","Concert","Kiss",12,34,18,42);
    b1.setPeople("Stanislav","Zhechev");
    b1.setPeople("Jon","Snow");
    RelaxTask r1("Cycling","Sofia","Relaxing","Got new bike ^.^ !!!",12,32,16,23);
    RelaxTask r2("Cycling","Sliven","Relax","Hyped",12,32,16,23);
    //r1.checkWeater();
    Calendar c1;
    c1.addBusinessTaskToDate(2,3,b1);
    c1.addRelaxTaskToDate(3,3,r1);
    c1.addStudyTaskToDate(4,3,s1);
    c1.addRelaxTaskToDate(2,3,r2);
    c1.checkTasks(2,3);
    c1.checkTasks(3,3);
    c1.checkTasks(4,3);
    c1.checkTasks(5,3);
    return 0;
}

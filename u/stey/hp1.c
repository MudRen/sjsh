// hp cmds (Mon  09-04-95)
#include <ansi.h>

inherit F_CLEAN_UP;


string status_color(int current, int max);

int main(object me, string arg)
{
        object ob;
        mapping my;
        int  year, day, hour,anger,x,i;
        string sp_skill;

        seteuid(getuid(me));

        if(!arg)

                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();
     printf(HIC" ��Ѫ�� %s%4d/ %4d %s(%3d%%)" HIC "    ������ %s%4d / %4d (+%d)\n" NOR,
                status_color(my["kee"], my["eff_kee"]), my["kee"],      my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
                my["force_factor"] );
    printf(HIY" ���� %s%4d/ %4d %s(%3d%%)" HIY "    ������ %s%4d / %4d (+%d)\n" NOR,
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]),     my["mana"], my["max_mana"],
                my["mana_factor"] );
    printf(HIG" ʳ� %s%4d/ %4d       " HIM "    �ҳϣ� %s%d\n" NOR,
             status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),
        HIY,                                         
     (int)ob->query("faith")
       );
    printf(HIC" ��ˮ�� %s%4d/ %4d      " HIC "     ��ֵ�� %s%d\n" NOR,
           status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM,             
(int)ob->query("office_number"));
        year = my["doaxing"] / 1000; 
        day = (my["daoxing"] - year * 1000) / 4;
        hour = (my["daoxing"] - year * 1000 - day * 4) * 3; 
  printf(HIC" Ǳ�ܣ�%8d           " HIY "   ���У� %s",
  (int)ob->query("potential") - (int)ob->query("learned_points"),    
        status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),
        HIM );
    if(year) printf("%s��", chinese_number(year));
    if(day) printf("%s��", chinese_number(day));
    if(hour) printf("%sʱ��", chinese_number(hour));
        if(!year && !day && !hour)  printf("�㻹û�е��С�");
sp_skill=ob->query_skill_mapped("spells");
if(sp_skill)
printf(HIW"  �������ԣ�%s"NOR,"/adm/daemons/spelld"->query_shuxing_chinese(
                     SKILL_D(sp_skill)->query_shuxing()));
 printf("\n");
return 1;
}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

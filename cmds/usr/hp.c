//Last modify by vikee.
//2000.12.15

#include <ansi.h>
inherit F_CLEAN_UP;

string chinese_daoxing(int gain);
string status_color(int current, int max);

int main(object me, string arg)
{
        object ob;
        mapping my;
        int dao,x,i;
        string str;
        seteuid(getuid(me));
        
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } 
		else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");

        my = ob->query_entire_dbase();

        printf(NOR CYN"������������������������������"HIY"S"HIR"��"HIY"J"HIR"��"HIY"S"HIR"��"HIY"H"NOR CYN"������������������������������\n"NOR,);
        printf(NOR CYN"��"NOR WHT" ����״̬"NOR CYN" �� ����"NOR WHT"%-12s "NOR CYN" �Ա�"NOR WHT"%-10s "NOR CYN"I D��"NOR WHT"%-13s"NOR CYN"��\n"NOR,ob->name(),ob->query("gender"),"["+capitalize(ob->query("id"))+"]");
        printf(NOR CYN"�ǩ�������������������������������������������������������������������\n"NOR);
        printf(NOR CYN"��"NOR WHT"�� ��Ѫ ��%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"]);
        printf(NOR WHT"  �� ���� ��%s%7-d/%7-d(+%4d)"NOR CYN"��\n"NOR,status_color(my["force"], my["max_force"]), my["force"], my["max_force"],my["force_factor"]);
        printf(NOR CYN"��"NOR WHT"�� ���� ��%s%7-d/%8-d%s[%3d%%]"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]);
        printf(NOR WHT"  �� ���� ��%s%7-d/%7-d(+%4d)"NOR CYN"��\n"NOR,status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],my["mana_factor"]);
        if(my["food"]*100/ob->max_food_capacity()>100) str=HIC+"�ܱ�";
        else if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"����";
        else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"ȱʳ";        
		else if(my["food"]*100/ob->max_food_capacity()>30) str=CYN+"ȱʳ";
        else if(my["food"]*100/ob->max_food_capacity()>10) str=HIR+"ȱʳ";
        else str=RED+"����";
        printf(NOR CYN"��"NOR WHT"�� ʳ�� ��%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        if(my["combat_exp"]>=((my["level"]+1)*(my["level"]+1)*200))
 printf(NOR WHT"  �� ��ѧ ��%s%18-d����"NOR CYN"��\n"HIG,HIY,(int)ob->query("combat_exp"));
        else
        printf(NOR WHT"  �� ��ѧ ��%s%18-d    "NOR CYN"��\n"HIG,HIY,(int)ob->query("combat_exp"));
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"�ܱ�";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"����";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"ȱˮ";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"ȱˮ";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"ȱˮ";
        else str=RED+"����";
         printf(NOR CYN"��"NOR WHT"�� ��ˮ ��%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        printf(NOR WHT"  �� Ǳ�� ��%s%14-d "NOR CYN"       ��\n"NOR,HIG,(int)ob->query("potential") - (int)ob->query("learned_points"));
        printf(NOR CYN"��"NOR WHT"�� ��ְ ��%s%21-d "NOR,HIG,(int)ob->query("office_number"));
        printf(NOR WHT"  �� ɱ�� ��%s%20-d "NOR CYN" ��\n"HIG,HIR,(int)ob->query("bellicosity"));
	printf(NOR CYN"��"NOR WHT"�� ���� ��%s%18-d " NOR "     "WHT"�� �ȼ� ��%s%4d "NOR"            "CYN"     �� "NOR"\n" NOR,
	HIY,my["scorepoint"],HIW,my["level"]);
		dao=(int)ob->query("daoxing");       
        printf(NOR CYN"��"NOR WHT"�� ���� ��%s%52-s    "NOR CYN"��\n"NOR,HIM,chinese_daoxing(dao));    
		if (ob->query("degree"))
		{
		printf(NOR CYN"��"NOR WHT"�� �ٰ� ��%s%52-s                  "NOR CYN"��\n"NOR,HIW,ob->query("degree"));
                
        printf(NOR CYN"������������������������������"HIY"S"HIR"��"HIY"J"HIR"��"HIY"S"HIR"��"HIY"H"NOR CYN"������������������������������\n"NOR);
		}
		else
		{
		printf(NOR CYN"��"NOR WHT"�� �ٰ� ��%s%52-s    "NOR CYN"��\n"NOR,HIW,"δ����;");
        printf(NOR CYN"������������������������������"HIY"S"HIR"��"HIY"J"HIR"��"HIY"S"HIR"��"HIY"H"NOR CYN"������������������������������\n"NOR);

		}
        //printf(NOR WHT"  �� �ٰ� �� %s "NOR CYN"  \n"NOR,ob->query("degree"));

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
        if( percent >= 30 ) return CYN;
        if( percent >= 10 ) return HIR;
        return RED;
}


string chinese_daoxing(int gain) {
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"��";
             if(day) str=str+chinese_number(day)+"��";
             if(hour) str=str+chinese_number(hour)+"ʱ��";
             if(gain==0) str="δ���;";
             return str;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ��(��)��ָ������(������)�ľ�, ��, ����ֵ��
 
see also : score
HELP
    );
    return 1;
}
 

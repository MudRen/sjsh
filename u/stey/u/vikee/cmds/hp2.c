#include <ansi.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int main(object me, string arg)
{
        object ob;
        mapping my;
        int  x,i;
        string str;
        seteuid(getuid(me));
        
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");
        my = ob->query_entire_dbase();
        printf(NOR CYN"������������������������������"HIR"�ɡ��¡��顤Ե"NOR CYN"������������������������������\n"NOR,);
        printf(NOR CYN"��"NOR WHT" ���˼��"NOR CYN" �� ����"NOR WHT"%-10s "NOR CYN" �Ա�"NOR WHT"%-10s "NOR CYN"I D��"NOR WHT"%-13s"NOR CYN"��\n"NOR,ob->name(),ob->query("gender"),"["+capitalize(ob->query("id"))+"]");
        printf(NOR CYN"�ǩ�������������������������������������������������������������������\n"NOR);
        printf(NOR CYN"��"NOR WHT"�� ��Ѫ ��%s%7-d/%7-d%s(%4d%%)"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"]);
        printf(NOR WHT"  �� ���� ��%s%7-d/%7-d(+%4d)"NOR CYN"��\n"NOR,status_color(my["force"], my["max_force"]), my["force"], my["max_force"],my["force_factor"]);
        printf(NOR CYN"��"NOR WHT"�� ���� ��%s%7-d/%7-d%s(%4d%%)"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]);
        printf(NOR WHT"  �� ���� ��%s%7-d/%7-d(+%4d)"NOR CYN"��\n"NOR,status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],my["mana_factor"]);
        if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"�ܱ�";
    	else if(my["food"]*100/ob->max_food_capacity()>80) str=HIC+"����";
    	else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"ȱʳ";
    	else if(my["food"]*100/ob->max_food_capacity()>40) str=HIM+"ȱʳ";
    	else if(my["food"]*100/ob->max_food_capacity()>20) str=HIR+"ȱʳ";
    	else str=HIR+"����";
    	printf(NOR CYN"��"NOR WHT"�� ʳ�� ��%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        printf(NOR WHT"  �� ��ѧ ��   %s%11-d "NOR CYN"       ��\n"NOR,HIG,(int)ob->query("combat_exp"));
        if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"�ܱ�";
    	else if(my["water"]*100/ob->max_water_capacity()>80) str=HIC+"����";
    	else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"ȱˮ";
    	else if(my["water"]*100/ob->max_water_capacity()>40) str=HIM+"ȱˮ";
    	else if(my["water"]*100/ob->max_water_capacity()>20) str=HIR+"ȱˮ";
    	else str=HIR+"����";
    	printf(NOR CYN"��"NOR WHT"�� ��ˮ ��%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        if(ob->query("daoxing")==0)  
	printf(NOR WHT"  �� ���� ��   %s%11-d "NOR CYN"       ��\n"NOR,HIY,"������û�е��У�");
	else
	printf(NOR WHT"  �� ���� ��   %s%11-d "NOR CYN"       ��\n"NOR,HIY,chinese_number(ob->query("daoxing"));
        printf(NOR CYN"��"NOR WHT"�� Ǳ�� ��%s%21-d "NOR,HIG,(int)ob->query("potential") - (int)ob->query("learned_points"));
        printf(NOR WHT"  �� ɱ�� ��   %s "NOR CYN"  ��\n"NOR,HIR,ob->query("bellicosity"));
        printf(NOR CYN"��������������������������������������������������������������������������\n"NOR);
  
	
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
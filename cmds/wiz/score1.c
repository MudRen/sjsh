//Cracked by Roath
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string *gift_ranking = ({"����֮ѡ","�µ�", "����", "�е�", "����", "�ϵ�", "����֮ѡ"});
string bar_string = "��������������������";
string blank_string ="��������������������";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);
void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
        object ob;
        mapping my;
        string line, str, skill_type;
        object weapon;
        int attack_points, dodge_points, parry_points,year,years,qian1,qian2,qian3,quest1,obstacles;
        int i;
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
        line = sprintf("        \n");
        line += sprintf(YEL"�ԡԡԡԡԡԡԡԡԡ�"HIG"��"NOR""YEL"�ԡ�"HIG"��"NOR""YEL"�ԡ�"HIG"��"NOR""YEL"�ԡ�"HIG"��"NOR""YEL"�ԡԡԡԡԡԡԡԡԡ�\n"NOR);        
//        line += sprintf("                     "MAG"��"HIG" �� �� �� ��  "MAG"��"HIW"    \n");
//        line += sprintf("         \n"NOR);
        line += sprintf(HIG"�� "NOR""HIW"�����ڵ�"HIR"ͷ��"HIW"��"CYN"ְ��"HIW"Ϊ ��"NOR"" BOLD "%16s" NOR "\n"HIG"��"NOR"   %s"HIY"\n"NOR, RANK_D->query_rank(ob),ob->short(1) );
        line += sprintf(YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n"NOR);
     if( ob->query("fake_age")){
           line += sprintf(" ����һ%s%s���%s%s��%s����\n",
                   ob->query("unit"),
                   chinese_number(ob->query("age")), 
                   ob->query("gender"),
                   ob->query("race"),
                   CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
       }else{
           line += sprintf(" ����һ%s%s���%s%s��%s����\n",
                   ob->query("unit"),
                   chinese_number(ob->query("age")),
                   ob->query("gender"),
                   ob->query("race"),
                   CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
   }
           year = my["combat_exp"] / 1000;
           years = my["combat_exp"];
          if(years>3000)
          line += sprintf(HIR" ��ϲ��"NOR"�������ڻ��"HIY""MAG"%s"NOR"��ĵ��С�\n",chinese_number(years));
          else
          line += sprintf(HIY" ����Ŭ��"NOR"�������ڸոջ��"HIY""MAG"%s"NOR"��ĵ��С�\n",chinese_number(years));
          obstacles = ob->query("obstacle/number");
          if(obstacles)
          line += sprintf(HIR" ��ϲ��"NOR"��������"HIG"����ȡ��"NOR"�ѹ���"HIY"%s"NOR"����"NOR"��  ������Qujing�鿴��\n",chinese_number(obstacles));
          else
          line += sprintf(HIY" ����Ŭ��"NOR"��������"HIY""CYN"��δ��"HIG"������ȡ�澭"NOR"��������Help Qujings�鿴��\n");
         quest1 = ob->query("quest/number");
       if (quest1)
          line += sprintf(HIR" ��ϲ��"NOR"���������Ѿ������"HIY"%s"NOR"��"HIG"����"NOR"�ˡ�  ������Quests�鿴��\n",chinese_number(quest1));
        else
          line += sprintf(HIY" ����Ŭ��"NOR"��������"HIY""CYN"��δ��"HIG""NOR"��ɹ�"HIG"����"NOR"��  ������Help jiemi�鿴��\n");
        if( wizardp(me) || (int)ob->query("age") >= 14 ) {
               line += sprintf(
                        " ������[%s]  ��ʶ��[%s]  ���ԣ�[%s]  ���ԣ�[%s]\n"
                        " ������[%s]  ��ò��[%s]  ���ǣ�[%s]  ��Ե��[%s]\n",
                        display_attr(my["str"], ob->query_str()),
                        display_attr(my["cor"], ob->query_cor()),
                        display_attr(my["int"], ob->query_int()),
                        display_attr(my["spi"], ob->query_spi()),
                        display_attr(my["cps"], ob->query_cps()),
                        display_attr(my["per"], ob->query_per()),
                        display_attr(my["con"], ob->query_con()),
                        display_attr(my["kar"], ob->query_kar()));
        }
        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line = sprintf("%s ���ʦ����" BOLD "%s"NOR"��\t\t",line, my["family"]["master_name"] );
        }
        else { line += sprintf(CYN" �����ڻ�û�а�ʦ"NOR"��\t\t");}
        if (ob->query("married")) {
                if (ob->query("gender")=="Ů��") {
                        line += HIM" ����ɷ���" +HIY+ ob->query("couple/name")+"��\n"NOR;
                }
                else {
                        line += HIG" ���������" +HIM+ ob->query("couple/name")+"��\n"NOR;
        }
       }
        else {
           if (ob->query("gender")=="Ů��")
                line += HIR" ��Ŀǰ�����ֹ��С�\n"NOR;
           else line+=HIG" ��Ŀǰ���ǹ����һ����\n"NOR; }
            line += " ��Ѫ  " + tribar_graph(my["kee"], my["eff_kee"],my["max_kee"], HIR) + "\t";
            line += " ����  " + tribar_graph(my["sen"], my["eff_sen"],my["max_sen"], HIB) + "\n";
       if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";
        attack_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge",SKILL_USAGE_DEFENSE);
       line += sprintf(" ս�������� " HIW "%d (+%d)" NOR "\t  ս�������� " HIW "%d (+%d)\n" NOR,
                attack_points/100 + 1, ob->query_temp("apply/damage"),
            (dodge_points + (weapon? parry_points:
            (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
        line += " ʳ�" + tribar_graph(my["food"],ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\t";
        line += " ��ˮ��" + tribar_graph(my["water"],ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";
        line += sprintf(" ��Ŀǰ�ܹ�"HIR"ɱ"NOR"�� %7d ���� �������� %4d ����������ҡ�\n",
                my["MKS"] + my["PKS"], my["PKS"]);
        line += sprintf(" ��Ŀǰ��"HIR"��ɱ"NOR"�� %7d ��   �������� %4d ����������ҡ�\n",
                my["BMKS"] + my["BPKS"], my["BPKS"],);
          if(ob->query("balance")){ 
            line += sprintf(HIC" ��Ĵ����Ϊ "NOR"��" );
            qian1 = ob->query("balance")/10000;
            qian2 = (ob->query("balance")-ob->query("balance")/10000*10000)/100;
            qian3 = ob->query("balance")-(((ob->query("balance")-ob->query("balance")/10000*10000)/100*100)+(ob->query("balance")/10000*10000));
          if(ob->query("balance")/10000) 
             line += sprintf(HIM "%s"NOR""CYN"��"YEL"�ƽ�" NOR,chinese_number(qian1));
          if((ob->query("balance")-ob->query("balance")/10000*10000)/100)
             line += sprintf(HIM"%s"NOR""CYN"��"WHT"����" NOR, chinese_number(qian2));
          if(ob->query("balance")-(((ob->query("balance")-ob->query("balance")/10000*10000)/100*100)+(ob->query("balance")/10000*10000)))
             line += sprintf(HIM"%s"NOR""CYN"��"YEL"ͭǮ" NOR, chinese_number(qian3));}
          else
             line += sprintf(HIW" ������û����Ǯׯ�д�Ǯ ��"NOR );
        line += sprintf("\n ɱ  ���� " HIR "%-9d" NOR "            ",ob->query("bellicosity") );
        line += sprintf(" ��  ���� " HIM "%-9d\n" NOR,ob->query("shen") );
        line += sprintf(" Ǳ  �ܣ� " HIY "%-9d" NOR "            ",(int)ob->query("potential") -(int)ob->query("learned_points") );
        line += sprintf(" ��  �ۣ� " HIC "%-9d\n" NOR,ob->query("score") );
        line += sprintf(YEL"�ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ� "HIR"������ I "NOR""YEL"�ԡԡԡ�\n"NOR);
        write(line);
        return 1;
}
string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}
string status_color(int current, int max)
{
        int percent;
        if( max ) percent = current * 100 / max;
        else percent = 100;
       if( percent > 100 ) return HIC;
       if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*25/max)*2-1]
                + ((eff > val) ?
blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)
���ָ�������ʾ���ָ������(������)�Ļ������ϡ�
�����ϵ��趨����� 'help setup'��
see also : hp
HELP
    );
    return 1;
}


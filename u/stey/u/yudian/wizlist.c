// yudian 2000-11-13
#include <ansi.h>
inherit F_CLEAN_UP;
mapping hoodname=([
                      "(elder)": HIC "���������" NOR "  (elder)  ",
                     "(immortal)" : HIM "�������ʦ" NOR " (immortal) ",
                    "(apprentice)" : HIG "����ʦѧͽ" NOR "(apprentice)",
                    "(wizard)" : HIB "����    ʦ" NOR "  (wizard)  ",
                        "(arch)" : HIG "����    ��" NOR "   (arch)   ",
             "(admin)" : HIW "���� ң ��" NOR "  (admin)   ",
]);

int level(mixed, mixed);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int j = 1;
        list = sort_array(SECURITY_D->query_wizlist(), (: level :));
//      str = "�� " + MUD_NAME + "Ŀǰ����" + chinese_number(sizeof(list)) + "λ��ʦ��";
            str = HIM"��������Ե��"HIY"��"HIG"֪��վ"NOR"��ʦ��ȫ�Ҹ�";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood != wizhood(list[i])) {
                        hood = wizhood(list[i]);
                        if (j%8) str += "\n";
                        str += sprintf("%-13s" NOR ": ", hoodname[hood]);
                        j = 1;
                }
        if (!(j % 8)) {
            str += sprintf("%14s", "");
                        j++;
                }
                str += sprintf("%-9s%s", capitalize(list[i]),
                        (j%8==7) ? "\n" : "");
        }
        me->start_more(str);
        return 1;
}

int level(mixed ob1, mixed ob2)
{
        if (wiz_level(ob1) != wiz_level(ob2))
                return wiz_level(ob1) - wiz_level(ob2);
        return ob1 < ob2?-1:1;
}

int help(object me)
{
write(@HELP
  ָ���ʽ : wizlist
��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}

// wizlist.c

#include <ansi.h>

inherit F_CLEAN_UP;

mapping lists = ([
        "(admin)"      : HIW"��ϵͳ������"NOR,
        "(arch)"       : HIR"�����򿪷�����"NOR,
        "(wizard)"     : HIY"��վ��ά������"NOR,
        "(apprentice)" : HIG"����ϰ������"NOR,
        "(immortal)"   : HIM"��������ʦ����"NOR,
        "(elder)"      : HIB"��������ҡ���  eld  ����"NOR,
]);
int level(mixed, mixed);

int main(object me, string arg)
{
        string *list, hood = "", str;
        int j = 0;
        list = sort_array(SECURITY_D->query_wizlist(), (: level :) );
str = HIR"������"HIG"Ȫ��ʦԺ��վ "HIR"�� "+HIY"��ʦȫ�Ҹ� "HIR"��"NOR+CYN" ��\n";
        str += "��������������������������������������������������������\n";
        for(int i=0; i<sizeof(list); i++, j++) {
                if (hood != wizhood(list[i]) ) {
                        hood = wizhood(list[i]);
                        if (j%7) str += "\n";
                        str += lists[hood] ;
                        j = 0;
                }
 
 if (list[i]!="kissess" && list[i]!="chm"&& list[i]!="peaceful") str +=sprintf("%s%s",capitalize(list[i]),
                        ( j%7==6 ) ? "\n" : ( i<sizeof(list)-1 && hood ==wizhood(list[i+1]) ) ? ", " : ""  );
        }
str += CYN"\n��������������������������������������������������������\n"NOR;
  str += "Ŀǰ����" +HIW+ chinese_number(sizeof(list)-2) +NOR+ "λ��ʦ��\n\n";
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
        write("\nָ���ʽ : wizlist\n"
        "��; : �г�Ŀǰ���е���ʦ������\n"
        );
        return 1;
}

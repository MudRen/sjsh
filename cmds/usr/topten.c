// /cmds/usr/topten.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string str,*astr;
        int i;
        seteuid(geteuid(me));
        if (!arg||arg=="")
                return notify_fail("ָ���ʽ : topten <����>\n");
        str=TOPTEN_D->topten_query(arg);
        write(str+"\n");
        return 1;
}

int help(object me)
{   write(HIW"ָ���ʽ : topten <����>\n"NOR+TOPTEN_D->query_type());
    return 1;
}

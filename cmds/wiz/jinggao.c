#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
          void create() {seteuid(getuid());}
int main(object me, string arg)
{//object ob;
//string target, msg, mud,from;
string target, msg;
object obj;
if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

obj = find_player(target);
write(HIR "\n �㾯��" + obj->name(1) + "��\n \n" + "      �������"+msg +"��ΪΥ������Ϸ��������˲���Ӱ�죬����ٷ���\n"+"      ��ȥ���εȺ�ͷ���\n \n" NOR);
tell_object(obj, sprintf( HIR "\n %s�����㣺\n \n"+"      �������"+HIW +"%s"+HIR +"��ΪΥ������Ϸ��������˲���Ӱ�죬����ٷ���\n"+"      ��ȥ���εȺ�ͷ���\n \n" NOR,me->name(1), msg));
message("shout", HIR "�����澫�顿������ʦ"+me->query("name")+"������" + obj->name(1) + "����\n" NOR,users());
return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ��jinggao <ĳ��> <ѶϢ>
����������ָ����κ��ˡ�
HELP
);
return 1;
}


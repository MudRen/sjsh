// promote.c
//modified by kissess for log recording
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object ob;
    string old_status, new_status;
    int my_level, ob_level, level;

    if( me!=this_player(1) ) return 0;

    if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
        return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�>\n");

    if( wiz_level(new_status) < 0 ) return notify_fail("û�����ֵȼ���\n");

    if( !objectp(ob = present(arg, environment(me))) 
    ||   !userp(ob) )
        return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

    if( wiz_level(me) < wiz_level(new_status) )
        return notify_fail("��û������Ȩ����\n");

    old_status = wizhood(ob);

    seteuid(getuid());
    if( !(SECURITY_D->set_status(ob, new_status)) )
        return notify_fail("�޸�ʧ�ܡ�\n");

    message_vision(HIC""HIG"$N "HIC"�� "HIY"$n "HIC"��Ȩ�޴� "HIR + old_status + HIC" ��Ϊ "HIR + new_status + "\n"NOR, me, ob);
    message("channel:sys",HIR"��Ȩ�޾��顿"HIG+me->name(1)+HIR" �ı��� "HIW+ob->name(1)+HIR" ����ʦȨ�޵ȼ� \n"NOR,users());
    seteuid(getuid());
    ob->setup();
log_file("static/promote",
                        sprintf("%s(%s) promote %s(%s) �µȼ�%s on %s\n",me->name(1), geteuid(me), ob->name(1), geteuid(ob), wizhood(ob), ctime(time()) ) );

    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : promote <ĳ��> (Ȩ�޵ȼ�)

��������Ȩ�޵ȼ�, (player) (immortal) (apprentice) (wizard)
(arch) (admin)
һ�� admin ������Ȩ�����κεȼ�, �� arch ֻ�������� arch��
HELP
  );
  return 1;
}


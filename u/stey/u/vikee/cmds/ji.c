// Modified by vikee for xlqy-zq station
// 2000.12.4
// ji.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string targetname, fabaoname;
    object obj, *inv, target, obj2,old_env, fabao;
    int i, amount;
    mixed no_get;

    if( !wizardp(me) && environment(me)->query("no_magic") )
	return notify_fail("�����ֹ��������\n");
    if( !arg ) return notify_fail("��Ҫ������������\n");

    // Check if correct format is followed

	//the followed is added by vikee
	if(userp(target) && target->query("age")<16)
		return notify_fail("��վ��ʱ�������֡�\n");

	if(me->query("combat_exp")<50000 && userp(target))
		return notify_fail("�Լ�����û���þ���ɱ�ˣ�\n");

	if(me->query("daoxing")<50000 && userp(target))
		return notify_fail("�Լ�����û���þ���ɱ�ˣ�\n");	

    if( sscanf(arg, "%s on %s", fabaoname, targetname)>2 )
	return notify_fail("ָ���ʽ : ji <��������> [on <Ŀ��>]\n");

    // Check if both a fabao and a target is specified.
    // if so, then check 1. whether the player own's the fabao,
    // and 2. check whether the target is in the same environment.
    if( sscanf(arg, "%s on %s", fabaoname, targetname)==2 )
    {
	fabao=present(fabaoname, me);
	if(!fabao) return notify_fail("��û�� "+fabaoname+" ����������\n");
	target = present(targetname, environment(me));
	if (me->is_busy() && !fabao->query("no_busy"))
	    return notify_fail("����һ��������û����ɣ���Ͼ�����������\n");
	if(!target) return notify_fail("����û�� " + targetname + "��\n");
	if(target==me)
	    return notify_fail("���Լ���������\n");
	return fabao->ji(targetname);
	
}
    fabao=present(arg, me);
    if(!fabao) return notify_fail("��û��" + arg +"����������\n");
    if (me->is_busy() && !fabao->query("no_busy"))
	return notify_fail("����һ��������û����ɣ���Ͼ�����������\n");

    return fabao->ji();
}
int help(object me)
{
    write(@HELP
ָ���ʽ : ji <��������> [on <Ŀ��>]

���ָ����������һ�����

HELP
			);
		     return 1;
		 }

#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit SHIELD;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_UNIQUE;

int msgon = 1;
int ji(string arg);
int find(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
void remove_ding(object me, object victim);

void create()
{
	seteuid(getuid());

	set("long",@LONG
������������������������쾵��find����
LONG
);
	set("unit","��");
            set("value",1);             
       set("no_drop","��ô�õı�����˶��ϧѽ��\n");
       set("no_give","��ô�õı�������Լ��ðɣ�\n");
       set("no_sell", 1);
	set("is_monitored", 1);
	set("no_busy", 0);
	set("armor_prop/armor", 500);
	set_weight(1);
	setup();
}

void init()
{
	object me = this_player();

	seteuid(geteuid());
	if (!present(this_object(), me)) {
		if (environment(environment(me))) {
			write("�㱻һ���������������ˣ�\n");
			me->move(environment(environment(me)), 1);
		}
		return;
	}
        set_name (HIW"���쾵"NOR, ({ "haotian jing", "haotian", "jing" }));

	if (me && present(this_object(), me)) {
		add_action("find", "find");
	}
}


int find(string arg)
{
	object where, target, me = this_player();
	object *ob;
	string msg;
	int i;

	if (!geteuid()) seteuid(getuid());
	if (arg) {
		if (target = LOGIN_D->find_body(arg)) {
			where = environment(target);
			if (!where) return notify_fail("��������Ʈ��䡣\n");
			"/cmds/std/look"->look_room(me, where);
			return 1;
		}
		else {
		ob = users();
		msg = "";
		for (i = 0; i < sizeof(ob); i++) {
			where = environment(ob[i]);
			if (!where)
				msg = sprintf("%s%14s(%-10s) %s\n",
					msg, ob[i]->name(1), ob[i]->query("id"),
					"??????????");
             return 1;
				
		}
	}
	write (msg);
	return 1;
}
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name();
    if (this_object()->query("in_use"))
        return notify_fail("���ڵ�"+objname+"ֻ��һ����ͨ�ķ��ߡ�\n");
    if (!target)
	return notify_fail("�����ö�˭��"+objname+"��\n");
    if (!objectp(victim=present(target, environment(me))))
	return notify_fail("����û�� "+target+"��\n");
    if(!living(victim))
	return notify_fail("���Ŀ�겻�ǻ��\n");
    if(!me->is_fighting(victim))
	return notify_fail("ֻ��ս���в��ܼ�"+objname+"��\n");  
    if(victim->query("no_move"))
	return notify_fail("�Է��Ѿ���Ͼ�Թ��ˣ��б�Ҫ��"+objname+"ô��\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("��ķ��������ˣ�\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("��ľ����޷����У�\n");
    msg="$N����"+objname+"�����������дʣ�\n";
    msg+=objname+"���һ���׹�����$n��\n";
    condition=determine_success(me, victim);
    switch(condition)
    {
      case 1:
        msg+=HIW"�����$n���׹���ס���������ˡ�\n" NOR;
        msg+=HIW"$n��"+objname+HIW"�ķ�����ס�ˣ�\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random((int)me->query("mana_factor")*4/5)+1;
	if (dingtime > 60) dingtime=60;
	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"����ס��"+chinese_number(dingtime)+"�롣\n" NOR);
	this_object()->set("in_use", 1);
	call_out("remove_ding", dingtime, me, victim);
	break;
      case 0:
        msg+=HIY"$n������ָ�����һ�������Һ��쾵�������쾵�׹�һ�����ջ�$N���С�\n"NOR;
	break;
      case -1:
        msg+=HIY"$n������ָ�����һ�����գ���ֻ�����쾵����$N��ס�ˣ�\n"NOR;
	dingtime=random(victim->query("mana_factor")*4/5)+1;
	if (dingtime > 60) dingtime=60;
	me->set_temp("no_move");
	this_object()->set("in_use");
	call_out("remove_ding", dingtime, victim, me);
	break;
      case -2:
        msg+=HIY"$n������ָ�����һ�������Һ��쾵����ֻ�����쾵�׹�һ�����ջ�$N���С�\n"NOR;
	this_object()->move(victim);
	break;
    }
    message_vision(msg,me,victim);
    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    return 1;
}

int determine_success(object me, object victim)
{
    int myspells, mydx, victimspells, victimdx;
    int ap, dp, attackfactor, condition;
    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;
    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;
    attackfactor=random(ap+dp);
    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();
    cost=me->query(variable)/5;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

void remove_ding(object me, object victim)
{
    string msg=query("name")+HIW"�׹�һ����$n�����˳����ˡ�\n"NOR;
    this_object()->delete("in_use");
  if (!victim)
   {
    message_vision(msg, me);
    return;
   }

    if (living(victim))
        msg += HIW"$n�����˳�����\n"NOR;
    message_vision(msg, me, victim);
    victim->delete_temp("no_move");
    return;
}

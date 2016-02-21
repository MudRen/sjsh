#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"��ħ��"NOR,({ "fumo dao", "dao","blade" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 5);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);        
                set("material", "gold");
                set("wield_force", 100);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg",HIY"ֻ������ৡ���һ������߷���һ��ϼ�⣬����һ����$N����
                ����һ�ѽ𵶣�\n"NOR);
                set("long", HIY"\n�����ô�������һ���䵶�����������ħ���ԡ���ϸ��ȥ�������ײ���һ���� \n
                �ƺ����Խ�(jie)ʲô������\n"NOR);               
                set("unwield_msg", HIY "$N��һ�ӣ���ħ�𵶻�Ϊһ����⣬[��]��һ�������ˡ�\n"NOR);               
        }
        init_blade(70);
        setup();
}

void init()
{
    add_action("do_jie", "jie");
}

int do_jie()
{
     object me,ob, obj, dao;
     me = this_player();
     ob = this_object();
     obj = present("xiangyao chan", me);
     if(!objectp(obj))
           return notify_fail("������ֻ�з�ħ�𵶣����ҵ���������˵�ɡ�\n");
     if((int)me->query("force") < 500)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷�������ϲ���\n");
     if((int)me->query("mana") < 500)
		return notify_fail("��о�һ���ķ����ң�ԭ����ħ���������޷�������ϲ���\n");
     if((int)me->query_str() < 28)
		return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������޷�������ϲ���\n");
     me->add("force", -300);
     message_vision(HIY"\nֻ����ħ�𵶺ͽ�����ͬʱ����ҫ�۵�ϼ�⣬�𽥽ӽ�������Ϊһ�壡��\n"NOR, me);
     destruct(obj);   
     dao = new("/u/xintai/weapon/suoluodao")->move(me, 1);     
     destruct(ob);
     return 1;
}

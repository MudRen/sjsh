#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_aim","aim");
        add_action("do_shoot","shoot");
}

void create()
{
       set_name("AK47-���ǹ", ({ "chongfeng qiang", "qiang", "gun" }) );
       set_weight(2000);
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("unit", "��");
               set("bullet", 200);
               set("value", 50000);
               set("material", "steel");
               set("long", "����һ��ɱ���������AK47���ǹ���������Կֲ����ų��õ�����������\n");
               set("wield_msg", "$N��һ��$n�������С�\n");
               set("unequip_msg", "$N�����е�$n�������ϡ�\n");
       }
       init_blade(100);
       setup();
}

int do_aim(string arg)
{
       object me, obj;

       if(arg=="swl") return 1;
       
       me = this_player();

       if( !arg )
               return notify_fail("����ɱ˭��\n");

       if( this_object()->query("bullet") <=0)
               return notify_fail("�ӵ��Ѿ�����ˡ�\n");

       if(!objectp(obj = present(arg, environment(me))))
               return notify_fail("����û������ˡ�\n");

       if( !obj->is_character())
               return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

       if(obj == me)
               return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

       message_vision(HIR "\n$N����AK47-���ǹ������$n�ķ�������¶��һ˿�����Ц�ݡ�\n\n" NOR, 
                       me, obj);

       set_temp("target", arg);

       return 1;
}

int do_shoot()
{
       object me, obj;
       string arg;

       me = this_player();

       if( !(arg = this_object()->query_temp("target")) ) 
               return notify_fail("�㻹û����׼������Ŀ�꣡\n");

       if( !objectp(obj = present(arg, environment(me)) ))
               return notify_fail("��Ҫ����Ķ����Ѿ��뿪�ˡ�\n");

       message_vision(HIR "\n$N��׼$nһ���ɨ������\n�ӵ���һƬ��â������$n��$nƬ�̱�������룡\n\n" NOR,
                       me, obj);

       this_object()->add("bullet", -20);
       obj->set_temp("last_damage_from", "��" + me->name() + "ıɱ");
       obj->delete("env/immortal");
       obj->die();
       delete_temp("target");

       return 1;
}

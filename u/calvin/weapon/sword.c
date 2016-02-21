// Īаʥ�� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"Īаʥ��"NOR, ({"moxie sword", "moxie","sword"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
               set("no_sell", "��?����,���ֺ����Ķ�������������!\n");
//                 set("no_get", "ʲô,�����? ���Σ�\n");
                set("material", "steel");
                set("long", "�ഫΪĪаר�õı���������͸��,�����ޱȡ�\n");
                set("wield_msg", "һ���Ϲ�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(60);
        setup();
}

void init()
{
  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
        add_action("do_xiulian","xiulian");
}
void destruct_me(object where, object me)
{
        object pearl;
        if( pearl=new("/d/obj/weapon/sword/changjian"))
                pearl->move(where);
        message_vision("$N���е�$nͻȻһ���׹⣬һ����������ʧȥ����ɫ��\n",where,me);
        destruct(me);
}

int do_xiulian()
{
        object me,a,b,real;
        me=this_player();
        a=this_object();

        if( (int)me->query("force") < 2000)
                return notify_fail("�����������,Īа�����ľ����ǲ��򲻵���\n");
        if( (int)me->query("mana") < 2000)
                return notify_fail("��ķ�������,Īа�����ľ���������͸��\n");

         if ( !(c=present("ganjiang sword",me)))
                return notify_fail("��Ŭ�����������ľ�,�������ǲ����������\n");

        if( real=new("/d/calvin/weapon/rysj")){
                destruct(b);
        real->move(me);

        message_vision("$N����ͨ��Ŭ�����������ľ���ʹ�øɽ�Īа˫���϶�Ϊһ��\n",me);
        destruct(a);
        }
        return 1;
}

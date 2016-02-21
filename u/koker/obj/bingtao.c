// bingtao.c ����
//by koker@sjsh 2002
#include <ansi.h>
#define LAST_PAR "bt2"
#define THIS_PAR "bt1"
inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ�ɱ��Ҵ�ָ�们�䣬ˤ�÷��飡\n");
    set("no_give","���粻ϣ������������\n");
    set("no_drop","���ҵ��ڵ��ϻ���ģ�\n");
    set("no_sell","С���Ǹ��ջ�����˷��Ķ�����������պã���������鷳�ˣ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name("����", ({"bing tao","bingtao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "���ǻ���������ǧ�꺮����̵����ӣ�����ȥ�ɰ����ˡ�\n");
    set("value", 50000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "��Թ��˰�������ô����������\n\n");
       tell_object(me,CYN "�㱻����ݺݵ�����һ�š�\n" NOR);
       return 1;
       }
  me->set("water", (int)me->max_water_capacity());
  me->add_maximum_force(20);
  me->add_maximum_mana(20);
  me->add("combat_exp",100000);
  me->add("daoxing",100000);
  me->add("potential",100000);
  message_vision(HIG "$N����һ�����ң�ȫ������ͻȻ����˪���֣����ݲ�ͣ�Ĵ���� \n" NOR, me);
  me->delete(LAST_PAR + "_pick");
  me->set(THIS_PAR + "_pick",1);
  destruct(this_object());
  return 1;
}

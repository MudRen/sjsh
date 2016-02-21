#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIB "ת����" NOR, ({"bishui dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "������һ��ת������\n");
	set("value", 500000);  
        set("no_sell", 1);
  }
  
  setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
    
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

	
if ((int)me->query("potential") < 5000)  
 return notify_fail("������װ̬����û����ת����\n");

	else {
 
  	message_vision(HIB"$N����һ��ת��������ɫ��䣬�������ڷ�����Ī���ı仯��\n"NOR, me);  
  
	me->add("bellicosity", -random( (int)me->query_kar() * 10));
	if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
	me->add("potential", -1000);
        me->add("combat_exp",1000);

}
  destruct(this_object());
  return 1;
}

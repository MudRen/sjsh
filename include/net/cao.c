// ���ؾ��� ����ʹ��
/* <SecCrypt CPL V3R05> */
 
// ˮ��
// qkl  14/4/01

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
        }
        add_action("do_eat", "eat");
}

void create()
{
  set_name("��̦", ({"qing tai","cao","qing","tai"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long", "һЩ��ɫС�ݡ�\n");
     set("drug_type", "��Ʒ");
        }
  set("is_monitored",1); //��ؾ���
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg)) 
    {
      return notify_fail("��Ҫ��ʲô��\n");
    }
       else
         {
           me->set("food", (int)me->max_food_capacity());
           me->add("potential",9);
           me->add("combat_exp",9);
           me->add("daoxing",9);
           message_vision(HIC "$N����һЩ��̦��ɫ����,���ǸϿ����˳���! \n" NOR, me);
           destruct(this_object());  //���������Ʒ
           return 1;
         }
 }



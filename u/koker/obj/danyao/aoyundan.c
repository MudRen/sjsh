// ��������Ե*�����񻰡�

// aoyundan.c ���˴���
// koker  13/07/2001

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_sell", "�ٺ٣����ΰ�! \n");
                set("no_give", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô���Ļ��ᣬ����������! \n");
        }
        add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "���˴���" NOR, ({"aoyun wan","wan","aoyun","dan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long", "�����������ɹ���ش��衣������У����±������°��ˡ������֡�\n");
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
           me->add("potential",150000);
           message_vision(HIC "$N����һ�Ű��˴��裬ֻ������ȽȽ����һ���������ļ���������֮���㻹û���˶�������󺰵�������Ұ��㣡�ҵ�����Զ�����㣡������꣬�������꣡ \n" NOR, me);
           destruct(this_object());  //���������Ʒ
           return 1;
         }
 }



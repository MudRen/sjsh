//By Repoo
// guaishi.c

#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(RED"��ֵ�ʯͷ"NOR, ({"guai shi", "shi", "stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ���ʯͷ,����ȥ��һ�����ȡ�");
                set("weight", 4000);
                 set("no_get","�ⶫ���ò�������\n");
        }
        setup();
}
void init()
{
  add_action("do_hammer", "hammer");
}

int do_hammer(string arg)
{       
  object me;
  me=this_player();
  if ( !present("hammer", me) || (arg != "stone"))
    return notify_fail("�����ȭͷ��ʯͷ����ȥ���ҵ����ֶ�����Ѫ��\n");
  else
    message_vision("$N����󴸣���ʯͷ����ȥ��\n", me);
  if((int)me->query_temp("mark/��ʯ") < 1)
    {
    me->set_temp("mark/��ʯ", 1);
  }
  me->add_temp("mark/��ʯ", 1);
  me->receive_damage("kee", 40);
   if((int)me->query_temp("mark/��ʯ") > 3)
    {
    message_vision("$N��ʯͷ�ҳ������顣\n", me);
 message("system", HIW"һ���׹���������ʧ�ڶ�����\n"NOR+HIG"\nһ���̹���������ʧ��������\n"+HIR"\nһ�������������ʧ���Ϸ���\n\n"NOR,users());
 message("channel:rumor",YEL+"��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+me->query("name")+"����ֵ�ʯͷ�ҳ������飬�ֱ��򶫡����������������ȥ��\n"+NOR,users() );
    me->set_temp("mark/��ʯ", 1);
     destruct(this_object());
    return 1;
}
  return 1;
}

#include <ansi.h>

inherit ITEM;

int do_kiss(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ��"+this_object()->query("name")+"��ָ�们�䣡\n");
    set("no_give","��ô���Ķ��ӣ����������ˣ�\n");
    set("no_drop","��ô�İ��Ķ��������˶��ϧѽ��\n");
    set("no_sell","����֮������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_kiss", "kiss");
}

void create()
{
  set_name(HIR "��ҹ" NOR, ({"ziye"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_kiss(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ����ʲô��\n");
    me->set("sen",(int)me->query("eff_sen"));
  me->set("kee",(int)me->query("eff_kee"));
  return 1;
}

